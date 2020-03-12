#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "book_management.h"


void test_store_books() {
	FILE* f= fopen("../test_file.csv","w");

// test for files not existing.
	TEST_ASSERT_NOT_NULL_MESSAGE(f, "FAILED! File does not exist.")

	int ret_value= store_books(f); //returned value of the store_books() test.

	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret_value, "TEST FAILED: store_books() did not return 0.");
}


void test_load_books() {
	FILE* f= fopen("../test_file.csv","w");

// test for files not existing.
	TEST_ASSERT_NOT_NULL_MESSAGE(f, "FAILED! File does not exist.")

	int ret_value= load_books(f); //returned value of the store_books() test.

	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret_value, "TEST FAILED: load_books() did not return 0.");
}


void test_add_book() {
	struct Book b;

	int ret_value= add_book(b);

	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret_value, "TEST FAILED: add_books() did not return 0.");
}

void test_remove_book() {
	struct Book b;

	int ret_value= remove_book(b);

	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret_value, "TEST FAILED: remove_book() did not return 0.");
}


void test_find_book_by_title()  {
	char* t="Dracula";
	char* fake_t="Koala";

	struct BookArray ret_value= find_book_by_title(t);
	struct BookArray wret_value= find_book_by_title(fake_t);
	TEST_ASSERT_NULL_MESSAGE(ret_value.array,"TEST FAILED: find_book_by_title() couldn't find Dracula.");
	TEST_ASSERT_NOT_NULL_MESSAGE(wret_value.array,"TEST FAILED: find_book_by_title() didn't return Null for Koala.");

	TEST_ASSERT_EQUAL_INT_MESSAGE(ret_value.length,1,"TEST FAILED: find_book_by_title() returned an array with length %i not 1 for Dracula.");
	TEST_ASSERT_EQUAL_INT_MESSAGE(wret_value.length,0,"TEST FAILED: find_book_by_title() returned an array with length %i not 0 for Koala.");
}


void test_find_book_by_author() {
	char* a="Victor Hugo";
	char* fake_a="Fake Author";

	struct BookArray ret_value= find_book_by_author(a);
	struct BookArray wret_value= find_book_by_author(fake_a);
	TEST_ASSERT_NULL_MESSAGE(ret_value.array,"TEST FAILED: find_book_by_title() couldn't find Victor Hugo.");
	TEST_ASSERT_NOT_NULL_MESSAGE(wret_value.array,"TEST FAILED: find_book_by_title() didn't return Null for Fake Author.");

	TEST_ASSERT_EQUAL_INT_MESSAGE(ret_value.length,1,"TEST FAILED: find_book_by_title() returned an array with length %i not 1 for Victor Hugo.");
	TEST_ASSERT_EQUAL_INT_MESSAGE(wret_value.length,0, "TEST FAILED: find_book_by_title() returned an array with length %i not 0 for Fake Author.");
}


void test_find_book_by_year() {
	unsigned int y=1813;
	unsigned int fake_y=2021;

	struct BookArray ret_value= find_book_by_year(1813);
	struct BookArray wret_value= find_book_by_year(fake_y);
	TEST_ASSERT_NULL_MESSAGE(ret_value.array,"TEST FAILED: find_book_by_title() couldn't find 1813.");
	TEST_ASSERT_NOT_NULL_MESSAGE(wret_value.array,"TEST FAILED: find_book_by_title() didn't return Null for 2021.");

	TEST_ASSERT_EQUAL_INT_MESSAGE(ret_value.length,1,"TEST FAILED: find_book_by_title() returned an array with length %i not 1 for 1813.");
	TEST_ASSERT_EQUAL_INT_MESSAGE(wret_value.length,0, "TEST FAILED: find_book_by_title() returned an array with length %i not 0 for 2021.");
}


void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

/*int main() {
	UNITY_BEGIN();


	RUN_TEST(test_store_books);
	RUN_TEST(test_load_books);
	RUN_TEST(test_add_book);
	RUN_TEST(test_remove_book);
	RUN_TEST(test_find_book_by_title);
	RUN_TEST(test_find_book_by_author);
	RUN_TEST(test_find_book_by_year);
	return UNITY_END();
}*/
