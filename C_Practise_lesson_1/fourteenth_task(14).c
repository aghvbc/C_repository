#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int object_height;
    float height_on_moon;
    printf("Введите вес объекта: ");
    scanf("%d", &object_height);

    height_on_moon = object_height / 6.0;
    printf("Вес на луне: %.2f", height_on_moon);

    return 0;
}