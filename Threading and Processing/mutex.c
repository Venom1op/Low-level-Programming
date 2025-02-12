<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int count = 0;
pthread_mutex_t lock;
void *routine(){
    for(int i = 0 ; i < 100000000 ; i++){
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main(int argc, char*argv[]){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&routine,NULL);
    pthread_create(&t2,NULL,&routine,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%d\n",count);
    pthread_mutex_destroy(&lock);
    return 0;
=======
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int count = 0;
pthread_mutex_t lock;
void *routine(){
    for(int i = 0 ; i < 100000000 ; i++){
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main(int argc, char*argv[]){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&routine,NULL);
    pthread_create(&t2,NULL,&routine,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%d\n",count);
    pthread_mutex_destroy(&lock);
    return 0;
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}