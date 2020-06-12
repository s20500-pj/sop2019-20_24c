#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //wait
#include <sys/wait.h> //wait
#include <stdlib.h> //atoi

int main(int argc, char *argv[])
{
	for (int i =0; i<100; i++){
        if(fork()==0){
            fork();
            wait(NULL);
        }
        else
        {
            wait(NULL);
        }
        
    }


	return 0;
}
