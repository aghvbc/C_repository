#include <stdio.h>
#include <unistd.h>


int main (void)
{
    int result;
    result = fork();
    if (result == -1){
        fprintf(stderr, "Fork() error");
    }

    if (result == 0){
        execl("./hw", "hw", NULL);
        fprintf(stderr, "Exec() error");
        return 1;
    }
    else{
        printf("Основная программа tut!!!\n");
    }
    return 0;
}