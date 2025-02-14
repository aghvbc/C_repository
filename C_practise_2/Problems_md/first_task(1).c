#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float average_mark;
};

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++){
        struct  Student student;
        scanf("%s", student.name);
        scanf("%d", &student.age);
        scanf("%f", &student.average_mark);

        printf("Name: %s\n", student.name);
        printf("Age: %d\n", student.age);
        printf("GPA: %.1f\n", student.average_mark);
    }

    return 0;
}
