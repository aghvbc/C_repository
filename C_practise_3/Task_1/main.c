/*Вопросы для анализа:

    1.В какой секции ELF-файла будет находиться global_var?
    2.В какой секции ELF-файла будет храниться uninitialized_global_var?
    3.Где находится static_var?
    4.Где будет размещена global_point?
    5.Где будут расположены:
        local_var из функции print_message?
        static_local_var из той же функции?
    6.Где будет храниться auto_var из функции main?
    7.Где будет выделена память для dynamic_var?
    8.Где будет создана stack_point?
*/

/*Ответы:
1. global_var находится в секции .data (в .data хранятся инициализированные глобальные и локальные(статические) переменные)
2. uninitialized_global_var находится в секции .bss(в .bss хранятся неинициализированные глобальные и локальные переменные)
3. static_var будет размещена в .data
4. global_point будет размещена в .data potomuchto xz
5. 1.local_var появится только при запуске программы так что нигде.
    2. static_local_var будет находится в .data 
6. 
*/

#include <stdio.h>
#include <stdlib.h>

// Глобальные переменные
int global_var = 42; 
int uninitialized_global_var; 

// Статическая переменная
static int static_var = 10;

// Структура
struct Point {
    int x;
    int y;
};

struct Point global_point = {1, 2};

// Функция
void print_message() {
    static int static_local_var = 5;
    int local_var = 3;
    printf("Message from function!\n");
}

int main() {
    int auto_var = 100;
    int *dynamic_var = malloc(4);
    if (dynamic_var) {
        *dynamic_var = 200;
    }

    struct Point stack_point = {3, 4};

    print_message();

    free(dynamic_var); 

    return 0;
}