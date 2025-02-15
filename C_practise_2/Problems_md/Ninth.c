// Создайте структуру `Weather`, которая будет хранить информацию о погоде: 
// температура (вещественное число), влажность (вещественное число), состояние (перечисление: `Sunny`, `Cloudy`, `Rainy`). 
// Напишите программу, которая будет выводить данные о текущей погоде.
// ```
// **Ввод:**  

//    ```bash
//    30.5 70.2 Sunny
//    ```

//    **Вывод:**  

//    ```bash
//    Temperature: 30.5°C
//    Humidity: 70.2%
//    Condition: Sunny
// ```

#include <stdio.h>
#include <string.h>

struct Weather {
    float temperature;
    float humidity;
    char condition[50];
};

int main() {
    struct Weather grades;

    printf("Введите температуру(в градусах): ");
    scanf("%f", &grades.temperature);
    printf("Введите влажность(в процентах): ");
    scanf("%f", &grades.humidity);
    printf("Введите состояние: ");
    scanf("%s", &grades.condition);

    printf("\n");

    printf("Температура: %.2f\n", grades.temperature);
    printf("Влажность: %.2f\n", grades.humidity);
    printf("Состояние: %s\n", grades.condition);

    return 0;
}
