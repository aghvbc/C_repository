#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Разделение экипажа

В космической экспедиции участвуют заранее подготовленные космонавты. 
Для предстоящего полета подготовлены модульные отсеки для космического корабля. 
Космическая программа профинансировала изготовление 3-х вариантов модулей, которые вмещают 2-х человек экипажа, 3-х или 4-х человек. 
По итогу отбора участников, будет выяволено общее число претендентов на экспедицию. 
Напишите программу, которая определит можно ли разделить число отобранных участников на равные группы, где каждая группа может содержать 2, 3 или 4 человека. 
На вход программа принимает количество космонавтов и выводит, можно ли их разделить без остатка, а также сколько потребуется полностью заполненных модулей и какого типа: 2-х, 3-х или 4-х местные. 
Программа должна рассчитать всевозможные варианты комплектаций модулями, исключая непоместившегося космонавта (если такой будет).
*/

int main(){
    int clanses;
    int number;
    int remainder_of_clanses;
    int groups_of_four = 0;
    int groups_of_three = 0;
    int groups_of_two = 0;
    int temp_num;
    
    printf("Напишите количество претендентов: ");
    scanf("%d", &clanses);
    
    if (clanses % 2 == 0){
        number = clanses / 2;
        printf("Претендентов для группы по 2 человека: %d\n", number);
    }
    else if (clanses % 2 != 0){
        number = clanses / 2;
        remainder_of_clanses = clanses % 2;
        printf("Претендентов для группы по 2 человека: %d с остатком из: %d человек\n", number, remainder_of_clanses);
    }

    if (clanses % 3 == 0){
        number = clanses / 3;
        printf("Претендентов для группы по 3 человека: %d\n", number);
    }
    else if (clanses % 3 != 0){
        number = clanses / 3;
        remainder_of_clanses = clanses % 3;
        printf("Претендентов для группы по 3 человека: %d с остатком из: %d человек\n", number, remainder_of_clanses);
    }

    if (clanses % 4 == 0){
        number = clanses / 4;
        printf("Претендентов для группы по 4 человека: %d\n", number);
    }
    else if (clanses % 4 != 0){
        number = clanses / 4;
        remainder_of_clanses = clanses % 4;
        printf("Претендентов для группы по 4 человека: %d с остатком из: %d человек\n", number, remainder_of_clanses);
    }
    
    temp_num = clanses;

    printf("temp = %d\n", temp_num);

    while (temp_num >= 2){
        if (temp_num >= 4){
            groups_of_four += 1;
            temp_num -= 4;
            continue;
        }

        else if (temp_num >= 3){
            groups_of_three += 1;
            temp_num -= 3;
            continue;
        }

        else if (temp_num >= 2){
            groups_of_two += 1;
            temp_num -= 2;
            continue;
        }
    }
    // printf("четыре: %d три: %d два: %d не войдёт: %d человек\n", groups_of_four, groups_of_three, groups_of_two, temp_num);

    // if (groups_of_four == groups_of_three && groups_of_four == groups_of_two){
    //     printf("Претендентов можно разделить на равные группы: %d, не войдёт: %d человек\n", groups_of_four, temp_num);
    // }
    // else{
    //     printf("Претендентов нельзя  разделить на равные группы.");
    // }

    if (clanses % 2 != 0 && clanses % 3 != 0 && clanses % 4 != 0)
    {
        printf("Нельзя разделить на равные группы одного типа.\n");
    }

    if (clanses % 2 == 0) {
        printf("%d модулей по 2 человека (можно разделить на равные группы)\n", clanses / 2);
    }
    if (clanses % 3 == 0) {
        printf("%d модулей по 3 человека (можно разделить на равные группы)\n", clanses / 3);
    }
    if (clanses % 4 == 0) {
        printf("%d модулей по 4 человека (можно разделить на равные группы)\n", clanses / 4);
    }
    return 0;
}