#include<stdio.h>
int  main() {
  int num1 = 4;
  int num2 = 3;
  int *ptr1 = &num1;
  int *ptr2 = &num2;
  int sum = *ptr1 + *ptr2;
  printf("%d\n",sum );
  return 0;
}
