#include <stdio.h>
int main() {
  int arr[] = {10, 20, 40, 50};
  int *ptr1 = &arr[1];
  int *ptr3 = &arr[3];
  printf("%p\n",ptr1);
  printf("%p\n",ptr3);
  printf("%d\n",*ptr3);
  printf("%d\n", ptr3 - ptr1); // difference in array index
  return 0;
}