 #include <stdio.h>
 #include <time.h>

// // Ожидаемый старт миссии
// // Дата старта миссии задана в виде целого числа (например, 20250210 – 10 февраля 2025 года). 
//Напишите программу, которая принимает дату от пользователя и проверяет, находится ли она в будущем относительно текущей даты.

int main() {
    int date;
    printf("Введите дату в формате(20250210): ");
    scanf("%d", &date);

    int day = date % 100;
    int month = (date / 100 )% 100;
    int year = ((date / 100 ) / 100) % 10000;
    printf("Год: %d\nМесяц: %02d\nДень: %d\n", year, month, day);

    time_t mytime = time(NULL);
    struct tm now = *localtime(&mytime);
    
    int currentDate = now.tm_year + 1900; // Год
    currentDate = currentDate * 100 + (now.tm_mon + 1); // Месяц
    currentDate = currentDate * 100 + now.tm_mday; // День
    printf("Ваша дата: %d\n", currentDate);
    
    if (currentDate > date){
        printf("Вы находитесь в будущем");
    }
    else if (currentDate < date)
    {
        printf("Вы находитесь в прошлом");
    }
    else{
        printf("Вы ввели текущую дату");
    }
    

    return 0;
}

