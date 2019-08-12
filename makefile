HUFF = huff.h huff.c
HEAP = heap.h heap.c
UTILS = header.h header.h 
TREE = tree.h tree.c
MAIN = maineuacho.c

compile_tree:
	   gcc $(UTILS) $(HUFF) $(HEAP) $(TREE) $(MAIN) -o teste -lm -w
