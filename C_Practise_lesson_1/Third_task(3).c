#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; 

    printf("Введите один символ (от A до Z): ");
    scanf("%s", input); 

    if (strlen(input) != 1) {
        printf("Введите символ от A до Z.\n");
    } else {
        char character = input[0]; 
        if (character >= 'A' && character <= 'Z') {
            printf("Символ '%c' входит в допустимый диапазон.\n", character);
        } else {
            printf("Символ '%c' не входит в допустимый диапазон.\n", character);
        }
    }

    return 0;
}

