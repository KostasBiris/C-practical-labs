#include <stdio.h>

int main(){
  int x= 5;
  int* p= &x;
  *p=6;
  int** q= &p;
  int*** r= &q;

  printf("Size of *p in bytes : %lu\n", (unsigned long)sizeof(*p));
  printf("Address pointed to by p  : %p\n", p);
  printf("Value stored at this address : %i\n", *p);

  printf("Size of *q in bytes : %lu\n", (unsigned long)sizeof(*q));
  printf("Address pointed to by q : %p\n", q);
  printf("Value stored at this address : %i\n", *q);

  printf("Size of **q in bytes : %lu\n", (unsigned long)sizeof(**q));
  printf("Address pointed to by *q  : %p\n", *q);
  printf("Value stored at this address : %i\n", **q);

  printf("Size of **r in bytes : %lu\n", (unsigned long)sizeof(**r));
  printf("Address pointed to by **r : %p\n", *r);
  printf("Value stored at this address : %c\n", **r);

  printf("Size of ***r in bytes : %lu\n", (unsigned long)sizeof(***r));
  printf("Address pointed to by ***r  : %p\n", **r);
  printf("Value stored at this address : %i\n", ***r);

  return 0;
}
