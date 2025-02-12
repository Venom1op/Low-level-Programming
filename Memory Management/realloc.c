#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv){
    int n , *ptr;
    n = 5;
    ptr = (int*)calloc(n,sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated!!");
        exit(0);
    }
    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Not allocated!!!");
        exit(0);
    }
    else
    {
        printf("Memory allocated!!!");
        for (int i = 0; i < n; i++)
        {
            printf("Enter the Command %d : ", i);
            scanf("%d", &ptr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            printf(" the Command are : %d\n", ptr[i]);
        }
    }
    n = 8;
    printf("After Using Reallocation : \n");
    ptr = (int*)realloc(ptr,n*sizeof(int));
    for (int i = 6; i <= 8; i++)
    {
         printf("Enter the element %d : ", i);
            scanf("%d", &ptr[i]);
    }
    
    for (int i = 0; i < n; i++)
        {
            printf(" the Command to be executed are : %d\n", ptr[i]);
        }
    return 0;
}