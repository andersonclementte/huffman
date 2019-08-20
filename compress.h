#ifndef compress_h
#define compress_h
#include "./header.h"

void compress(unsigned char * uncomp_archive_name);

unsigned char set_bit(unsigned char c, int i);

int is_bit_set(unsigned char c, int i);

unsigned char *get_new_bin(hash *ht, unsigned char c);

void print_tree_header(FILE *compressed_archive, node* tree);

void print_trash_treesize(FILE *compressed_archive, unsigned char *bits);

int write_compressed_file(FILE *archive, FILE *compressed_archive, hash *ht);

int int_to_bin_converter(unsigned int c, int i);

void int_to_bin(unsigned char *bin,int num, int bits);



#endif