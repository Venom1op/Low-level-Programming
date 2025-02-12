<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
int main(){
    int a;
    printf("Enter the value of a : \n");
    scanf("%d",&a);
    int *b = &a;
    int **c = &b;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",*b);
    printf("%d\n",c);
    printf("%d\n",*c);
    printf("%d\n",**c);
    return 0;
=======
#include<stdio.h>
#include<stdlib.h>
int main(){
    int a;
    printf("Enter the value of a : \n");
    scanf("%d",&a);
    int *b = &a;
    int **c = &b;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",*b);
    printf("%d\n",c);
    printf("%d\n",*c);
    printf("%d\n",**c);
    return 0;
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}