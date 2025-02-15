#include <stdio.h>
#include <string.h>

struct Event {
    char name[50];
    int day, month, year;
    char description[100];
};

int main() {
    int numEvents;
    scanf("%d", &numEvents);

    struct Event events[numEvents];

    for (int i = 0; i < numEvents; i++) {
        scanf("%s %d %d %d %s", events[i].name, &events[i].day, &events[i].month, &events[i].year, events[i].description);
    }

    for (int i = 0; i < numEvents; i++) {
        printf("Событие: %s\n", events[i].name);
        printf("Дата: %d/%d/%d\n", events[i].day, events[i].month, events[i].year);
        printf("Описание: %s\n\n", events[i].description);
    }

    return 0;
}