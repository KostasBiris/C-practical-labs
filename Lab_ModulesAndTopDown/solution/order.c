#include "order.h"

#include <stdlib.h>
#include <string.h>

/*With a linked list adding orders does not invalidate pointers
 * to existing orders returned by order_find() */

struct OrderNode {
	struct Order o;
	struct OrderNode *next;
};

static struct Dish *all_dishes = 0;
static int dish_number = 0;

static struct OrderNode *bgn = 0;
static struct OrderNode *end = 0;
static int max_id = 0;

static void load_dishes() {

	//this would probably load from a file, but for now I'll simplify

	dish_number =3;
	all_dishes = calloc(dish_number,sizeof(struct Dish));

	all_dishes[0].name = "lasagna";
	all_dishes[0].description = "good stuff";
	all_dishes[0].calories = 20000;

	all_dishes[1].name = "polenta";
	all_dishes[1].description = "something for the Winter";
	all_dishes[1].calories = 350;

	all_dishes[2].name = "parmigiana";
	all_dishes[2].description = "the best of all";
	all_dishes[2].calories = 5000;
}

static const struct Dish *find_dish(const char* name) {

	if (!all_dishes)
		load_dishes();

	for (int i=0; i< dish_number; ++i) {
			if (!strcmp(all_dishes[i].name, name))
				return &all_dishes[i];
		}

	return 0;
}

static struct Order *find_order(const struct Customer* customer) {

	struct OrderNode *current = bgn;

	for (; current; current = current->next) {
			if (current->o.customer == customer)
				return &(current->o);
		}

	return 0;
}


static void add_dish_to_order(const struct Dish *d,struct  Order *o) {

	if (o->order_length + 1 > o->array_size) {
			o->dishes = realloc((void*)o->dishes,sizeof(struct Dish*) * (o->array_size + 1));
			++(o->array_size);
		}

	o->dishes[(o->order_length)++] = d;
}

static void init_order(struct Order *o, const struct Customer *c) {
	o->customer = c;
	o->dishes = 0;
	o->order_length = 0;
	o->array_size = 0;
	o->ID = max_id++;
}

static void create_new_order(const struct Customer* customer) {
	struct OrderNode *newNode = malloc(sizeof(struct OrderNode));
	init_order(&(newNode->o), customer);
	newNode->next = 0;
	if (!bgn)
		bgn = newNode;
	if (end)
		end->next = newNode;
	end = newNode;
}

int order_add_dish(struct Order *order, const char* dish_name) {

	const struct Dish *d = find_dish(dish_name);

	if (!d) {
			//couldn't find dish!
			return 1;
		}

	add_dish_to_order(d,order);

	return 0;
}


void order_cleanup() {
	struct OrderNode *current = bgn;

	while (current) {
			struct OrderNode *toDelete = current;
			current = current->next;
			free(toDelete->o.dishes);
			free(toDelete);
		}
	bgn = 0;
	end = 0;
	
	//delete all dishes
	free(all_dishes);
	all_dishes =0;
}

struct Order * order_create(const struct Customer *customer) {
	 
		create_new_order(customer);
		return &(end->o);
	 
}


