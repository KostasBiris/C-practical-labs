#ifndef ORDER_GUARD__H
#define ORDER_GUARD__H

struct Dish {
	char *name;
    char *description;
	int calories;
};

struct Order {
		const struct Customer* customer;
		const struct Dish **dishes; //array of pointers to Dish
		int order_length; //number of dishes ordered;
		int array_size;
		int ID; // the same customer could make multiple orders
};


struct Customer; //forward declaration of Customer.

//creates an order for the customer *customer*. The module stores 
//the Orders internally. It also stores the pointer to customer. This function returns a pointer to the internal
//order, therefore the pointer must not be freed (it belongs to the module).
struct Order * order_create(const struct Customer *customer);

//adds a dish with name *dish_name* to an existing order *order*. 
//return true if a dish with such a name does not exist.
int order_add_dish(struct Order * order,const char *dish_name);

//frees any resource allocated to store orders.
void order_cleanup();

#endif
