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

void print_tree_header(FILE *compressed_archive, node* tree)
{
    if(tree != NULL)
    {
        
        if(tree->data == '*' && is_leaf(tree) || tree->data == '\\' && is_leaf(tree))
        {

            fprintf(compressed_archive,"\\%c", tree->data);
        }
        else
        {
            fprintf(compressed_archive,"%c", tree->data);
        }
        
        print_tree_header(compressed_archive,tree->left);
        print_tree_header(compressed_archive,tree->right);
    }
}

void print_trash_treesize(FILE *compressed_archive, unsigned char *bits)
{
    int i;
    unsigned char byte =0;
    int bit_index = 7;
    for(i=0;i<16;i++)
    {
        if(bits[i] != '0')
        {
            byte = set_bit(byte,bit_index);
        }
        bit_index--;

        if(bit_index<0)
        {
            bit_index=7;
            fprintf(compressed_archive,"%c", byte);
            byte=0;   
        }
    }
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
    unsigned char *comp_archive= malloc(sizeof(unsigned char) *100);
    strcat(uncomp_archive_name, ".huff");
    strcpy(comp_archive, uncomp_archive_name);
    FILE *compressed_archive=fopen(comp_archive,"wb");
    fprintf(compressed_archive, "00"); // Reserves the first 16 bits.*/
    heap*rip = create_heap();
    check_frequency(archive, rip);
   //print_heap(rip->size, rip);
    build_huff_tree(rip);
    hash *ht=create_hash_table();
    printf("Arvore criada!\n");
    unsigned char binary[8];
    navigate(rip->items[1],binary,0,ht);

    printf("Comprimindo, tenha paciencia pfv.\n");

    //tree header
    int tree_sizeeesss=tree_size(rip->items[1]);
    print_tree_header(compressed_archive, rip->items[1]);
    unsigned char tree_header_size[13];
    int_to_bin(tree_header_size, tree_sizeeesss,13);
    //trash header
    unsigned int trash=write_compressed_file(archive,compressed_archive,ht);
    unsigned char trash_size[4];
    int_to_bin(trash_size,trash,3);
    trash_size[3]='\0';
    
    //constructing header
    char header[17]="";
    strcpy(header,trash_size);
    header[3]='\0';
    strcat(header,tree_header_size);
    header[16]='\0';
    rewind(compressed_archive);

    print_trash_treesize(compressed_archive,header);

    fclose(archive);
    fclose(compressed_archive);

    printf("\nArquivo comprimido com sucesso!\n");
    

    //print_preorder(rip->items[1]);
    printf("\n");
    //print_hash(ht);
    //printf("aqui\n");
    return;
}