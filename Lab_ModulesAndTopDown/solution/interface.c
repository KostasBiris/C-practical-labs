#include "interface.h"

#include "customer.h"
#include "order.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*	NOTE the use of *static* for functions and variables that must not be accessed
		from outside this file, and the use of *const* on parameters and return values
		that are not meant to be modified. */

static const struct Customer *current_customer=0;
static  struct Order *current_order=0;

//return a newly allocated string
static char *ask_question(const char *question) {

	printf("%s",question);

	const int size_step = 2;
	char *answer = malloc(size_step);
	answer[0] = 0; //now it's a string of length 0.

	//read until a new line in blocks of size_step  bytes at at time
	char *next_chunk = answer;
	int iteration = 0;
	do {
		answer = realloc(answer, size_step + iteration*size_step);
		next_chunk = answer + strlen(answer); //answer may have moved.
		fgets(next_chunk, size_step, stdin);

		next_chunk = answer + strlen(answer); //take the new read into account
		++iteration;
	} while (* (next_chunk-1) != '\n');

	*(next_chunk-1) = 0; //truncate the string eliminating the new line.

	return answer;
}

static void enter_customer_interface() {

	struct Customer c;
	c.name = ask_question("Customer's full name: ");

	c.address.house = ask_question("Address\nHouse name/number: ");

	c.address.street = ask_question("Street name: ");

	c.address.city = ask_question("City: ");

	c.address.post_code = ask_question("Post code: ");

	//the customer module is taking ownership of all the strings.
	current_customer =customer_add(c);

	current_order = 0; //reset order
}

static void search_for_customer_interface() {

	char *name = ask_question("Name of the customer: ");

	current_customer = customer_find_by_name(name);
	current_order = 0; //reset order

	if (current_customer)
		printf("Customer %s found\n", current_customer->name);
	else
		printf("Name not found\n");


	free(name); //very important!
}

static void create_order_interface() {
	if (!current_customer) {
		printf("No current customer");
		return ;
	}

	char *answer=0;
	int dish_entered = 0;

	current_order = order_create(current_customer);

	do {
		free(answer); //it is safe to free the null pointer
		//without the free() above, every call to ask_question leaks the string
		//of the previous answer!

		answer = ask_question("Dish to order, or enter to terminate the order: ");

		dish_entered = strlen(answer) > 1;

		if (dish_entered) {
			int error = order_add_dish(current_order, answer);

			if (error)
				printf("Couldn't find dish!\n");
		}

	} while (dish_entered);  // until the user only hits enter.

	free(answer); //obviously!
}

static void print_order_summary() {

	if (current_order) {

		printf("Order Summary:\n");

		for (int i=0 ; i < current_order->order_length; ++i)
			printf("  %s\n  %s\n  calories: %d\n\n", current_order->dishes[i]->name,
			       current_order->dishes[i]->description,
			       current_order->dishes[i]->calories);
	} else {
		printf("Nothing ordered so far\n");
	}
}


static void main_menu() {

	int choice = 5; //exit

	do {

		char * answer = ask_question("\nPlease enter next action:\n1) Enter Customer\n2) Search for Customer\n3) Create Order\n4) Print Order Summary\n5) Quit\nchoice: ");
		choice = atoi(answer);
		free(answer);

		switch (choice) {
			case 1:
				enter_customer_interface();
				break;
			case 2:
				search_for_customer_interface();
				break;
			case 3:
				create_order_interface();
				break;
			case 4:
				print_order_summary();
				break;
			case 5:
				printf("goodbye");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}

	} while (choice != 5);

	return;
}


void run_interface() {

	main_menu();
	//time to clean up behind us.

	customer_cleanup();
	order_cleanup();

	return;
}

