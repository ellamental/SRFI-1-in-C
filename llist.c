#include <stdio.h>
#include <stdlib.h>


/* Creation of a pair */

typedef struct pair {
  int car;
  struct pair *cdr;
} pair;


pair *alloc_pair(void) {
  pair *obj;

  obj = malloc(sizeof(pair));
  if (obj == NULL) {
    printf("Out of memory\n");
  }
  return obj;
}

pair *cons(int car, pair *cdr) {
  pair *obj;
  
  obj = alloc_pair();
  obj->car = car;
  obj->cdr = cdr;
  return obj;
}


/* Accessing parts of a pair */

int car(pair *list) {
  return list->car;
}


void main() {
  pair *d = cons(42, NULL);
  printf("\n%d\n", car(d));
}