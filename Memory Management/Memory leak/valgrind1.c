#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *str = malloc(20);
    strcpy(str,"lode");
    printf("%s\n",str);
    //free(str);
    return 0;
}