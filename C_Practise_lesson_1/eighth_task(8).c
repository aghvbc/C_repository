#include <stdio.h>
#include <math.h>

int main() {
    int N;
    printf("Введите сколько килограмм груза: ");
    scanf("%d", &N);

    if (N % 4 == 0){
        int B = N / 4;
        printf("Да, груз может быть равномерно распределён на 4 отсека\n");
        printf("В каждом отсеке будет: %d кг груза", B);
    }
    else{
        printf("Груз нельзя равномерно распределить на 4 отсека");
    }

    return 0;
}