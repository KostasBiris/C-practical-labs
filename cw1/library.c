#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book_management.h"
#include "users.h"
#include "library.h"

LoanArray loans_array={0};
int number_loans=0;

int load_loans(FILE *file){
  loans_array.length=0;
  int buff=0;
  char b;
  char buff1[512];
  Loan* loaded_loan;
  loaded_loan= (Loan*)malloc(sizeof(Loan));
  char *token;
  int i=0;

  for(b=getc(file);b!=EOF;b=getc(file)){
    if(b=='\n'){
      i++;
    }
  }
  rewind(file);

  number_loans=i-1;
  loans_array.array= calloc(number_loans,sizeof(Loan));
  while (fgets(buff1, 512, file)) {

    if(buff==0){
      buff++;
      continue;
    }
    //Loan ID
    token= strtok(buff1,",");
    loaded_loan->loan_id= atoi(token);

    //User ID
    token= strtok(NULL,",");
    loaded_loan->user_id= atoi(token);

    //Book ID
    token= strtok(NULL,",");
    loaded_loan->book_id= atoi(token);
    }

  loans_array.array= (Loan*) loans_array.array;

  return 0;
}


//Cheks if the provided book has enough copies left in the library's database.
//Returns 0 if the book is available and 1 otherwise.
int is_available(struct Book book){

  for(int i=0; i<books_array.length; i++){
    if((strcmp(books_array.array[i].title,book.title)==0) && (strcmp(books_array.array[i].authors,book.authors)==0)
     && (books_array.array[i].year== book.year) && (books_array.array[i].copies==book.copies))
      return 0;

    else
      return 1;
  }
}
//Removes the specified book from the library's database while decreasing the number of available copies and
//adds it to the user's books_borrowed array and returns 0 if successful;
 const int borrow_book(struct Book b, User u){

  u.books_borrowed.array[u.books_borrowed.length]= b;
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
    if((strcmp(u.books_borrowed.array[i].title,b.title)==0)
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

//saves the database of loans in the specified file
//returns 0 if loans were stored correctly, or an error code otherwise
int store_loans(FILE *file){
  Loan loan_temp;
  Loan* array_temp= (Loan*)malloc(sizeof(Loan));
  array_temp=loans_array.array;

  if(file==NULL){
    return -1;
  }

  for(int i=1; i<loans_array.length;i++){
    loan_temp= *(array_temp+i);
    fprintf(file,"%d,%d,%d\n", loan_temp.loan_id, loan_temp.user_id, loan_temp.book_id);
  }
  return 0;
}
