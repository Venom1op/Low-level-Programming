<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#define BUFFER_SIZE 3
#define NUM_PRODUCER 2
#define NUM_CONSUMER 2;
int main(int argc , char* argc[]){

=======
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define Buffersize 10
pthread_mutex_t mutexBUFFER;
sem_t sem_empty, sem_full;
int buffer[Buffersize];
int count = 0;

void *producer(void *args) {
  while (1) {
    int x = rand() % 100;
    sem_wait(&sem_empty);
    pthread_mutex_lock(&mutexBUFFER);
    buffer[count] = x;
    count++;
    printf("produced : %d\n", x);
    pthread_mutex_unlock(&mutexBUFFER);
    sem_post(&sem_full);
    sleep(1);
  }
  return NULL;
}

void *consumer(void *args) {
  while (1) {
    sem_wait(&sem_full);
    pthread_mutex_lock(&mutexBUFFER);
    int y = buffer[count - 1];
    count--;
    printf("Consumed %d ", y);
    pthread_mutex_unlock(&mutexBUFFER);
    sem_post(&sem_empty);
    sleep(2);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t producedthread, consumerthread;
  pthread_mutex_init(&mutexBUFFER, NULL);
  sem_init(&sem_empty, 0, Buffersize);
  sem_init(&sem_full, 0, 0);
    // Start with no data

  pthread_create(&producedthread, NULL, &producer, NULL);
  pthread_create(&producedthread, NULL, &consumer, NULL);

  pthread_join(producedthread, NULL);
  pthread_join(consumerthread, NULL);

  pthread_mutex_destroy(&mutexBUFFER);
  sem_destroy(&sem_empty);
  sem_destroy(&sem_full);
>>>>>>> 643dfa5 (Initial commit - Low-level programming)
}