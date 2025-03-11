/*3. Реализация примитивного калькулятора
Описание:
Напишите программу, которая принимает от пользователя строку вида "12 + 34" и вычисляет результат. 
Поддерживаемые операции: +, -, *, /.
Используйте указатель на функцию для выбора операции.

🔹 Дополнительно:

Добавить обработку ошибок (деление на 0, некорректный ввод).
Реализовать поддержку вещественных чисел (float вместо int).

addition
subtraction
division
multiplication

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float addition(float a, float b){
    return a + b;
}

float subtraction(float a, float b){
    return a - b;

}

float division(float a, float b){
    if (b != 0){return a / b;}else{printf("Нельзя делить на ноль!\n");return -1;}

}

float multiplication(float a, float b){
    return a * b;

}

typedef struct Function{
    float (*func)(float, float);
    char *name;
} function;

int main(){
    float a,b;
    char sym;
    int res;
    char *lst[] = {"+", "-", "*", "/"};
    char str[100];
    fgets(str, 100, stdin);
    
    function functions[] =
    {
        {addition, "+"},
        {subtraction, "-"},
        {division, "/"},
        {multiplication, "*"}

    };

    if (sscanf(str, "%f %c %f", &a, &sym, &b) != 3){
        printf("Неправильный ввод");
        return 1;
    }

    int n = sizeof(functions) / sizeof(functions[0]);

    for (int i = 0; i < n; i++) {
        char *pos = strchr(str, functions[i].name[0]); 
        if (pos != NULL) {
            printf("Оператор %c найден на позиции: %ld\n", *pos, pos - str);
            printf("Результат: %.2f\n", functions[i].func(a, b));
        }
        
    }
    return 0;
}