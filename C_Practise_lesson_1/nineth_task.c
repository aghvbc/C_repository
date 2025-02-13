#include <stdio.h>
#include <math.h>

int main() {
    double T;
    int D = 0;
    double T_copy;
    printf("Введите время передачи сообщения(в секундах): ");
    scanf("%lf", &T);

    T_copy = T;
    while (T >= 60){
        T -= 60;
        D += 1;
    }
    printf("%.2lf секунд → %d минута  %.2lf секунд", T_copy, D, T);
    

    return 0;
}