#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int angle;
    printf("Введите угол: ");
    scanf("%d", &angle);

    if (angle >= -180 && angle <= 180){
        printf("Угол входит в допустимый диапазон!\n");
    }
    else{
        printf("Угол не входит в допустимый диапазон");
    }

    return 0;
}