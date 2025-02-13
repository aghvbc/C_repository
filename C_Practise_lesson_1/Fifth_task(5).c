#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    const double epsilon = 0.000001;
    double calculated_speed;
    printf("Введите расчётную скорость: ");
    scanf("%lf", &calculated_speed);
    printf("скорость: %f\n", calculated_speed );


    double actual_speed;
    printf("Введите фактическую скорость: ");
    scanf("%lf", &actual_speed);
    printf("скорость: %f\n", actual_speed);

    printf("%f\n", fabs(calculated_speed - actual_speed));
    

    if (fabs(calculated_speed - actual_speed) > 0.1 + epsilon){
        printf("Орбита не стабильна");
        return 0;
    }
    
    printf("Орбита стабильна");
    return 0;
}