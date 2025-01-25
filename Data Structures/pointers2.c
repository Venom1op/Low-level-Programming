#include<stdio.h>
#include<stdlib.h>
int main(){
char *names[] = {"anshul","venom","charlie"};
char **ptr = names;
printf("%s\n",*(ptr));
}
