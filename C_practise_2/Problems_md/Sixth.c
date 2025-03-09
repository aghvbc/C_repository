// Создайте структуру `Vehicle`, которая будет хранить информацию о транспортном средстве: 
// марка (строка), модель (строка), год выпуска (целое число), тип двигателя (перечисление: `Gasoline`, `Diesel`, `Electric`). 
// Напишите программу, которая будет выводить информацию о нескольких транспортных средствах.

#include <stdio.h>

typedef enum {
    GASOLINE,
    DIESEL,
    ELECTRIC
}EngineType;

struct Vehicle {
    char mark[50];
    char model[50];
    int year_of_release;
    EngineType enginetype;
};

int main() 
{
    int choice;
    printf("Введите количество машин: ");
    scanf("%d", &choice);   
    struct Vehicle vehicle[choice];

    for(int i = 0; i < choice; i++)
    {
        printf("Введите марку машины: ");
        scanf("%s", vehicle[i].mark);
        printf("Введите модель машины: ");
        scanf("%s", vehicle[i].model);
        printf("Введите год выпуска: ");
        scanf("%d", &vehicle[i].year_of_release);
        printf("Выберите тип двигателя (0 - Gasoline, 1 - Diesel, 2 - Electric): ");
        int engine_choice;
        scanf("%d", &engine_choice);
        if (engine_choice >= 0 && engine_choice <= 2) {
            vehicle[i].enginetype = (EngineType)engine_choice;
        } else {
            printf("Ошибка: Неверный ввод типа двигателя. Устанавливаем Gasoline по умолчанию.\n");
            vehicle[i].enginetype = GASOLINE;
        }
       
    }
    printf("\n");
    for(int i = 0; i < choice; i++)
    {
        printf("Марка машины: %s %s\n", vehicle[i].mark, vehicle[i].model);
        printf("Год выпуска: %d\n",vehicle[i].year_of_release);
        printf("Тип двигателя: \n");
        switch (vehicle[i].enginetype)
        {
            case GASOLINE: 
                printf("Gasoline\n"); 
                break;
            case DIESEL: 
                printf("Diesel\n"); 
                break;
            case ELECTRIC: 
                printf("Electric\n"); 
                break;
            default:
                printf("XZ\n");
        }
        printf("\n");
    }

    return 0;
}
