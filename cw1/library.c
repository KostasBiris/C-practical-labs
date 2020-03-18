#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "library.h"



//Cheks if the provided book has enough copies left in the library's database.
//Returns 0 if the book is available and 1 otherwise.
int is_available(struct Book b){

  for(int i=0; i<books_array.length; i++){
    if(books_array.array[i].bookId== book.bookId)&&(strcmp(books_array.array[i].title,book.title)==0) && (strcmp(books_array.array[i].authors,book.authors)==0)
     && (books_array.array[i].year== book.year) && (books_array.array[i].copies==book.copies)
  }
}
//Removes the specified book from the library's database while decreasing the number of available copies and
//adds it to the user's books_borrowed array and returns 0 if successful;
const int borrow_book(struct Book b, User u){

  u.books_borrowed[u.numBooksBorrowed]= book;
  u.numBooksBorrowed++;
  b.copies--;
  return 0;
}


//Removes the specified book from the user'books_borrowed array and
//adds it to the library's books database while increasing the number of available copies and returns 0 if successful;
const int return_book(struct Book b, User u);
