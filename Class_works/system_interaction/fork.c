#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    fork();
    printf("Hello мир\n");
    // system("sleep 15&");
    // sleep(15);
    return 0;
}