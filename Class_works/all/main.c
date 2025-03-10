#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int a = atof(argv[1]);
    int b = atof(argv[2]);
    int c = pow(a,b);
    printf("%d", c);
    return 0;
}