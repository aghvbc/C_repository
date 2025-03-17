#include <stdio.h>
#include <pthread.h>


void* some_func(void* arg){
    printf("Hello, world!\n");
    return NULL;
}

int main(){
    pthread_t thread;
    int result;
    result = pthread_create(&thread, NULL, some_func, NULL);
    if (result != 0){
        fprintf(stderr, "pthread_create() error");
        return 1;
    }

    fprintf(stderr, "GoodBye World\n");
    return 0;
}