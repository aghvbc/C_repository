#include <stdio.h>
#include <math.h>


int main() {
    float M;
    float speed;
    printf("Введите сколько МегаБайт данных: ");
    scanf("%f", &M);

    speed = M*(1024*8);
    printf("Скорость в Кбит/с: %.2f", speed);
    return 0;
}