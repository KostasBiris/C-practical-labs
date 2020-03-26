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

	printf("\t\t\t###########################################################################");
	printf("\n\t\t\t############      			Library System Initiated   		   		 ############");
	printf("\n\t\t\t###########################################################################");

	do {
		printf("\n\t\t\t---------------------------------------------------------------------------\n");
		char * users_choice = command("\nWhat would you like to do?:\n1) Login\n2) Register\n3) Quit\n\nChoice: \n\n\n");
		printf("\n\t\t\t----------------------------------------------------------------------------");
		choice = atoi(users_choice);
		free(users_choice);

		switch (choice) {


			case 1:
				printf("Email: ");
				scanf("%s\n",temp_email);

				printf("Password: ");
				scanf("%s\n",temp_password);

				current_user=login(temp_email,temp_password);

				if(current_user!=NULL);
					break;

			case 2:
				register_user();
				break;

			case 3:
				printf("Have a nice Day!");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}

	} while (choice!=3);

//========================================={Start: Normal User}==================================================
	if(current_user->type==1){

		do {
			printf("\n\t\t\t---------------------------------------------------------------------------\n");
			char * users_choice = command("\nWhat would you like to do now?:\n1) Borrow Book\n2) Return Book\n3) Logout\n\nChoice: \n\n\n");
			printf("\n\t\t\t----------------------------------------------------------------------------");
			choice = atoi(users_choice);
			free(users_choice);

			switch (choice) {
//----------------------------------------------------{Start:Borrow Book}----------------------------------------------------------
				case 1:
				do {
					printf("\n\t\t\t---------------------------------------------------------------------------\n");
					char * users_choice = command("\n1) Find Book by Title\n2) Find Book by Author\n3) Find Book by Year\n4)Go Back\n\nChoice: \n\n\n");
					printf("\n\t\t\t----------------------------------------------------------------------------");
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
						printf("Book's Author: ");
						scanf("%s\n", author);

						temp_array=find_book_by_author(author);

						if(temp_array.length==0){
							printf("Book with author <<%s>> was Not found",author);
						}

						else{
							printf("Book with title <<%s>> was found\nDo you want to borrow it?",title);
							users_choice2= command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
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
						printf("Book's Year: ");
						scanf("%d\n", year);

						temp_array=find_book_by_year(year);

						if(temp_array.length==0){
							printf("Book from <<%d>> was Not found",year);
						}

						else{
							printf("Book from <<%d>> was found\nDo you want to borrow it?",year);
							users_choice2 = command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
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
//----------------------------------------------------{End:Borrow Book}----------------------------------------------------------

//--------------------------------------------------{Start:Return Book}----------------------------------------------------------
				case 2:

					do{
						char * users_choice2 = command("\n1) Enter Book details\n2) Go Back\n\nChoice: \n\n\n");
						printf("\n\t\t\t----------------------------------------------------------------------------");
						int choice2 = atoi(users_choice2);
						free(users_choice2);


						switch (choice2){
							case 1:
								printf("Please Enter the details of the Book you want to return.");
								temp_book.title=command("Book's Title: ");
								temp_book.authors=command("Book's Author: ");
								temp_book.year=atoi(command("Book's Year: "));
								temp_book.copies=1;

								book_was_returned=return_book(temp_book,*current_user);

								if(book_was_returned==0){
									printf("Book was returned successfully.");
									break;
								}

								else if(book_was_returned==1){
									printf("There is no such Book in your Borrowed Books list.");
									break;
								}

								else{
									printf("Something Unexpected Happened.");
									break;
								}
							case 2:
								break;

							default:
								printf("Sorry,that doesn't seem to be an option.");

					}while(choice2!=2);

//---------------------------------------------------{End:Return Book}------------------------------------------------------------

//--------------------------------------------------{Start: Logout}---------------------------------------------------------------
				case 3:
					printf("Have a nice Day!");
					break;
//--------------------------------------------------{End: Logout}---------------------------------------------------------------
				default:
					printf("Sorry, that doesn't seem to be an option\n");

			}while(choice2!=2);

//===================================={End: Normal User}===============================================================

//===================================={Start: Librarian}================================================================
if(current_user->type==2){

	do {
		printf("\n\t\t\t---------------------------------------------------------------------------\n");
		char * users_choice = command("\nWhat would you like to do now?:\n1) Borrow Book\n2) Return Book\n3)Add Book\n4)Remove Book\n5) Logout\n\nChoice: \n\n\n");
		printf("\n\t\t\t----------------------------------------------------------------------------");
		choice = atoi(users_choice);
		free(users_choice);

		switch (choice) {
//----------------------------------------------------{Start:Borrow Book}----------------------------------------------------------
			case 1:
			do {
				printf("\n\t\t\t---------------------------------------------------------------------------\n");
				char * users_choice = command("\n1) Find Book by Title\n2) Find Book by Author\n3) Find Book by Year\n4)Go Back\n\nChoice: \n\n\n");
				printf("\n\t\t\t----------------------------------------------------------------------------");
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
							printf("Book with title <<%s>> was found\nDo you want to borrow it?",title);
							users_choice2= command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
							choice = atoi(users_choice);
							free(users_choice2);

							if(choice==1){
								printf("Book was returned successfully.");
								book_was_borrowed=borrow_book(temp_array.array[0],current_user);
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
						printf("Book with title <<%s>> was found\nDo you want to borrow it?",title);
						users_choice2= command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
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
					printf("Book's Year: ");
					scanf("%d\n", year);

					temp_array=find_book_by_year(year);

					if(temp_array.length==0){
						printf("Book from <<%d>> was Not found",year);
					}

					else{
						printf("Book from <<%d>> was found\nDo you want to borrow it?",year);
						users_choice2 = command("\n1) Yes\n2) No\n\nChoice: \n\n\n");
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
			} while (choice!=4);
//----------------------------------------------------{End:Borrow Book}----------------------------------------------------------

//--------------------------------------------------{Start:Return Book}----------------------------------------------------------
			case 2:

				do{
					char * users_choice2 = command("\n1) Enter Book details\n2) Go Back\n\nChoice: \n\n\n");
					printf("\n\t\t\t----------------------------------------------------------------------------");
					choice2 = atoi(users_choice2);
					free(users_choice2);


					switch (choice2){
						case 1:
							printf("Please Enter the details of the Book you want to return.");
							temp_book.title=command("Book's Title: ");
							temp_book.authors=command("Book's Author: ");
							temp_book.year=atoi(command("Book's Year: "));
							temp_book.copies=1;

							book_was_returned=return_book(temp_book);

							if(book_was_returned==0){
								printf("Book was returned successfully.");
								break;
							}

							else if(book_was_returned==1){
								printf("There is no such Book in your Borrowed Books list.");
								break;
							}

							else{
								printf("Something Unexpected Happened.");
								break;
							}
						case 2:
							break;

				}while(choice2!=2);

				if(return_book(temp_book,current_user)==0)
					break;
//---------------------------------------------------{End:Return Book}------------------------------------------------------------

//--------------------------------------------------{Start: Logout}---------------------------------------------------------------
			case 3:
				printf("Have a nice Day!");
				break;
//--------------------------------------------------{End: Logout}---------------------------------------------------------------
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}










		}while (choice!=3);
		}

	return;
}
/*
static void search_for_customer_interface() {

	char *name = command("Name of the customer: ");

	current_customer = customer_find_by_name(name);
	current_order = 0; //reset order

	if (current_customer)
		printf("Customer %s found\n", current_customer->name);
	else
		printf("Name not found\n");


	free(name); //very important!
}
*/
