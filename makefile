HUFF = huff.h huff.c
HEAP = heap.h heap.c
UTILS = header.h header.h 
TREE = tree.h tree.c
MAIN = maineuacho.c
TEST = teste.c

compile_tree:
	   gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(MAIN) -o tree -lm -w

compile_test:
		gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(TEST) -o test -lm -w -lcunit