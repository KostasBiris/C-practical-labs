#include "lib_interface.h"

#include "book_management.h"
#include "users.h"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const User *current_user=0;
static const struct Book *current_book=0;

char* temp_email;
char* temp_password;
char* title;
char* author;
unsigned int year;
char* users_choice2;
struct BookArray temp_array;
int book_was_borrowed;
int book_was_returned; //equals 0 if the book was returned, 1 if the book doesn't exist in the user's books_borrowed array
struct Book temp_book;
int book_was_returned;

struct Book book_added;
int book_was_removed;
//return a newly allocated data string
static char *command(const char *c) {

	printf("%s",c);
	const int size_step= 2;
	char *input= malloc(size_step);
	input[0]= 0; //now it's a string of length 0.

	//read until a new line in blocks of size_step  bytes at at time
	char *next_line= input;
	int loop_num = 0;
	do {
		input= realloc(input, size_step + loop_num*size_step);
		next_line= input + strlen(input); //answer may have moved.
		fgets(next_line, size_step, stdin);//input from the keyboard

		next_line= input + strlen(input); //take the new read into account
		loop_num++;
	} while (*(next_line-1)!='\n');

	*(next_line-1) = 0; //truncate the string eliminating the new line.

	return input;
}

//registers a new user to the library database
static void register_user() {

	User u;
	u.first_name= command("Enter User's Full Name: ");
	u.last_name= command("Enter User's Last Name: ");
	u.type= atoi(command("Enter User's Type: "));
	u.email= command("Enter User's Email: ");
	u.password= command("Enter User's Password: ");
	u.books_borrowed.length=0;


	add_user(u);
	current_user=login(u.email,u.password);
}

