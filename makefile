HUFF = huff.h huff.c
HEAP = heap.h heap.c
UTILS = header.h header.h 
TREE = tree.h tree.c
MAIN = maineuacho.c
TEST = teste.c
HASH = hashtable.h hashtable.c

compile_tree:
	   gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(MAIN) $(HASH) -o tree -lm -w

compile_test:
		gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(TEST) -o test -lm -w -lcunit