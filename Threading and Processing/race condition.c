#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int count = 0;
void *routine(){
    for(int i = 0 ; i <1000000 ; i++){
        count++;
    }
}
int main(int argc , char* argv[]){
pthread_t t1,t2;
pthread_create(&t1,NULL,&routine,NULL);
pthread_create(&t2,NULL,&routine,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("%d\n",count);
return 0;
}