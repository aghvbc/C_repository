#include "ship.h"
#include <stdio.h>


int check_fuel(int fuel_level){
    if (fuel_level < 10){
        printf("Уровень топлива слишком низок, надо заправиться!");
    }
}