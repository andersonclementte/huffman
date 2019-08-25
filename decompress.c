#include "./header.h"

node *build_tree (node *huff_tree, FILE *compressed_file)
{
    unsigned char character;
     fscanf(compressed_file, "%c", &character);
     if (character == '*')  
     {
        huff_tree =  create_node(character, 0, NULL, NULL);
        huff_tree->left=build_tree(huff_tree->left, compressed_file);
        huff_tree->right=build_tree(huff_tree->right, compressed_file);

     }
     else
     {
         if(character == '\\')
         {
             fscanf(compressed_file, "%c", &character);
         }
         huff_tree = create_node(character,0, NULL, NULL);
     }

     return huff_tree;
     
}

void decompress(unsigned char *compressed_archive_name)
{
    unsigned char character;
    unsigned short trash_size, tree_size;
    FILE *compressed_archive = fopen(compressed_archive_name, "rb");
    if (compressed_archive == NULL){
		printf("Arquivo não encontrado\n");
		return;
	}
    fscanf(compressed_archive, "%c", &character);

    trash_size = character>>5;
    tree_size = character<<11;
    tree_size >>= 3;

    fscanf(compressed_archive, "%c", &character);
    tree_size |= character;
    node* huff_tree = build_tree(huff_tree, compressed_archive);
    node* huff_tree_aux = huff_tree;

    unsigned char new_file[100];
    int size = strlen(compressed_archive_name);
    int i;
    for ( i = 0; i < size-5; i++)
    {
        new_file[i]=compressed_archive_name[i];
    }
    new_file[i] = '\0';

    long long int file_size;

    while (fscanf(compressed_archive, "%c", &character)!=EOF)
    {
        file_size++;
    }
    fseeko(compressed_archive, 2+tree_size, SEEK_SET);
    FILE *decompressed_file = fopen(new_file, "wb");
    

    while (file_size  > 0)
    {
        fscanf(compressed_archive,"%c", &character);
        if(file_size != 1)
        {
            for(i=7; i>=0; i--)
            {
                if(is_bit_set(character,i))
                {
                    huff_tree_aux=huff_tree_aux->right;
                }
                else
                {
                    huff_tree_aux=huff_tree_aux->left;
                }
                if(is_leaf(huff_tree_aux))
                {
                    fprintf(decompressed_file,"%c",huff_tree_aux->data);
                    huff_tree_aux=huff_tree;
                }
            }
        }
        else
        {
            for(i=7;i>=trash_size;i--)
            {
                if(is_bit_set(character,i))
                {
                    huff_tree_aux=huff_tree_aux->right;
                }
                else
                {
                    huff_tree_aux=huff_tree_aux->left;
                }
                if(is_leaf(huff_tree_aux))
                {
                    fprintf(decompressed_file,"%c",huff_tree_aux->data);
                    huff_tree_aux=huff_tree;
                }
            }
        }
        file_size--;
        
    }

    fclose(compressed_archive);
    fclose(decompressed_file);

    printf("\nArquivo descomprimido com sucesso!\n");
    
    

}
