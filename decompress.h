#ifndef decompress_h
#define decompress_h
#include "./header.h"

/*
Receives a node and the compressed file, it will read the pre_ordered tree string and create
a new tree that is returned. 
*/
node *build_tree (node *huff_tree, FILE *compressed_file);


/*
This function receives the compressed file, it will calculate trash and tree size 
then will create a huffman tree that will give the compressed representation of the binary
the function will read all the remaining chars in the file and do the conversion to the original
binary representation using the created huffman tree.
*/
void decompress(unsigned char *compressed_archive_name);

#endif