/*4. Собственная реализация qsort
Описание:
Реализуйте сортировку массива строк с помощью qsort, но с кастомной функцией сравнения, 
передаваемой через указатель на функцию.
Должны быть доступны три варианта сортировки:

По алфавиту
По длине строки
По количеству гласных букв
Пользователь вводит строки, затем выбирает режим сортировки.

🔹 Дополнительно: Можно реализовать сравнение без учёта регистра.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 100  
#define MAX_LENGTH 100   


int compare_alphabet(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}


int compare_length(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}


int count_vowels(const char *str) {
    int count = 0;
    while (*str) {
        char c = tolower(*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            count++;
        }
        str++;
    }
    return count;
}


int compare_vowels(const void *a, const void *b) {
    return count_vowels(*(const char **)a) - count_vowels(*(const char **)b);
}

int main() {
    char *strings[MAX_STRINGS];  
    int count = 0;               

    
    printf("Введите строки (пустая строка для завершения):\n");
    char buffer[MAX_LENGTH];
    while (count < MAX_STRINGS) {
        fgets(buffer, MAX_LENGTH, stdin);
        if (buffer[0] == '\n') break;  
        buffer[strcspn(buffer, "\n")] = 0;  
        strings[count] = strdup(buffer);  
        count++;
    }

    int choice;
    printf("Выберите вариант сортировки:\n");
    printf("1 - По алфавиту\n");
    printf("2 - По длине строки\n");
    printf("3 - По количеству гласных букв\n");
    scanf("%d", &choice);
    getchar();  


    int (*compare_func)(const void *, const void *) = NULL;
    if (choice == 1) compare_func = compare_alphabet;
    else if (choice == 2) compare_func = compare_length;
    else if (choice == 3) compare_func = compare_vowels;
    else {
        printf("Ошибка: неверный выбор\n");
        return 1;
    }

    qsort(strings, count, sizeof(char *), compare_func);

    printf("Отсортированные строки:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);  
    }

    return 0;
}