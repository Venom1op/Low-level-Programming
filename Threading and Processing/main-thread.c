<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void*routine(){
    printf("Hello from Threads...%d\n",getpid());
}
int main(int argc,char*argv[]){
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,&routine,NULL)){
        return 1;
    }
    if(pthread_create(&t2,NULL,&routine,NULL)){
        return 2;
    }
    if(pthread_join(t1,NULL)){
        return 3;
    }
    if(pthread_join(t2,NULL)){
        return 4;
    }
    return 0;
=======
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void*routine(){
    printf("Hello from Threads...%d\n",getpid());
}
int main(int argc,char*argv[]){
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,&routine,NULL)){
        return 1;
    }
    if(pthread_create(&t2,NULL,&routine,NULL)){
        return 2;
    }
    if(pthread_join(t1,NULL)){
        return 3;
    }
    if(pthread_join(t2,NULL)){
        return 4;
    }
    return 0;
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}