static void main_menu() {

	int choice = 3;
	int choice2= 2;

	printf("###########################################################################");
	printf("\n############   		Library System Initiated       ############");
	printf("\n###########################################################################");

	do {
		printf("\n---------------------------------------------------------------------------\n");
		char * users_choice = command("\nWhat would you like to do?:\n1) Login\n2) Register\n3) Quit\n\nChoice:");
		printf("\n----------------------------------------------------------------------------\n");
		choice = atoi(users_choice);
		free(users_choice);

		switch (choice) {


			case 1:
				printf("\nEmail: ");
				scanf("%s\n",temp_email);

				printf("\nPassword: ");
				scanf("%s\n",temp_password);

				current_user=login(temp_email,temp_password);

				break;

			case 2:
				register_user();
				break;

			case 3:
				printf("\nHave a nice Day!\n");
				break;
			default:
				printf("\nSorry, that doesn't seem to be an option\n");
		}

	} while (choice!=3);

//load user's Borrowed books
	for(int i=0;i<loans_array.length;i++){
		for(int j=0;j<books_array.length;j++){
			if(current_user->userId==loans_array.array[i].user_id){
				if(loans_array.array[i].book_id==books_array.array[j].id){
					borrow_book(books_array.array[i],*current_user);
				}
			}
		}
	}
//========================================={Start: Normal User}==================================================
	if(current_user->type==1){

		do {
			printf("\n---------------------------------------------------------------------------\n");
			char * users_choice = command("\nWhat would you like to do now?:\n1) Borrow Book\n2) Return Book\n3) Logout\n\nChoice: ");
			printf("\n----------------------------------------------------------------------------\n");
			choice = atoi(users_choice);
			free(users_choice);

			switch (choice) {
//----------------------------------------------------{Start:Borrow Book}----------------------------------------------------------
				case 1:
				do {
					printf("\n---------------------------------------------------------------------------\n");
					char * users_choice = command("\n1) Find Book by Title\n2) Find Book by Author\n3) Find Book by Year\n4)Go Back\n\nChoice: ");
					printf("\n----------------------------------------------------------------------------\n");
					choice = atoi(users_choice);
					free(users_choice);

					switch (choice) {
				//1) Find Book by Title
						case 1:
							printf("\nBook's Title: ");
							scanf("%s\n", title);

							temp_array=find_book_by_title(title);

							if(temp_array.length==0){
								printf("\nBook with title <<%s>> was Not found\n",title);
							}

							else{
								printf("\nBook with title <<%s>> was found\nDo you want to borrow it?\n",title);
								users_choice2= command("\n1) Yes\n2) No\n\nChoice: ");
								choice = atoi(users_choice);
								free(users_choice2);

								if(choice==1){
									printf("\nBook was returned successfully.\n");
									book_was_borrowed=borrow_book(temp_array.array[0],*current_user);
									break;
								}
							}

				//2) Find Book by Author
						case 2:
						printf("\nBook's Author: \n");
						scanf("%s\n", author);

						temp_array=find_book_by_author(author);

						if(temp_array.length==0){
							printf("Book with author <<%s>> was Not found",author);
						}

						else{
							printf("\nBook with title <<%s>> was found\nDo you want to borrow it?\n",title);
							users_choice2= command("\n1) Yes\n2) No\n\nChoice: ");
							choice = atoi(users_choice2);
							free(users_choice2);

							if(choice==1){
								borrow_book(temp_array.array[0],*current_user);
								break;
							}
						}
						break;

				//3) Find Book by Year
						case 3:
						printf("\nBook's Year: ");
						scanf("%d\n", year);

						temp_array=find_book_by_year(year);

						if(temp_array.length==0){
							printf("Book from <<%d>> was Not found",year);
						}

						else{
							printf("\nBook from <<%d>> was found\nDo you want to borrow it?\n",year);
							users_choice2 = command("\n1) Yes\n2) No\n\nChoice: ");
							choice = atoi(users_choice2);
							free(users_choice2);

							if(choice==1){
								borrow_book(temp_array.array[0],*current_user);
								break;
							}
						}
						break;

				//4)Go Back
						case 4:
							break;

						default:
							printf("Sorry, that doesn't seem to be an option\n");
					}

				}while (choice!=4);
				break;
//----------------------------------------------------{End:Borrow Book}----------------------------------------------------------

//--------------------------------------------------{Start:Return Book}----------------------------------------------------------
				case 2:

					do{
						char * users_choice2 = command("\n1) Enter Book details\n2) Go Back\n\nChoice:");
						printf("\n----------------------------------------------------------------------------\n");
						choice2 = atoi(users_choice2);
						free(users_choice2);


						switch (choice2){
							case 1:
								printf("\nPlease Enter the details of the Book you want to return.\n");
								temp_book.title=command("Book's Title: ");
								temp_book.authors=command("Book's Author: ");
								temp_book.year=atoi(command("Book's Year: "));
								temp_book.copies=1;

								book_was_returned=return_book(temp_book,*current_user);

								if(book_was_returned==0){
									printf("\nBook was returned successfully.\n");
									break;
								}

								else if(book_was_returned==1){
									printf("\nThere is no such Book in your Borrowed Books list.\n");
									break;
								}

								else{
									printf("\nSomething Unexpected Happened.\n");
									break;
								}
								break;

							case 2:
								break;

							default:
								printf("\nSorry,that doesn't seem to be an option.\n");
						}
					}while(choice2!=2);
					break;
//---------------------------------------------------{End:Return Book}------------------------------------------------------------

//--------------------------------------------------{Start: Logout}---------------------------------------------------------------
				case 3:
					printf("Have a nice Day!");
					break;
//--------------------------------------------------{End: Logout}---------------------------------------------------------------
				default:
					printf("\nSorry, that doesn't seem to be an option\n");

				}
		}while(choice!=3);
	}
//===================================={End: Normal User}===============================================================

//===================================={Start: Librarian}================================================================
	if(current_user->type==2){

		do {
			printf("\n\t\t\t---------------------------------------------------------------------------\n");
			char * users_choice = command("\nWhat would you like to do now?:\n1) Borrow Book\n2) Return Book\n3)Add Book\n4)Remove Book\n5) Logout\n\nChoice: \n\n\n");
			printf("\n----------------------------------------------------------------------------\n");
			choice = atoi(users_choice);
			free(users_choice);

			switch (choice) {
//----------------------------------------------------{Start:Borrow Book}----------------------------------------------------------
				case 1:
				do {
					printf("\n---------------------------------------------------------------------------\n");
					char * users_choice = command("\n1) Find Book by Title\n2) Find Book by Author\n3) Find Book by Year\n4)Go Back\n\nChoice: \n\n\n");
					printf("\n----------------------------------------------------------------------------\n");
					choice = atoi(users_choice);
					free(users_choice);

					switch (choice) {
				//1) Find Book by Title
						case 1:
							printf("\nBook's Title: \n");
							scanf("%s\n", title);

							temp_array=find_book_by_title(title);

							if(temp_array.length==0){
								printf("Book with title <<%s>> was Not found",title);
							}

							else{
								printf("Book with title <<%s>> was found\nDo you want to borrow it?",title);
								users_choice2= command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
								choice = atoi(users_choice);
								free(users_choice2);

								if(choice==1){
									printf("Book was returned successfully.");
									book_was_borrowed=borrow_book(temp_array.array[0],*current_user);
									break;
								}
							}

				//2) Find Book by Author
						case 2:
						printf("\nBook's Author: \n");
						scanf("%s\n", author);

						temp_array=find_book_by_author(author);

						if(temp_array.length==0){
							printf("\nBook with author <<%s>> was Not found\n",author);
						}

						else{
							printf("\nBook with title <<%s>> was found\nDo you want to borrow it?\n",title);
							users_choice2= command("\n1) Yes\n2) No\n\nChoice: ");
							choice = atoi(users_choice2);
							free(users_choice2);

							if(choice==1){
								borrow_book(temp_array.array[0],*current_user);
								break;
							}
						}
						break;

				//3) Find Book by Year
						case 3:
						printf("\nBook's Year: ");
						scanf("%d\n", year);

						temp_array=find_book_by_year(year);

						if(temp_array.length==0){
							printf("\nBook from <<%d>> was Not found\n",year);
						}

						else{
							printf("Book from <<%d>> was found\nDo you want to borrow it?",year);
							users_choice2 = command("\n1) Yes\n2) No\n\nChoice:\n");
							choice = atoi(users_choice2);
							free(users_choice2);

							if(choice==1){
								borrow_book(temp_array.array[0],*current_user);
								break;
							}
						}
						break;

				//4)Go Back
						case 4:
							break;

						default:
							printf("\nSorry, that doesn't seem to be an option\n");
					}

				}while (choice!=4);
				break;
//----------------------------------------------------{End:Borrow Book}----------------------------------------------------------

//--------------------------------------------------{Start:Return Book}----------------------------------------------------------
				case 2:

					do{
						char * users_choice2 = command("\n1) Enter Book details\n2) Go Back\n\nChoice: ");
						printf("\n----------------------------------------------------------------------------\n");
						choice2 = atoi(users_choice2);
						free(users_choice2);


						switch (choice2){
							case 1:
								printf("\nPlease Enter the details of the Book you want to return.\n");
								temp_book.title=command("Book's Title: ");
								temp_book.authors=command("Book's Author: ");
								temp_book.year=atoi(command("Book's Year: "));
								temp_book.copies=1;

								book_was_returned=return_book(temp_book,*current_user);

								if(book_was_returned==0){
									printf("\nBook was returned successfully.\n");
									break;
								}

								else if(book_was_returned==1){
									printf("\nThere is no such Book in your Borrowed Books list.\n");
									break;
								}

								else{
									printf("\nSomething Unexpected Happened.\n");
									break;
								}
								break;

							case 2:
								break;

							default:
								printf("\nSorry,that doesn't seem to be an option.\n");
						}
					}while(choice2!=2);
					break;
//---------------------------------------------------{End:Return Book}------------------------------------------------------------

//--------------------------------------------------{Start: Add Book}---------------------------------------------------------------
				case 3:
					printf("Please Enter the Book's details.");

					book_added.title= command("Enter the Book's Title: ");
					book_added.authors= command("Enter the Book's Authors: ");
					book_added.year= atoi(command("Enter the Book's Year: "));
					book_added.copies= atoi(command("Enter the Book's number of copies: "));

					add_book(book_added);
					break;
//--------------------------------------------------{End: Add Book}-----------------------------------------------------------------

//--------------------------------------------------{Start: Remove Book}-----------------------------------------------------------
				case 4:
					do {
						printf("\n---------------------------------------------------------------------------\n");
						char * users_choice = command("\n1) Find Book by Title\n2) Find Book by Author\n3) Find Book by Year\n4)Go Back\n\nChoice:");
						printf("\n----------------------------------------------------------------------------\n");
						choice = atoi(users_choice);
						free(users_choice);

						switch (choice) {
					//1) Find Book by Title
							case 1:
								printf("Book's Title: ");
								scanf("%s\n", title);

								temp_array=find_book_by_title(title);

								if(temp_array.length==0){
									printf("Book with title <<%s>> was Not found",title);
								}

								else{
									printf("Book with title <<%s>> was found\nDo you want to remove it?",title);
									users_choice2= command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
									choice = atoi(users_choice);
									free(users_choice2);

									if(choice==1){
										printf("Book was returned successfully.");
										book_was_removed=remove_book(temp_array.array[0]);
										break;
									}
								}

					//2) Find Book by Author
							case 2:
							printf("Book's Author: ");
							scanf("%s\n", author);

							temp_array=find_book_by_author(author);

							if(temp_array.length==0){
								printf("Book with author <<%s>> was Not found",author);
							}

							else{
								printf("Book with title <<%s>> was found\nDo you want to remove it?",title);
								users_choice2= command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
								choice = atoi(users_choice2);
								free(users_choice2);

								if(choice==1){
									book_was_removed=remove_book(temp_array.array[0]);
									break;
								}
							}
							break;

					//3) Find Book by Year
							case 3:
								printf("Book's Year: ");
								scanf("%d\n", year);

								temp_array=find_book_by_year(year);

								if(temp_array.length==0){
									printf("Book from <<%d>> was Not found",year);
								}

								else{
									printf("Book from <<%d>> was found\nDo you want to remove it?",year);
									users_choice2 = command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
									choice = atoi(users_choice2);
									free(users_choice2);

									if(choice==1){
										book_was_removed=remove_book(temp_array.array[0]);
										break;
									}
								}
								break;

					//4)Go Back
							case 4:
								break;

							default:
								printf("Sorry, that doesn't seem to be an option\n");
						}

					}while (choice!=4);
					break;
//--------------------------------------------------{End: Remove Book}--------------------------------------------------------------

//--------------------------------------------------{Start: Logout}---------------------------------------------------------------
				case 5:
					printf("Have a nice Day!");
					break;
//--------------------------------------------------{End: Logout}---------------------------------------------------------------
				default:
					printf("Sorry, that doesn't seem to be an option\n");

				}
		}while(choice!=5);
	}

	return;
}

void run_lib_interface(){
	FILE* original_file_books= fopen("../books.csv","r");
	FILE* original_file_users= fopen("../users.csv","r");
	FILE* original_file_loans= fopen("../loans.csv","r");

	load_books(original_file_books);
	load_users(original_file_users);
	load_loans(original_file_loans);

	main_menu();

	FILE* end_file_books= fopen("../books.csv","w");
	FILE* end_file_users= fopen("../users.csv","w");
	FILE* end_file_loans= fopen("../loans.csv","w");

	store_books(end_file_books);
	store_books(end_file_users);
	store_books(end_file_loans);
}
