typedef struct vpair {
  void *car;
  struct vpair *cdr;
} vpair;

vpair *alloc_vpair(void) {
  vpair *obj;
  
  obj = malloc(sizeof(vpair));
  if (obj == NULL) {
    printf("Out of memory\n");
  }
  return obj;
}

vpair *vcons(void *car, vpair *cdr) {
  vpair *obj;
  
  obj = alloc_vpair();
  obj->car = car;
  obj->cdr = cdr;
  return obj;
}

void main() {
  
  int j = 42;
  void *p = &j;  // Shouldn't take an address from a local var, should malloc space for int.

  vpair *k = vcons(p, NULL);
  printf("\n%d\n", *(int *)k->car);
}