#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "users.h"

static int number_users=0;				// the number of users in the library
int userId_counter;			// a counter for creating unique user IDs
static User* all_users[MaxNumberUsers];
static User_Array users_array;

//loads the database of users from the specified file
//the file must have been generated by a previous call to store_users()
//returns 0 if users were loaded correctly, or an error code otherwise
int load_users(FILE *file){
  users_array.length=0;
  int buff=0;
  char b;
  char buff1[512];
  User* loaded_user;
  loaded_user= (User*)malloc(sizeof(User));
  char *token;
  int i=0;

  for(b=getc(file);b!=EOF;b=getc(file)){
    if(b=='\n'){
      i++;
    }
  }
  rewind(file);

  number_users=i-1;
  users_array.array= calloc(number_users,sizeof(User));
  while (fgets(buff1, 512, file)) {

    if(buff==0){
      buff++;
      continue;
    }
    //First Name
    token= strtok(buff1,",");
    loaded_user->first_name=(char*){malloc(sizeof(char)*strlen(token))};
    strcpy(loaded_user->first_name,token);

    //Last Name
    token= strtok(NULL,",");
    loaded_user->last_name=(char*)malloc(sizeof(char)*strlen(token));
    strcpy(loaded_user->last_name,token);

    //User Type
    token= strtok(NULL,",");
    loaded_user->type= atoi(token);

    //Email
    token= strtok(NULL,",");
    loaded_user->email=(char*)malloc(sizeof(char)*strlen(token));
    strcpy(loaded_user->email,token);

    //Password
    token= strtok(NULL,",");
    loaded_user->password=(char*)malloc(sizeof(char)*strlen(token));
    strcpy(loaded_user->password,token);


    users_array.array[users_array.length]= *loaded_user;
    users_array.length++;
    }

  users_array.array= (User*) users_array.array;


  return 0;
}

// returns a new user id
// first time returns 1
// if no more IDs can be generated returns -1
int newUserId (){
  if (userId_counter < MaxUserID)
    return userId_counter++;

  return -1;
}

// adds a user (pointer to the user) to the users_array
// if the array is full and cannot accept any more accounts the function returns 1
// otherwise it returns 0.
int add_user(User u){
  if(users_array.length==MaxNumberUsers)
    return 1;

    users_array.array[users_array.length]= u;
    users_array.length++;
    return 0;
}

//Registers a new user to the library and returns 0 if successful.
/*int register_user(unsigned int uid, char* fn,char* ln, unsigned int t, char* e, char* p){
  User* u= (User *)malloc(sizeof(User));
  u->first_name=(char*)malloc(sizeof(u->first_name)*sizeof(char));
  u->last_name=(char*)malloc(sizeof(u->last_name)*(sizeof(char)));
  u->email=(char*)malloc(sizeof(u->email)*(sizeof(char)));
  u->password=(char*)malloc(sizeof(u->password)*(sizeof(char)));


  u->userId=uid;
  strcpy(u->first_name,fn);
  strcpy(u->last_name,ln);
  u->type=t;
  strcpy(u->email,e);
  strcpy(u->password,p);
  u->books_borrowed.length=0;
  u->numBooksReturned=0;

  //add_user(*u);
  return 0;
}*/


//removes a user from the library
//returns 0 if the user could be successfully removed, or an error code otherwise.
int remove_user(User u){
  int length =users_array.length;
  int index=0;

  for(int i=0;i<length;i++){
    if((users_array.array[i].userId== u.userId)&&(strcmp(users_array.array[i].first_name,u.first_name)==0)
      && (strcmp(users_array.array[i].last_name,u.last_name)==0)
      && (users_array.array[i].type== u.type) &&(strcmp(users_array.array[i].email,u.email)==0)
      &&(strcmp(users_array.array[i].password, u.password)==0)){

      index=i;
      break;
     }
  }
  for(int j= index; j< length-2; j++){
    users_array.array[j]=users_array.array[j+1];

  users_array.length--;
}
  return 0;
}

//Checks if the provided user email and password corresponds
//to an existing user in the user database and returns a pointer to a user if correct.
const User* login(char* e, char* p){

  for(int i=0;i<users_array.length;i++){
    if(strcmp(users_array.array[i].email,e)==0
    && strcmp(users_array.array[i].password,p)==0){
      return &users_array.array[i];
    }
  }
  printf("Invalid Email or Password");;
}

//saves the database of users in the specified file
//returns 0 if users were stored correctly, or an error code otherwise
int store_users(FILE *file){
  User user_temp;
  User* array_temp= (User*)malloc(sizeof(User));
  array_temp=users_array.array;

  if(file==NULL){
    return -1;
  }

  for(int i=1; i<users_array.length;i++){
    user_temp= *(array_temp+i);
    fprintf(file,"%d,%s,%s,%d,%s,%s,%d\n",user_temp.userId, user_temp.first_name, user_temp.last_name, user_temp.type, user_temp.email,
            user_temp.password,user_temp.books_borrowed.length);
  }
  return 0;
}
/*
int main(){
  FILE* file1= fopen("../users.csv","r");
  FILE* file2= fopen("../test_file.csv","w");

  User user1;
  user1.userId= newUserId();
  user1.first_name = "Jacob";
  user1.last_name="Frye";
  user1.type=1;
  user1.email="jacob14frye@mail.com";
  user1.password="wef3524rf";
  user1.books_borrowed.length=0;
  user1.numBooksReturned=0;

  load_users(file1);

  User user2;
  user2.userId= newUserId();
  user2.first_name = "George";
  user2.last_name="Hamlin";
  user2.type=1;
  user2.email="geoham@inlook.com";
  user2.password="justpl4int3xt";
  user2.books_borrowed.length=3;

//  add_user(user1);
  remove_user(user2);
  store_users(file2);

  return 0;
}
*/
