#include <stdio.h>

// объеденяет два 2 числа в одно 4 байтовое например

union Data {
    int i;
    float f;
    char str[20];

};


int main() {
    union Data data;

    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 220.5;
    printf("data.f = %.2f\n", data.f);

    return 0;
}