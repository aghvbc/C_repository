#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void removeSpaces(char *str) {
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

int main(void) {
    char text[] = "Это пример   строки с пробелами,\tа также табуляцией и\nпереводами строки.";

    printf("Исходная строка:\n%s\n\n", text);
    removeSpaces(text);
    printf("Строка без пробелов:\n%s\n", text);

    return 0;
}