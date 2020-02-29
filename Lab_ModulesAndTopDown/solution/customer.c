#include "customer.h"

#include <stdlib.h>
#include <string.h>

/* here I'm using an array, however, a linked list would make sure that pointers to the elements of the 
 * structure are not invalidated by realloc */

static struct Customer *all_customers = 0;
static int customers_number = 0;
static int customer_array_size = 0;

const struct Customer * customer_add(struct Customer c) {
		
		const int customer_array_step = 10;
		
		if(customers_number + 1 > customer_array_size) { //needs to reallocate
				all_customers = realloc(all_customers, customer_array_size + customer_array_step * sizeof(struct Customer));
				customer_array_size += customer_array_step;
		}

		all_customers[customers_number] = c;
        
        return &all_customers[customers_number++];
}

const struct Customer * customer_find_by_name(const char* name) {
		
		for(int i=0; i < customers_number; ++i) {
				if(!strcmp(all_customers[i].name, name))
						return &(all_customers[i]);
		}
		
		return 0;

}


void customer_cleanup() {
		for(int i=0; i<customers_number; ++i) {
				free((void*)all_customers[i].name);
				
				free((void*) all_customers[i].address.city);
				free((void*) all_customers[i].address.house);
				free((void*) all_customers[i].address.street);
				free((void*) all_customers[i].address.post_code);
		}
		
		free(all_customers);
		all_customers = 0;
		customers_number = 0;
		customer_array_size = 0;
}


