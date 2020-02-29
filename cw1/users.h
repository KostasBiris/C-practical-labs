#ifndef USERS_GUARD_H
#define USERS_GUARD_H

#include <string.h>
#include "book_management.h"

#define MaxUserID 20000 //the maximum number of id's issued.
#define MinPasswordSize 8 //the minimum size of a user's password.
#define MaxPasswoedSize 16 //the maximum size of a user's password.

#define MaxFirstNameSize 30
#define MaxLastNameSize 40

#define MaxNormalUsers 19950 //the maximum number of Normal type users.
#define MaxLibrarianUsers 50 //the maximum number of Librarian type users.

#define MaxBooksBorrowed 10 //the maximum number of Books a user can borrow.
#define MaxBooksReturned 10 //the maximum number of displayed returned Books by a user.

typedef struct {
  unsigned int userId;
  char* userPassword[MaxPasswoedSize];
  char* userType[9]; //"Normal" or "Librarian" (9 is the number of letters in the word Librarian).

  char* firstName[MaxFirstNameSize];
  char* middleName[MaxFirstNameSize]="No Middle Name";
  char* lastName[MaxLastNameSize];

  unsigned int numBooksBorrowed;
  unsigned int numBooksReturned;
  struct Book booksBorrowed[MaxBooksBorrowed];
  struct Book booksReturned[MaxBooksReturned];

}User;



#endif
