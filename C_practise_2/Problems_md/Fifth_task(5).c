#include <stdio.h>

union Data {
    int int_value;
    float float_value;
    char string_value[20];
};

int main() {
    int choice;
    printf("Введите выбор: ");
    scanf("%d", &choice);
    union Data data;

    if (choice == 1) {
        printf("Введите целое число: ");
        scanf("%d", &data.int_value);
        printf("Вы ввели целое число: %d\n", data.int_value);
    } else if (choice == 2) {
        printf("Введите вещественное число: ");
        scanf("%f", &data.float_value);
        printf("Вы ввели вещественное число: %.2f\n", data.float_value);
    } else if (choice == 3) {
        printf("Введите строку: ");
        scanf("%s", data.string_value);
        printf("Вы ввели строку: %s\n", data.string_value);
    }

    return 0;
}