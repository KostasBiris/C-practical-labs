#include <stdio.h>

int main(){
  int a=1025, *p= &a;
  char *p0= (char *)p;

  printf("Size of integer in bytes : %lu\n", (unsigned long)sizeof(a));
  printf("Address pointed to by p  : %p\n", p);
  printf("Value stored at this address : %i\n", *p);
  printf("Address pointed by p+1 : %p\n", p+1);
  printf("Value stored at this address : %u", *(p+1));

  printf("Size of char in bytes : %lu\n", (unsigned long)sizeof(*p0));
  printf("Address pointed to by p0 : %p\n", p0);
  printf("Value stored at this address : %c\n", *p0);
  printf("Address pointed by p+1 : %p\n", p0+1);
  printf("Value stored at this address : %u", *(p0+1));

  return 0;
}
