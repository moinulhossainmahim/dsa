#include<stdio.h>
#include<stdlib.h>

struct Rectangle {
  int length;
  int breadth;
};

int main() {
  struct Rectangle p;
  struct Rectangle *r = &p;

  struct Rectangle *d;
  d = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  d->breadth = 20;
  d->length = 15;
  printf("%d", d->breadth);
  printf("%d", d->length);
  
  r->breadth = 10;
  r->length = 15;
  printf("%d", r->breadth);
  printf("%d", r->length);

  /* r.length = 10;
  r.breadth = 15;
  printf("%d\n", r.length);
  printf("%d", r.breadth); */
  return 0;
}
