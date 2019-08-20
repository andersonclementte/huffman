#include "./header.h"

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

int is_bit_set(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask & c;
}

unsigned char *get_new_bin(hash *ht, unsigned char c)
{
    return ht->table[c]->bin;
}

int write_compressed_file(FILE *archive, FILE *compressed_archive, hash *ht)
{
    unsigned char byte=0, byteread;
    unsigned char *new_bin=NULL;
    int i, bit_index=7;
    rewind(archive);

    while(fscanf(archive,"%c", &byteread) > 0)
    {
        new_bin=get_new_bin(ht,byteread);
        
        for(i=0;i<strlen(new_bin);i++)
        {
            if(bit_index==-1)
            {
                fprintf(compressed_archive,"%c",byte);
                byte=0;
                bit_index=7;
            }
            if(new_bin[i] == '1')
            {
                byte = set_bit(byte,bit_index);
            }
            bit_index--;    
        }
    }
    if(bit_index<=7)
    {
        fprintf(compressed_archive,"%c",byte);
    }
    bit_index++;
    return bit_index;
}

int int_to_bin_converter(unsigned int c, int i)
{
    unsigned char mask = c >> i;
    return mask & 1;
}

void int_to_bin(unsigned char *bin,int num, int bits)
{
    int i;
    for(i=0;i<bits;i++)
    {
        bin[bits-i-1]=int_to_bin_converter(num,i)+'0';
    }
    bin[strlen(bin)]='\0';
}

void compress(unsigned char *uncomp_archive_name)
{
    FILE *archive=fopen(uncomp_archive_name,"rb");
    fseek(archive, 0L, SEEK_END);
	int fileSize = ftell(archive);
	rewind(archive);
    unsigned char* file_bin= malloc(sizeof(char)* fileSize);
    fread(file_bin,1,fileSize,archive);
    printf("%s\n", file_bin);
    unsigned char comp_archive[100];
    strcat(uncomp_archive_name, ".huff");
    FILE *compressed_archive=fopen(comp_archive,"wb");
    fprintf(comp_archive, "00"); // Reserves the first 16 bits.
    heap*rip = create_heap();
    check_frequency(file_bin, rip);
    print_heap(rip->size, rip);
    build_huff_tree(rip);
    hash *ht=create_hash_table();
    unsigned char binary[8];
    navigate(rip->items[1],binary,0,ht);

    unsigned int trash=write_compressed_file(archive,compressed_archive,ht);
    unsigned char trash_size[4];
    int_to_bin(trash_size,trash,3);

    char header[17];
    //print_preorder(rip->items[1]);
    //printf("\n");
    //print_hash(ht);

    
}