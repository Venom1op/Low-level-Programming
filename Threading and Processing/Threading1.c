#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *calculations() {
    int a, b;
    printf("Enter the First Number: \n");
    scanf("%d", &a);
    printf("Enter the Second Number: \n");
    scanf("%d", &b);
    sleep(5);
    int c = a + b;
    printf("%d + %d = %d\n", a, b, c);
    return NULL; // Ensure a proper return
}
void *waitingtime() {
    sleep(7);
    printf("Executing the process....\n");
    return NULL; // Ensure a proper return
}

int main(int argc, char *argv[]) {
    pthread_t t1, t2;

    // Fixed incorrect function call syntax
    pthread_create(&t1, NULL, calculations, NULL);
    pthread_create(&t2, NULL, waitingtime, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Successfully Executed!!!\n");
    return 0;
}
