#include "./header.h"

void compress(unsigned char uncomp_archive_name)
{
    FILE *archive=fopen(uncomp_archive_name,"rb");
    fseek(archive, 0L, SEEK_END);
	int fileSize = ftell(archive);
	rewind(archive);
    unsigned char file_bin[fileSize];
    for(int i=0; i<fileSize; i++)
    {
     scanf("%c", &file_bin[i]);   
    }
    heap*rip = create_heap();
    check_frequency(file_bin, rip);
    print_heap(rip->size, rip);
    build_huff_tree(rip);
    hash *ht=create_hash_table();
    unsigned char binary[8];
    navigate(rip->items[1],binary,0,ht);
    print_preorder(rip->items[1]);
    printf("\n");
    print_hash(ht);   



    //unsigned char comp_archive[100];
    //strcat(uncomp_archive_name, ".huff");
    //FILE *compressed_archive=fopen(comp_archive,"wb");
}