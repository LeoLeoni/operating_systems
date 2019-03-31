#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s; 

void *child(void *arg) {
    printf("child\n");
    // use semaphore here
    sem_post(&s);
    return NULL;
}

int main(int argc, char *argv[]) {
    sem_init(&s, 1, 0);
    pthread_t p;
    printf("parent: begin\n");
    pthread_create(&p, NULL, child, NULL);
    // use semaphore here
    sem_wait(&s);
    printf("parent: end\n");
    return 0;
}

