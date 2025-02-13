#include <stdio.h>
#include <math.h>

int main() {
    float oxigen;
    printf("Введите процентов кислорода осталось: ");
    scanf("%f", &oxigen);

    if (oxigen < 15){
        printf("Уровень кислорода слишком низок, необходимо включить аварийную систему!\n");
    }
    else{
        printf("Уровень кислорода в норме");
    }

    return 0;
}