#ifndef compress_h
#define compress_h
#include "./header.h"

void compress(unsigned char * uncomp_archive_name);

/*
This function receives a char that represents the byte and a index that represents the bit that will be
setted (0->1).

it returns the new byte with the index set.
*/
unsigned char set_bit(unsigned char c, int i);

/*
This function receives a char that represents the byte and a index that represents
the bit that we verify if is set or not.

it returns 0 if its not set and 1 if it is set
*/
int is_bit_set(unsigned char c, int i);

/*
This function access the given hash and gets the new byte representation, then returns it.
*/
unsigned char *get_new_bin(hash *ht, unsigned char c);

/*
This function receives a File and a huffman tree, then it prints the tree in preorder in the file.
*/
void print_tree_on_file(FILE *compressed_archive, node* tree);

/*
This function receives a File and a char representing 2 bytes, it prints the trash and tree size
in the header of the file.
*/
void print_trash_treesize(FILE *compressed_archive, unsigned char *bits);

/*
This function receives 2 archives and a hash with the new binarys map.
this function prints the new binary map in the compressed file until the end of the older file.

it return the trash size.
*/
int write_compressed_file(FILE *archive, FILE *compressed_archive, hash *ht);

/*
This function is called in int_to_bin_converter to do a logical conversion then returns a integer.
*/
int int_to_bin_converter(unsigned int c, int i);

/*
Receives a pointer, a integer number and the size of the byte, it converts an integer to
a binary representation.
*/
void int_to_bin(unsigned char *bin,int num, int bits);



#endif