<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
int main(){
  int size;
  printf("Enter the size of array : \n");
  scanf("%d",&size);
  int *ptr;
  ptr = (int*)calloc(size,sizeof(int));
  if (ptr == NULL) {
    printf("Memory is not allocated\n");
    return 1;
  }
  else{
    printf("Memory allocated successfully!!\n");
    for (int i = 0; i < size; i++) {
      printf("Enter the Elements %d : \n",i+1 );
      scanf("%d",&ptr[i]);
    }
    for (int i = 0; i < size; i++) {
      printf("Elements are : %d\n",ptr[i]);
  }
  return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>
int main(){
  int size;
  printf("Enter the size of array : \n");
  scanf("%d",&size);
  int *ptr;
  ptr = (int*)calloc(size,sizeof(int));
  if (ptr == NULL) {
    printf("Memory is not allocated\n");
    return 1;
  }
  else{
    printf("Memory allocated successfully!!\n");
    for (int i = 0; i < size; i++) {
      printf("Enter the Elements %d : \n",i+1 );
      scanf("%d",&ptr[i]);
    }
    for (int i = 0; i < size; i++) {
      printf("Elements are : %d\n",ptr[i]);
  }
  return 0;
}
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}   