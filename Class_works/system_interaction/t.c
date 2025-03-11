#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
    int uid = getuid();
    struct passwd * pwdp = getpwuid(uid);
    if (pwdp == NULL){
        fprintf(stderr, "Bad username\n");
        return 1;
    }

    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    printf("UID: %d\n", uid);
    printf("Username: %s\n", pwdp->pw_name);

    system("sleep 15 &");
    return 0;
}