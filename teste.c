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

void testandoTeste() {
	char expected_string = "f:21 c:* f:9 c:* f:4 c:C f:5 c:B f:12 c:* f:6 c:* f:3 c:D f:3 c:* f:1 c:F f:2 c:E f:6 c:A ";
	CU_ASSERT_STRING_EQUAL(expected_string, print_preorder(rip->items[1]));
}

int run_tests() {
    testandoTeste();
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

    if(NULL == CU_add_test(pSuite, "testandoTeste", testandoTeste)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}