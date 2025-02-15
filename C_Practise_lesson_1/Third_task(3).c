#include <stdio.h>
#include <string.h>

int main() {
    char character; 

    printf("Введите один символ (от A до Z): ");
    scanf("%с", character); 

    if (character >= 'A' && character <= 'Z') {
        printf("Символ %c входит в допустимый диапазон.\n", character);
    } else {
        printf("Символ %c не входит в допустимый диапазон.\n", character);
    }

    return 0;
}

