#include <stdio.h>

// Ожидаемый старт миссии

// Дата старта миссии задана в виде целого числа (например, 20250210 – 10 февраля 2025 года). Напишите программу, которая принимает дату от пользователя и проверяет, находится ли она в будущем относительно текущей даты.


// Кирилл, эту задачу ты решил (если решил) , то супер сложно. Задача состоит из ТРЁХ-ПЯТИ строк
int main() {
    int date = 20250210;
    int day = date % 100;
    int month = (date / 100 )% 100;
    int year = ((date / 100 ) / 100) % 10000;
    int input_date;
    printf("Год: %d\nМесяц: %02d\nДень: %d\n", year, month, day);

    printf("Введите текущую дату: ");
    scanf("%d", &input_date);
    printf("Вы ввели: %d\n", input_date);

    int input_day = input_date % 100;
    int input_month = (input_date / 100 )% 100;
    int input_year = ((input_date / 100 ) / 100) % 10000;

    if (input_year > year){
        printf("Вы находитесь в будующем!");
        return 0;
    }
    else if (input_year < year){
        printf("Вы вообще в прошлом!");
        return 0;
    }
    else if (input_year== year){
        if (input_month > month){
            printf("Вы находитесь в будующем!");
            return 0;
        }
        else if (input_month < month){
            printf("Вы в прошлом!");
            return 0;

        }
        else if (input_month == month){
            if (input_day > day){
                printf("Вы находитесь в будующем!");
                return 0;
            }
            else if (input_day < day){
                printf("Вы в прошлом!");
                return 0;
            }
            else if (input_day == day){
                printf("Вы ввели дату начала миссии!");
                return 0;
            }
        }


    }

    return 0;
}

