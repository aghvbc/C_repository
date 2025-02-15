// Создайте объединение `Grade`, которое может содержать либо числовую оценку (целое число), либо строку (например, "A", "B", "C" и т.д.). 
// Напишите программу, которая принимает оценку студентов, используя объединение, и выводит результат.

#include <stdio.h>
#include <string.h>

union Grade {
    int num_value;
    char string_value[50];
};

int main() {
    int n;
    printf("Введите количество оценок: ");
    scanf("%d", &n);
    int type_of_mark[n];
    union Grade grades[n];

    for (int i = 0; i < n; i++) {
        printf("Введите тип оценки: ");
        scanf("%d", &type_of_mark[i]);
        if (type_of_mark[i] == 1) {
            scanf("%d", &grades[i].num_value);
        } else if (type_of_mark[i] == 2) {
            scanf("%s", &grades[i].string_value);
        }
    }
    for (int i = 0; i < n; i++) {
        if (type_of_mark[i] == 1) {
            printf("Grade: %d\n", grades[i].num_value);
        }
        if (type_of_mark[i] == 2) {
            printf("Grade: %s\n", grades[i].string_value);
        }
    }
    
    

    return 0;
}
