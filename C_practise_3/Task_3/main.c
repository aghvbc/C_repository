#include <stdio.h>
#include "ship.h"

int main(){
    float speed;
    float time;
    int current_fuel_level = 9; // текущее топливо корабля

    printf("Введите скорость: ");
    scanf("%f", &speed);
    printf("Введите время: ");
    scanf("%f", &time);
    calculate_distance(speed, time);
    printf("\n");
    check_fuel(current_fuel_level);

    return 0;
}
