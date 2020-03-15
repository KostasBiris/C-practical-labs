#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book_management.h"
#include "users.h"

int number_users;				// the actual number of accounts in the social network
int AccountIdCounter;			// a counter for creating unique account IDs

//Registers a new user to the library and returns 0 if successful.
User* register_user(unsigned int uid, char* fn,char* ln, char* ut, char* e, char* p){
  Account* u= (User *)malloc(sizeof(User));

  u->userId= uid;
  strcpy(p->first_name,fn);
  strcpy(p->last_name,ln);
  strcpy(p->user_type,ut);
  strcpy(p->email,e);
  strcpy(p->user_password,p);
}

//Checks if the provided user id and password corresponds
//to an existing user in the user database and returns 0 if correct or 1 otherwise.
const int login(unsigned int id, char* password);

//Cheks if the provided book has enough copies left in the library's database.
//Returns 0 if the book is available and 1 otherwise.
int is_available(struct Book b);

//Removes the specified book from the library's database while decreasing the number of available copies and
//adds it to the user's books_borrowed array and returns 0 if successful;
const int borrow_book(struct Book b, User u);

//Removes the specified book from the user'books_borrowed array and
//adds it to the library's books database while increasing the number of available copies and returns 0 if successful;
const int return_book(struct Book b, User u);
