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

pair *cdr(pair *list) {
  return list->cdr;
}


int emptyp(pair *list) {
  return list == NULL ? 1 : 0;
}


int length(pair *list) {
  pair *n = list;
  int l = 0;
  while (!emptyp(n)) {
    l += 1;
    n = cdr(n);
  }
  return l;
}

/* Returns the node (not car)
 * Also segfaults when idx > length(list) */
pair *index(pair *list, int idx) {
  pair *n = list;
  while (idx != 0) {
    idx -= 1;
    n = cdr(n);
  }
  return n;
}


void main() {
  // Test construction of a pair
  
  // Test car
  pair *a = cons(42, NULL);
  printf("\nExpected: 42 ==> %d\n", car(a));
  
  // Test cdr
  pair *b = cons(42, cons(43, NULL));
  pair *c = cdr(b);
  printf("\nExpected: 43 ==> %d\n", car(c));
  
  // Test empty
  pair *d = NULL;
  printf("\nExpected: 1 ==> %d\n", emptyp(d));
  
  // Test length
  pair *e = cons(42, cons(43, cons(44, NULL)));
  printf("\nExpected: 3 ==> %d\n", length(e));
  
  // Test index
  pair *f = cons(42, cons(43, cons(44, NULL)));
  printf("\nExpected: 43 ==> %d\n", car(index(f, 1)));
}






