/*Задача 1. Анализ названий космических кораблей
Условие:
В базе данных космического агентства хранятся названия кораблей. Нужно найти первый корабль, название которого начинается на "SS", и вывести его имя.

Входные данные:
Массив строк с названиями кораблей (не более 100 кораблей, длина названия ≤ 50 символов).

Выходные данные:
Название первого корабля, начинающегося на "SS" (без учёта регистра), или "Не найдено", если таких нет.

Подсказка: Используйте strncmp для сравнения первых символов.*/

#include <stdio.h>
#include <string.h>

int main(){
    char ships[100][50] = {"Voin", "Ssilovik","SSolo",  "Battle_ship1", "SSdaite"};
    size_t arr_leng = sizeof(ships) / sizeof(ships[0]);
    int count = 0;
    for (int i = 0; i < arr_leng; i++){
        if (strncmp(ships[i], "SS", 2) == 0){
            printf("%s", ships[i]);
            count ++;
            break;
        }
        else if(strncmp(ships[i], "ss", 2) == 0){
            printf("%s", ships[i]);
            count ++;
            break;
        }
    }
    if (count == 0){
        printf("Не найдено");
    }
    return 0;
}