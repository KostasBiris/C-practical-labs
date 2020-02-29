
#include "unity.h"



void test_a_function() {



}

void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();


	RUN_TEST(test_a_function);

	return UNITY_END();
}
