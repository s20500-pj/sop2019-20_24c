#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maksimum(int a, int b);
int minimum(int a, int b);
int suma(int a, int b);
int forAll(int tab[],int n, int id);

typedef int (*f)(int, int);
f func[3] = {maksimum, minimum, suma};

int main(int argc, char *argv[])
{
    int z, n, v;
    scanf("%d %d", &z, &n);
    int elements[n];
    

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
    }
    
    printf("%d", forAll(elements,n,z));
    
    return 0;
}

int maksimum(int a, int b)
{
    return a > b ? a : b;
}
int minimum(int a, int b)
{
    return a < b ? a : b;
}
int suma(int a, int b)
{
    return a + b;
}
int forAll(int tab[],int n, int id){
    int v = tab[0];
    for (int j = 1; j < n; j++)
    {
        v = func[id](v, tab[j]);
    }
    return v;
}