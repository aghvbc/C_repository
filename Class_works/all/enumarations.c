#include <stdio.h>

enum Day {
    Sunday, Monday, Thuesday, Wednesday, Thursday, Friday, Saturday
};

int main() {
    enum Day today = Wednesday;
    printf("Today is day number: %d\n", today);
    return 0;
}