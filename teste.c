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

void testandodaddy() {
	CU_ASSERT(5==daddy(10));
	CU_ASSERT(4==daddy(8));
	CU_ASSERT(3==daddy(7));
	
}

int run_tests() {
    testandodaddy();
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

    if(NULL == CU_add_test(pSuite, "testandodaddy", testandodaddy)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}