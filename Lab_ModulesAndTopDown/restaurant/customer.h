
#ifndef CUSTOMER_GUARD__H
#define CUSTOMER_GUARD__H

struct Address {
		const char *house;
		const char *street;
		const char *city;
		const char *post_code;
};

struct Customer {
		
		const char * name;
		struct Address address;
};

//Adds a new customer to the system
void customer_add(struct Customer c);

//deletes all records of existing customers
void customer_cleanup();

//returns a pointer to a customer with name *name* if existing, or a NULL pointer otherwise.
//The returned pointer points to an internal resource and belongs to the customer module (must not
//be freed from outside).
const struct Customer *customer_find_by_name(const char *name);

#endif
