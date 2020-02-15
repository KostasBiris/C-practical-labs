#include <stdio.h>

int main(){
  int p, x=p+1, y=p+2, *pointer= &p;
  float f, *pointerf= &f;
  char c, *pointerc= &c;

  printf("Address of p : %p \n", pointer);
  printf("Size of integer variable p : %lu\n", (unsigned long)sizeof(p));
  printf("Address of p+1 : %p\n", &x);
  printf("Address of p+2 : %p\n", &y);


  return 0;
}
