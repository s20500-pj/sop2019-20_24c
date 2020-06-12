#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Moj proces to: %d", getpid());
    printf("\n");
    if (fork() > 0)
    {
        printf("rodzic: \n");
        printf("PID: %d ", getpid());
        printf("PPID: %d ", getppid());
        printf("\n");
    }
    else
    {
        printf("potomek: \n");
        printf("PID: %d ", getpid());
        printf("PPID: %d", getppid());
        printf("\n");
    }

    return 0;
}