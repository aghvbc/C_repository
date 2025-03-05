/*2. Динамическое редактирование строки с функцией-обработчиком
Описание:
Напишите программу, в которой пользователь вводит строку, а затем выбирает одну из функций обработки:

Удаление пробелов
Замена всех гласных на *
Инвертирование регистра символов
Функция-обработчик передаётся указателем на функцию, а память для строки выделяется динамически.

🔹 Дополнительно: Дайте возможность пользователю выбрать любую комбинацию этих функций и применить их последовательно.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void space_deleter(){

}

void vowels_changer(){

}

void invert_case(){
    
}

struct function{
    char name[50];
    void (*func)(char*);
};

int main(){
    struct function functions[] = {
        {"delete_spaces", space_deleter},
        {"change_vowels", vowels_changer},
        {"invert_register", invert_case}
    };

    int n = sizeof(functions) / sizeof(functions[0]);

    int len_str = 100;
    printf("Введите строку: ");
    char *str = malloc(len_str);
    fgets(str, len_str, stdin);
    printf("Строка: %s", str);
    printf("Введите функцию: ");
    int len_name_func = 100;
    char *func_name = malloc(len_name_func);
    fgets(func_name, len_name_func, stdin);

    for (int i = 0; i < n; i++){
        if (strcmp(func_name, functions[i].name) == 0){
            functions[i].func(str);
        }
        
    }
    free(str); 

    return 0;
}