#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentDate = tm.tm_year + 1900; // Год
    currentDate = currentDate * 100 + (tm.tm_mon + 1); // Месяц
    currentDate = currentDate * 100 + tm.tm_mday; // День
    printf("%d", currentDate);

    return 0;
}