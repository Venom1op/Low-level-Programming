#include <stdio.h>
int main() {
  int x = 100;
  int *ptr = &x;
  printf("%d\n", x);
  printf("address of poitner -> %p\n", &ptr);
  printf("address where x is stored -> %p\n", ptr);
  printf("print the value -> %d\n", *ptr);
  return 0;
}