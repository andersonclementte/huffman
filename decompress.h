#ifndef decompress_h
#define decompress_h
#include "./header.h"

node *build_tree (node *huff_tree, FILE *compressed_file);

void decompress(unsigned char *compressed_archive_name);

#endif