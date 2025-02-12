<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t semaphore;
void *routine(){
    printf("Thread %ld waiting to enter critical section...\n",pthread_self());
    sem_wait(&semaphore);
    printf("Thead %ld entered the critical section...!!!\n",pthread_self());
    sleep(1);
    printf("Thead %ld leaving the critical section...!!!\n",pthread_self());
    sem_post(&semaphore);
    return NULL;
}
int main(int argc, char*argv[]){
    pthread_t threads[5];
    sem_init(&semaphore,0,3);
    for(int i = 0 ; i < 5 ; i ++){Scenario:
        pthread_create(&threads[i],NULL,&routine,NULL);
    }
    for(int i = 0 ; i < 5 ; i++){
        pthread_join(threads[i],NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t semaphore;
void *routine(){
    printf("Thread %ld waiting to enter critical section...\n",pthread_self());
    sem_wait(&semaphore);
    printf("Thead %ld entered the critical section...!!!\n",pthread_self());
    sleep(1);
    printf("Thead %ld leaving the critical section...!!!\n",pthread_self());
    sem_post(&semaphore);
    return NULL;
}
int main(int argc, char*argv[]){
    pthread_t threads[5];
    sem_init(&semaphore,0,3);
    for(int i = 0 ; i < 5 ; i ++){Scenario:
        pthread_create(&threads[i],NULL,&routine,NULL);
    }
    for(int i = 0 ; i < 5 ; i++){
        pthread_join(threads[i],NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
