#include <stdio.h>

int main() {
    int weight;

    printf("Введите ваш вес:");
    scanf("%d", &weight);

    if (weight < 60 || weight > 90)
        printf("Вы не прошли отбор!");
    else 
        printf("Вы прошли отбор!");

    return 0;
}
