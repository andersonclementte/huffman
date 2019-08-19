HUFF = huff.h huff.c
HEAP = heap.h heap.c
UTILS = header.h header.h 
TREE = tree.h tree.c
MAIN = maineuacho.c
TEST = teste.c
HASH = hashtable.h hashtable.c
COMPRESS = compress.h compress.c

compile_tree:
	   gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(MAIN) $(HASH) $(COMPRESS) -o tree -lm -w

compile_test:
		gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(TEST) $(HASH) -o test -lm -w -lcunit