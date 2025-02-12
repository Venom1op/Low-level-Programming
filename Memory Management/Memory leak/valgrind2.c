#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *str = malloc(30);
    strcpy(str,"I am anshul\n");
    printf("%s",str);
    FILE *ptr = fopen("anshul.txt","w");
    fprintf(ptr,"%s","we are legions\n");
    fclose(ptr);
    free(str);
    return 0; 
}