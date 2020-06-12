#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //wait
#include <sys/wait.h> //wait
#include <stdlib.h> //atoi

int main(int argc, char *argv[])
{
    pid_t masterPid = getpid();
    pid_t p = fork();
	for (int i =0; i<10; i++){
        if(p>0)
            fork();
    }
    if(p==getpid())
        wait(NULL);


	return 0;
}
