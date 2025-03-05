

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void lower(char *c){
    for(int i = 0; c[i]; i++){
       c[i] = tolower(c[i]);
    }
}

int main() {
    char c[50] = "MAMO";
    lower(c);
    printf("%s", c);
    return 0;
}
