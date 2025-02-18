// Создайте структуру `Vehicle`, которая будет хранить информацию о транспортном средстве: 
// марка (строка), модель (строка), год выпуска (целое число), тип двигателя (перечисление: `Gasoline`, `Diesel`, `Electric`). 
// Напишите программу, которая будет выводить информацию о нескольких транспортных средствах.
//
#include <stdio.h>

struct Vehicle {
    char mark[50];
    char model[50];
    int year_of_release;
    char type_of_engine[50];
};

int main() {
    int choice;
    printf("Введите количество машин: ");
    scanf("%d", &choice);   
    struct Vehicle vehicle[choice];

    for(int i = 0; i < choice; i++){
        printf("Введите марку машины: ");
        scanf("%s", &vehicle[i].mark);
        printf("Введите модель машины: ");
        scanf("%s", &vehicle[i].model);
        printf("Введите год выпуска: ");
        scanf("%d", &vehicle[i].year_of_release);
        printf("Введите тип двигателя: ");
        scanf("%s", &vehicle[i].type_of_engine);
    }
    printf("\n");
    for(int i = 0; i < choice; i++){
        printf("Марка машины: %s %s\n", vehicle[i].mark, vehicle[i].model);
        printf("Год выпуска: %d\n",vehicle[i].year_of_release);
        printf("Тип двигателя: %s\n",vehicle[i].type_of_engine);
    }


    return 0;
}