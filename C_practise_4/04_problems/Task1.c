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

void upper(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
}

void lower(char *str){
    for(int i = 0; str[i]; i++){
       str[i] = tolower(str[i]);
    }
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// void exit(){
//     printf("Завершение программы");
// }

struct function{
    char *name;
    void (*func)(char*);
};

int main() {
    char str[100] = "Hello, wrld!";
    struct function functions[] = 
    { 
        {"upper", upper},
        {"lower", lower},
        {"reverse", reverse},
        {"exit", exit}

    };
    while (not exit)
    {
        fgets();
        printf("%s", str);

    }
    // upper(str);
    return 0;
}
