#include <stdio.h>
#include <magic.h>

int main(){
    int t;
    printf("Введите температуру корпуса: ");
    scanf("%d", &t);

    if (t>= -150 && t<= 120){
        printf("Температура корпуса в норме");
        return 0;
    }

    printf("Температура корпуса не в норме!");
    return 0;
}