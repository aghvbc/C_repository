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

void space_deleter(char *str){
    char *src = str, *dst = str;
    
    while (*src != '\0') {
        if (!isspace((unsigned char)*src)) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

void vowels_changer(char *str) {
    const char *vowels_lst[] = {"а", "е", "и", "о", "у", "a", "e", "i", "o", "u"};
    int count = sizeof(vowels_lst) / sizeof(vowels_lst[0]);
    char chr_to_chng = '*';
    
    while (*str != '\0') {
        for (int i = 0; i < count; i++ ){
            if (*str == vowels_lst[i][0]) {
                *str = chr_to_chng;
                break;  
            }
        }
        str++;
    }
}

void invert_case(char *str){
    while (*str != '\0') {
        if (islower(*str)) 
        {
            *str = toupper(*str);
        } 
        else if (isupper(*str)) 
        {
            *str = tolower(*str);
        }
        str++;
    }
}
struct function{
    char name[50];
    void (*func)(char*);
};

int main(){
    struct function functions[] = {
        {"delete", space_deleter},
        {"change", vowels_changer},
        {"invert", invert_case}
    };

    int n = sizeof(functions) / sizeof(functions[0]);

    int len_str = 100;
    printf("Введите строку: ");
    char *str = malloc(len_str);
    fgets(str, len_str, stdin);

    printf("Введите функцию: ");
    int len_name_func = 60;
    char *func_name = malloc(len_name_func);
    fgets(func_name, len_name_func, stdin);
    func_name[strcspn(func_name, "\n")] = '\0';

    for (int i = 0; i < n; i++){
        if (strcmp(func_name, functions[i].name) == 0){
            functions[i].func(str);
            printf("Результат: %s\n", str);
        }
        
    }

    free(str); 
    free(func_name);


    return 0;
}