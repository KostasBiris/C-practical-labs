#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book_management.h"

struct BookArray books_array={0};
int number_books=0;
//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file){
  books_array.length=0;
  int buff=0;
  char b;
  char buff1[512];
  struct Book* loaded_book;
  loaded_book= (struct Book*)malloc(sizeof(struct Book));
  char *token;
  int i=0;

  for(b=getc(file);b!=EOF;b=getc(file)){
    if(b=='\n'){
      i++;
    }
  }
  rewind(file);

  number_books=i-1;
  books_array.array= calloc(number_books,sizeof(struct Book));
  while (fgets(buff1, 512, file)) {

    if(buff==0){
      buff++;
      continue;
    }

    //Id
    token= strtok(buff1,",");
    loaded_book->id= atoi(token);

    //Title
    token= strtok(NULL,",");
    loaded_book->title=(char*)malloc(sizeof(char)*strlen(token));
    strcpy(loaded_book->title,token);

    //Author
    token= strtok(NULL,",");
    loaded_book->authors=(char*)malloc(sizeof(char)*strlen(token));
    strcpy(loaded_book->authors,token);

    //Year
    token= strtok(NULL,",");
    loaded_book->year= atoi(token);

    //Copies
    token= strtok(NULL,",");
    loaded_book->copies= atoi(token);

    books_array.array[books_array.length]= *loaded_book;
    books_array.length++;
    }

  books_array.array= (struct Book*) books_array.array;


  return 0;
}
//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(struct Book book) {

  books_array.array[books_array.length]= book;
  books_array.length++;
  return 0;
}

//removes a book from the library
//returns 0 if the book could be successfully removed, returns 1 if the book isn't in the borrowed books array of the user, or an error code otherwise.
int remove_book(struct Book book){
  int length =books_array.length;
  int index=-1;

  for(int i=0;i<length;i++){
    if((strcmp(books_array.array[i].title,book.title)==0) && (strcmp(books_array.array[i].authors,book.authors)==0)&&(books_array.array[i].year== book.year)){
      index=i;
      break;
     }
  }
  if(index==-1){
    printf("Book not found in your Borrowed Books list");
    return 1;
  }

  for(int j= index; j< length-2; j++){
    books_array.array[j]=books_array.array[j+1];

  books_array.length--;
}
  return 0;
}

//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file){
  struct Book book_temp;
  struct Book* array_temp= (struct Book*)malloc(sizeof(struct Book));
  array_temp=books_array.array;

  if(file==NULL){
    return -1;
  }

  for(int i=1; i<books_array.length;i++){
    book_temp= *(array_temp+i);
    fprintf(file,"%d,%s,%s,%d,%d\n",book_temp.id, book_temp.title, book_temp.authors, book_temp.year, book_temp.copies);
  }
  return 0;
}

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_title (const char *title){
  int index=0;
  int i=0;
  int length=0;
  struct Book temp_array[index];

  while(i<books_array.length){
    if((strcmp(books_array.array[i].title,title)==0)){
      temp_array[index]=books_array.array[i];
      index++;
      length++;
    }
    i++;
  }
  struct BookArray* title_array=(struct BookArray*)calloc(1,sizeof(struct BookArray));
  title_array->array=NULL;
  title_array->length=0;

  if(length!=0){
    title_array->array=temp_array;
    title_array->length=length;
  }
  return *title_array;
}

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_author (const char *author){
  int index=0;
  int i=0;
  int length=0;
  struct Book temp_array[index];

  while(i<books_array.length){
    if((strcmp(books_array.array[i].authors,author)==0)){
      temp_array[index]=books_array.array[i];
      index++;
      length++;
    }
    i++;
  }
  struct BookArray* author_array=(struct BookArray*)calloc(1,sizeof(struct BookArray));
  author_array->array=NULL;
  author_array->length=0;

  if(length!=0){
    author_array->array=temp_array;
    author_array->length=length;
  }
  return *author_array;
}

//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_year (unsigned int year){
  int index=0;
  int i=0;
  int length=0;
  struct Book temp_array[index];

  while(i<books_array.length){
    if(books_array.array[i].year==year){
      temp_array[index]=books_array.array[i];
      index++;
      length++;
    }
    i++;
  }
  struct BookArray* year_array=(struct BookArray*)calloc(1,sizeof(struct BookArray));
  year_array->array=NULL;
  year_array->length=0;

  if(length!=0){
    year_array->array=temp_array;
    year_array->length=length;
  }
  return *year_array;
}
/*
int main(){
  FILE* file1= fopen("../books.csv","r");
  FILE* file2= fopen("../test_file.csv","w");
  struct BookArray an_array;

  struct Book b1;
  b1.id=5;
  b1.title = "BookTitle";
  b1.authors="BookAuthor";
  b1.year=2020;
  b1.copies=6;
  load_books(file1);

  struct Book b2;
  b2.title= "Dracula";
  b2.authors= "Bram Stoker";
  b2.year= 1897;
  b2.copies=4;

  //struct BookArray an_array=find_book_by_title("Pride and Prejudice");
  //printf(an_array.array[0].title);
  add_book(b1);
  an_array=find_book_by_title("Pride and Prejudice");
  remove_book(b2);
  store_books(file2);

  return 0;
}*/
