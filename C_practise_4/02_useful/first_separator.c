#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Привет, мир!";
    char *pos = strpbrk(str, " ,.!");

    if (pos) {
        *pos = '\0';  // Заменяем первый найденный разделитель на \0
    }

    printf("Первая часть строки: \"%s\"\n", str);
    return 0;
}