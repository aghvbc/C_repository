#include <stdio.h>
#include <unistd.h>

extern char ** environ;

int main (void)
{
    char * uname_args[] = {"uname", "-a", NULL};
    execvp ("uname", uname_args);
    fprintf (stderr, "Error\n");
    return 0;
}