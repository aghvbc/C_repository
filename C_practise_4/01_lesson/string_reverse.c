#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    printf("%s", s);
}

int main(){
    char str[50];
    scanf("%s", str);
    reverse(str);
    return 0;
}