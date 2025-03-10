#include <stdio.h>

struct Person
{
    char name[50];
    int age;
    float height;

};

int main() {
    struct Person p = {"Alise", 30, 1.75};
    printf("Name: %s, Age: %d, Height: %.2f\n", p.name, p.age, p.height);
    return 0;
    
}