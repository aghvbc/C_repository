#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    float signal;
    printf("Введите частоту сигнала: ");
    scanf("%f", &signal);

    if (signal < 2.5 || signal > 3.5){
        printf("Связь не стабильна");
    }
    else {
        printf("Связь стабильна");
    }
    return 0;
}
