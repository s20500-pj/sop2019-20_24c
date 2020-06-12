#include <stdio.h>

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]); //należy użyć atoi żeby char to int
                              //ponieważ argv[1] to char string
    int i, j;

    for (i = 1; i <= size; i++) 
    {
        for (j = 1; j <= size - i; j++) 
            printf(" ");

        for (j = 1; j <= 2 * i - 1; j++) 
            printf("*");

        printf("\n");
    }

    return 0;
}