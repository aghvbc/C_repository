/*1. Простейшая командная обработка (разминка)

Описание:  
Напишите программу, которая принимает команды от пользователя и вызывает соответствующие функции. 
Например:  

- `"upper"` — преобразует строку в верхний регистр  
- `"lower"` — преобразует строку в нижний регистр  
- `"reverse"` — переворачивает строку  
- `"exit"` — завершает программу  

Используйте массив структур, содержащих имя команды и указатель на функцию.

🔹 **Дополнительно:** Можно предложить вариант с указателями на указатели (`char**`), если студенты уже это проходили.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void to_upper(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str){
    for(int i = 0; str[i]; i++){
       str[i] = tolower(str[i]);
    }
}

void reverse_str(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void exit_programm(){
    printf("Завершение программы");
    exit(0);
}

struct function{
    char *name;
    void (*func)(char*);
};

int main() {
    char str[100] = "Hello, wrld!";
    char str_r[100];
    struct function functions[] = 
    { 
        {"upper", to_upper},
        {"lower", to_lower},
        {"reverse", reverse_str},
        {"exit", exit_programm}

    };

    int n = sizeof(functions) / sizeof(functions[0]); 

    while (1) {
        printf("Введите команду (upper, lower, reverse, exit): ");
        scanf("%s", str_r);

        for (int i = 0; i < n; i++) {
            if (strcmp(str_r, functions[i].name) == 0) {
                if (strcmp(str_r, "exit") == 0) {
                    functions[i].func(str); 
                } else {
                    functions[i].func(str);
                    printf("Результат: %s\n", str);
                }
                break;
            }
        }

    
        if (strcmp(str_r, functions[n-1].name) != 0 && strcmp(str_r, functions[n-2].name) != 0 && strcmp(str_r, functions[n-3].name) != 0 && strcmp(str_r, functions[n-4].name) != 0) {
            printf("Неизвестная команда: %s\n", str_r);
        }
    }

    return 0;
}