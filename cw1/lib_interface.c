#include "lib_interface.h"

#include "book_management.h"
#include "users.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const User *current_user=0;
static const struct Book *current_book=0;
//return a newly allocated data string
static char *command(const char *c) {

	printf("%s",c);
	const int size_step= 2;
	char *input= malloc(size_step);
	input[0]= 0; //now it's a string of length 0.

	//read until a new line in blocks of size_step  bytes at at time
	char *next_line= input;
	int loop_num = 0;
	do {
		input= realloc(input, size_step + loop_num*size_step);
		next_line= input + strlen(input); //answer may have moved.
		fgets(next_line, size_step, stdin);//input from the keyboard

		next_line= input + strlen(input); //take the new read into account
		loop_num++;
	} while (*(next_line-1)!='\n');

	*(next_line-1) = 0; //truncate the string eliminating the new line.

	return input;
}

//registers a new user to the library database
static void register_user() {

	User u;
	u.first_name= command("Enter User's Full Name: ");
	u.last_name= command("Enter User's Last Name: ");
	u.type= atoi(command("Enter User's Type: "));
	u.email= command("Enter User's Email: ");
	u.password= command("Enter User's Password: ");
	u.books_borrowed.length=0;


	add_user(u);
	current_user=login(u.email,u.password);
}

/*
static void search_for_customer_interface() {

	char *name = command("Name of the customer: ");

	current_customer = customer_find_by_name(name);
	current_order = 0; //reset order

	if (current_customer)
		printf("Customer %s found\n", current_customer->name);
	else
		printf("Name not found\n");


	free(name); //very important!
}
*/
