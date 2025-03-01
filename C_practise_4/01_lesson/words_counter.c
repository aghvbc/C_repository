#include <stdio.h>
#include <string.h>
#include <ctype.h>



int count_words(char *s) {
    int count = 0;
    while (*s) {
        while (*s && isspace(*s)) s++;
        if (*s) count++;
        while (*s && !isspace(*s)) s++;
    }
    printf("%d", count);
    return count;
}


int main(){
    char str[50];
    fgets(str, 50, stdin);
    count_words(str);
    return 0;
}