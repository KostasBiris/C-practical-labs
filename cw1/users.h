#ifndef USERS_GUARD_H
#define USERS_GUARD_H

#include <string.h>
#include "book_management.h"

#define MaxUserID 3 //the maximum number of id's issued.
#define MinPasswordSize 8 //the minimum size of a user's password.
#define MaxPasswoedSize 16 //the maximum size of a user's password.

#define MaxFirstNameSize 30
#define MaxLastNameSize 40

#define MaxNumberUsers 3
#define MaxNormalUsers 2 //the maximum number of Normal type users.
#define MaxLibrarianUsers 1 //the maximum number of Librarian type users.

#define MaxBooksBorrowed 10 //the maximum number of Books a user can borrow.
#define MaxBooksReturned 10 //the maximum number of displayed returned Books by a user.

typedef struct {
  unsigned int userId;
  char first_name[MaxFirstNameSize];
  char last_name[MaxLastNameSize];
  unsigned int user_type; //(1)"Normal" or (2)"Librarian" (9 is the number of letters in the word Librarian).

  char email[254];
  char password[MaxPasswoedSize];

  unsigned int numBooksBorrowed;
  unsigned int numBooksReturned;
  struct Book books_borrowed[MaxBooksBorrowed];
  struct Book books_returned[MaxBooksReturned];

}User;

typedef struct{
  User *array;
  unsigned int length;
}User_Array;

// returns a new account id
// first time returns 1
// if no more IDs can be generated returns -1
int newUserId ();

//Registers a new user to the library and returns 0 if successful.
int register_user(unsigned int uid, char fn[],char ln[], unsigned int ut, char e[], char p[]);

// adds a user (pointer to the user) to the users_array
// if the array is full and cannot accept any more accounts the function returns 1
// otherwise the function returns 0
int add_user();

//Checks if the provided user id and password corresponds
//to an existing user in the user database and returns 0 if correct or 1 otherwise.
const int login(char email[], char password[]);

//Cheks if the provided book has enough copies left in the library's database.
//Returns 0 if the book is available and 1 otherwise.
int is_available(struct Book b);

//Removes the specified book from the library's database while decreasing the number of available copies and
//adds it to the user's books_borrowed array and returns 0 if successful;
const int borrow_book(struct Book b, User u);

//Removes the specified book from the user'books_borrowed array and
//adds it to the library's books database while increasing the number of available copies and returns 0 if successful;
const int return_book(struct Book b, User u);

#endif
