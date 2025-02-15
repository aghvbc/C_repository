// Напишите программу, которая будет принимать информацию о студентах (структура `Student` с полями `name`, `age`, `gpa`), 
// используя указатели на структуры, а затем выводить данные о каждом студенте.

#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int choice;
    printf("Введите студентов: ");
    scanf("%d", &choice);   
    struct Student student[choice];

    for(int i = 0; i < choice; i++){
        printf("Введите имя: ");
        scanf("%s", &student[i].name);
        printf("Введите возраст: ");
        scanf("%d", &student[i].age);
        printf("Введите среднюю оценку: ");
        scanf("%f", &student[i].gpa);

    }
    printf("\n");
    for(int i = 0; i < choice; i++){
        printf("Имя студента: %s\n", student[i].name);
        printf("возраст студента: %d\n", student[i].age);
        printf("Средняя оценка студента: %.2f\n", student[i].gpa);
    }


    return 0;
}