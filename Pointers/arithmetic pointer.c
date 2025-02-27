#include<stdio.h>
int main(){
    int x = 120;
    int*ptr = &x;
    printf("before increment of ptr -> %p\n",ptr);
    ptr--;
    printf("after increment of ptr -> %p\n",++ptr);
    printf("after increment of ptr -> %p\n",ptr++);
    printf("after increment of ptr -> %p\n",++ptr);
    return 0;
}