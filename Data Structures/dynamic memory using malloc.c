<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
int main(){
  int *ptr;
  int size;
  printf("Enter the size of the array: \n");
  scanf("%d",&size);
  ptr = (int*) malloc(size* sizeof(int));
  if (ptr == NULL) {
    printf("Memory not allocated!!!\n");
    return 1;
  }
  else{
  for (int i = 0; i < size; i++) {
    printf("Enter the first element %d : \n",i+1);
    scanf("%d",&ptr[i]);
  }
  for (int i = 0; i < size; i++) {
    printf("Elements are : %d\n",ptr[i]);
  }
}
}
=======
#include<stdio.h>
#include<stdlib.h>
int main(){
  int *ptr;
  int size;
  printf("Enter the size of the array: \n");
  scanf("%d",&size);
  ptr = (int*) malloc(size* sizeof(int));
  if (ptr == NULL) {
    printf("Memory not allocated!!!\n");
    return 1;
  }
  else{
  for (int i = 0; i < size; i++) {
    printf("Enter the first element %d : \n",i+1);
    scanf("%d",&ptr[i]);
  }
  for (int i = 0; i < size; i++) {
    printf("Elements are : %d\n",ptr[i]);
  }
}
}
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
