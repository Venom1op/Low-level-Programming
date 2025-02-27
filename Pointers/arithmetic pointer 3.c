// pointer and array relationship
#include <stdio.h>
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int *ptr = arr;
  for (int i = 0; i < 5; i++) {
    printf("%d \n", *ptr + i);
  }
  char *var1 = "anshul";
  char *var2 = "rohit";
  char *var3 = "sujit";
  char *names[3] = {var1, var2, var3};
  for (int i = 0; i < 3; i++) {
    printf("%s ", names[i]);
  }
  return 0;
}
