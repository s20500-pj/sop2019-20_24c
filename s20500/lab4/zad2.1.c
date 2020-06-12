#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char fileName[100];
    scanf("%s",fileName);
    int n, x;

    FILE *fptr;
    fptr = fopen("./test.txt","r");
    
    
    fscanf(fptr,"%d",&n);
    char str[100]={""};
    char temp[100];
    for(int i = 0; i < n ; i++){
        fscanf(fptr,"%99s",temp); //zabezpieczenie przed przepełnieniem bufora
        strcat(str, temp);        
    }
    
    for (int j = 0; str[j] != 0; j++){
        printf("%c", str[j]);
        printf(" ");
    }
    printf("\n");

    fclose(fptr);
    return 0;
}