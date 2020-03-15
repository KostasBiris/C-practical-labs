#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book_management.h"
#include "users.h"

static int number_users=0;				// the number of users in the library
int userId_counter;			// a counter for creating unique user IDs
static User* all_users[MaxNumberUsers];
static User_Array users_array;


// adds a user (pointer to the user) to the users_array
// if the array is full and cannot accept any more accounts the function returns 1
// otherwise it returns 0.
int add_user(User* u){
  if(number_users==MaxNumberUsers)
    return 1;

  all_users[number_users]= u;
  users_array.length++;
  number_users++;
  return 0;
}

//Registers a new user to the library and returns 0 if successful.
int register_user(unsigned int uid, char fn[],char ln[], unsigned int ut, char e[], char p[]){
  User* u= (User *)malloc(sizeof(User));

  u->userId= uid;
  snprintf(u->first_name, sizeof(fn),"%s",fn);
  snprintf(u->last_name, sizeof(ln),"%s",ln);
  u->user_type=ut;
  snprintf(u->email, sizeof(e),"%s",e);
  snprintf(u->password, sizeof(p),"%s",p);
  u->numBooksBorrowed=0;
  u->numBooksReturned=0;

  add_user(u);
  return 0;
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

int main(){
  unsigned int iD=1;
  char firstName[MaxFirstNameSize]="Ragnaros";
  char lastName[MaxLastNameSize]="Preachos";
  unsigned int type=1;
  char email[254]="email@mail.com";
  char password[MaxPasswoedSize]="2rfadasasd";

  register_user(iD,firstName,lastName,type,email,password);
  return 0;
}
