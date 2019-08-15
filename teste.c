#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"
#include "./header.h"
#include "./huff.h"
#include "./tree.h"
#include "./heap.h"
#include "./hashtable.h"


int init_suite(void) {
	return 0;
}

int clear_suite(void) {
	return 0;
}



void heap_test() {
	heap* rip=create_heap();

	//testando create_heap
	CU_ASSERT(0 == rip->size);
	CU_ASSERT(NULL != rip);
	CU_ASSERT(1==isempty(rip));

	//testando enqueue
	node* test=create_node('a',10,NULL,NULL);
	enqueue(rip,test);
	node* test2=create_node('b',12,NULL,NULL);
	enqueue(rip,test2);
	node* test3=create_node('c',7,NULL,NULL);
	enqueue(rip,test3);
	CU_ASSERT('c' == rip->items[1]->data);
	CU_ASSERT(12 == rip->items[2]->frequency);

	//testando dequeue
	node* test4=dequeue(rip);
	CU_ASSERT('c' == test4->data);
	test4=dequeue(rip);
	CU_ASSERT(10==test4->frequency);
	test4=dequeue(rip);
	test4=dequeue(rip);
	CU_ASSERT(NULL==test4);
	
}

void huff_test() {
	
	//testando check_frequency
	unsigned char str[22]="AAAAAABBBBBCCCCDDDEEF";
	heap *riptest=create_heap();
	check_frequency(str,riptest);
	unsigned char testchar[1] = "F";
	CU_ASSERT_STRING_EQUAL(testchar, riptest->items[1]->data);
	CU_ASSERT(1 == riptest->items[1]->frequency);
	testchar[1]="E";
	CU_ASSERT(testchar == riptest->items[3]->data);
	CU_ASSERT(2 == riptest->items[3]->frequency);

	//testando merge
	node* merged=merge(riptest->items[1],riptest->items[3]);
	CU_ASSERT('*' == merged->data);
	CU_ASSERT(3 == merged->frequency);

	// testando build_huff_tree
	build_huff_tree(riptest);
	CU_ASSERT(1==riptest->size);
	
}

void hash_test()
{
	//testando criação da hash create_hash_table();
	hash * test_hash = create_hash_table();
	CU_ASSERT(NULL==test_hash->table[0]);
	CU_ASSERT(NULL==test_hash->table[255]);
	CU_ASSERT(NULL==test_hash->table[150]);

	//testando put bin on hash para ver se a inserção do binario ta certa
	 unsigned char biny[5]="0011";
	put_bin_on_hash(test_hash, 'a', biny, 4);
	CU_ASSERT_STRING_EQUAL(test_hash->table['a']->bin,biny);
	unsigned char biny2[5]="00";
	put_bin_on_hash(test_hash, 'b', biny2, 2);
	CU_ASSERT_STRING_EQUAL(test_hash->table['b']->bin,biny2);
	


}

int run_tests() {
    heap_test();
	huff_test();
	hash_test();

}

int main(void) {
	
	CU_pSuite pSuite = NULL;

	if(CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Basic_Test_Suite", init_suite, clear_suite);
	if(pSuite == NULL){
		return CU_get_error();
	}

    if(NULL == CU_add_test(pSuite, "heap_test", heap_test)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if(NULL == CU_add_test(pSuite, "huff_test", huff_test)) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	if(NULL == CU_add_test(pSuite, "hash_test", hash_test)) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}