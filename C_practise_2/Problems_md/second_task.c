#include <stdio.h>

struct Item {
    char name[50];
    int count;
    float cost;
};

int main() {
    int n;
    printf("Введите число товаров: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++){
        struct  Item item;
        scanf("%s", item.name);
        scanf("%d", &item.count);
        scanf("%f", &item.cost);

        printf("Название: %s\n", item.name);
        printf("количество: %d\n", item.count);
        printf("цена: %.1f\n", item.cost);
    }

    return 0;
}

/*#include <stdio.h>

#define MAX_ITEMS 100 // Максимальное количество товаров

struct Item {
    char name[50];
    int count;
    float cost;
};

int main() {
    struct Item items[MAX_ITEMS]; // Массив для хранения товаров
    int n;

    printf("Введите количество товаров: ");
    scanf("%d", &n);

    // Проверка на превышение максимального количества товаров
    if (n > MAX_ITEMS) {
        printf("Ошибка: максимальное количество товаров - %d\n", MAX_ITEMS);
        return 1; // Завершение программы с ошибкой
    }

    // Ввод данных о товарах
    for (int i = 0; i < n; i++) {
        printf("Введите название товара %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Введите количество товара %d: ", i + 1);
        scanf("%d", &items[i].count);
        printf("Введите цену товара %d: ", i + 1);
        scanf("%f", &items[i].cost);
    }

    // Вывод отчета о товарах
    printf("\nОтчет о товарах:\n");
    printf("%-20s %-10s %-10s\n", "Название", "Количество", "Цена");
    printf("-----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-10.2f\n", items[i].name, items[i].count, items[i].cost);
    }

    return 0;
}
*/