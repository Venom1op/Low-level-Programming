<<<<<<< HEAD
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char*argv[]){
    int pid = fork();
    int x = 4;
    if(pid !=0){
        x *=x;   
    }
    printf("Hello from Processes...%d\n",getpid());
   if(pid == 0){
        x++;
   }
   printf("%d\n",x);
    return 0;
=======
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char*argv[]){
    int pid = fork();
    int x = 4;
    if(pid !=0){
        x *=x;   
    }
    printf("Hello from Processes...%d\n",getpid());
   if(pid == 0){
        x++;
   }
   printf("%d\n",x);
    return 0;
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}