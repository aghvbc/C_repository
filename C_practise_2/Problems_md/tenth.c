// Создайте структуру `Course`, которая будет хранить информацию о курсе: название (строка), количество кредитов (целое число), преподаватель (строка). 
// Напишите программу, которая выводит список всех курсов и их преподавателей.

// **Ввод:**  

//    ```bash
//    2
//    Mathematics 5 Dr.Smith
//    Physics 4 Dr.Jones
//    ```

//    **Вывод:**  

//    ```bash
//    Course: Mathematics
//    Credits: 5
//    Professor: Dr.Smith

//    Course: Physics
//    Credits: 4
//    Professor: Dr.Jones
//    ```

// ---


#include <stdio.h>
#include <string.h>

struct Course {
    char name[50];
    int credits_count;
    char teacher[50];
};

int main() {
    int n;
    printf("Введите предметов: ");
    scanf("%d", &n);

    struct Course сourse[n];

    for (int i = 0; i < n; i++) {
        printf("Введите имя предмета: ");
        scanf("%s", сourse[i].name);
        printf("Введите кредиты: ");
        scanf("%d", &сourse[i].credits_count);
        printf("Введите имя преподавателя: ");
        scanf("%s", сourse[i].teacher);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Имя предмета: %s\n", сourse[i].name);
        printf("Кредиты: %d\n", сourse[i].credits_count);
        printf("Имя преподавателя: %s\n", сourse[i].teacher);
        printf("\n");
    }

    return 0;
}
