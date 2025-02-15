#include <stdio.h>
#include <string.h>

// Создайте структуру `Employee`, которая будет хранить информацию о сотруднике: имя (строка), должность (строка), зарплата (вещественное число). 
// Напишите программу, которая принимает информацию о нескольких сотрудниках, а затем выводит отчет по зарплатам.

struct Employee {
    char name[50];
    char job_title[50];
    float salary;
};

int main() {
    int numEvents;
    scanf("%d", &numEvents);

    struct Employee employee_lst[numEvents];

    for (int i = 0; i < numEvents; i++) {
        scanf("%s %s %f", employee_lst[i].name, employee_lst[i].job_title, &employee_lst[i].salary);
    }

    for (int i = 0; i < numEvents; i++) {
        printf("Event: %s\n", employee_lst[i].name);
        printf("Job_title: %s\n", employee_lst[i].job_title);
        printf("Description: %.2f\n", employee_lst[i].salary);
    }

    return 0;
}