#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"
#include "./header.h"
#include "./huff.h"
#include "./tree.h"
#include "./heap.h"


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
	test=create_node('a',10,NULL,NULL);

	
}

int run_tests() {
    heap_test();

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

	

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}