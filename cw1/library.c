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

  u.books_borrowed.array[books_borrowed.length]= book;
  u.books_borrowed.length++;
  b.copies--;
  return 0;
}


//removes a book from the library
//returns 0 if the book could be successfully removed, returns 1 if the book isn't in the borrowed books array of the user, or an error code otherwise.
const int return_book(struct Book b, User u){
  int length =u.books_borrowed.length;
  int index=-1;

  for(int i=0;i<length;i++){
    if((u.books_borrowed.array[i].bookId== b.bookId)&&(strcmp(u.books_borrowed.array[i].title,b.title)==0)
      && (strcmp(u.books_borrowed.array[i].authors,b.authors)==0)
      && (u.books_borrowed.array[i].year== b.year)){
      index=i;
      add_book(b);
      break;
     }
  }
  if(index==-1)
    return 1;

  for(int j= index; j< length-2; j++){
    u.books_borrowed.array[j]=u.books_borrowed.array[j+1];

  u.books_borrowed.length--;
}
  return 0;
}
