#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char fileName[100];
    scanf("%s",fileName);
    int n, x;

    FILE *fptr;
    fptr = fopen(fileName,"r");
    
    
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

    FILE *binaryfile;
    if ((binaryfile = fopen("./binary.bin","wb+")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
    fwrite(&str,sizeof(str),1,binaryfile);
    unsigned char buffer[10];
    if(strcmp(argv[1],"--print")==0){
        fread(buffer,sizeof(buffer),1,binaryfile);
        for(int i = 0; i<10; i++)
            printf("%u ", buffer[i]);
    }
    fclose(binaryfile);
    return 0;
}