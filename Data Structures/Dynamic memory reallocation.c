#include<stdlib.h>
#include<stdio.h>
int main(){
  int size = 5;
//
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

  printf("\n");
  size = 10;
  int*temp = ptr;
  ptr = realloc(ptr,size*sizeof(int));
  if (!ptr) {
    printf("memory reallocation failed!!\n");
    ptr = temp;
  }
  else{
    printf("memory reallocated successfully!!\n");
  }
  for (int i = 5; i < size; i++) {
    printf("Enter the Elements %d : \n",i+1 );
    scanf("%d",&ptr[i]);
  }
  for (int i = 0; i < size; i++) {
    printf("Elements are : %d\n",ptr[i]);
}
  return 0;
}
}
