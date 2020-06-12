#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //wait
#include <sys/wait.h> //wait
#include <stdlib.h> //atoi

int check_prime(int a)
{
	int c;

	for (c = 2; c <= a - 1; c++)
	{
		if (a % c == 0)
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int n, s = 0;
	n = atoi(argv[1]);

	if (fork() > 0)
	{
		for (int i = 0; i < n; i++)
		{
			s += i;
		}
		wait(NULL); //- wait for child to terminate
		printf(" \n");
		//wait(&status) you wait for a child to terminate
		//but you want to know some information about it's termination.
		printf("Rodzic::suma: %d", s);
		printf(" \n");
	}
	else
	{
		printf("Dziecko::liczby pierwsze: ");
		for (int j = 0; j < n; j++)
		{
			if (check_prime(j))
				printf("%d ", j);
		}
	}

	return 0;
}
