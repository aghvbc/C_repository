#include <stdio.h>
#include <math.h>

int main() {
    int N;
    printf("Введите количество космонавтов: ");
    scanf("%d", &N);

    if (N % 2 == 0){
        printf("Космонавтов можно доставить без остатка\n", N/2);
    }
    else{
        printf("Космонавтов нельзя доставить без остатка(остаток: %d)", N%2);
    }

    return 0;
}