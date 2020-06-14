/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 100

void sentFile(int sockfd, char filename[MAX]) 
{ 
 char buff[MAX];       // for read operation from file and used to sent operation 
 
 // create file 
 FILE *fp;
 fp=fopen(filename,"r");  // open file uses both stdio and stdin header files
           // file should be present at the program directory
if( fp == NULL ){
  printf("Error IN Opening File .. \n");
  return ;
 }
 
 while ( fgets(buff,MAX,fp) != NULL ) // fgets reads upto MAX character or EOF 
  write(sockfd,buff,sizeof(buff));  // sent the file data to stream
 
 fclose (fp);       // close the file 
 
 printf("File Sent successfully !!! \n");
 
}

void error(const char *msg)     //wyświetla błąd jeśli połączenie z serwerem zostanie nieudane
{                               //i kończy prace
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     while(1){
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
     read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     sentFile(newsockfd,buffer);
     
     close(newsockfd);
     }
     close(sockfd);
     return 0; 
}