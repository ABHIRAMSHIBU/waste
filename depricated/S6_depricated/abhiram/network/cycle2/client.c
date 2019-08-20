
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char data[1000];
    char buffer[1024] = {0}; 
    char name[100];
    printf("Enter your name:");
    gets(name);
    strcat(name,":");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    pid_t pid=fork();
    if(pid==0){
//         printf("Your name is %s",name);
        while(1){
            strcpy(buffer,"");
//             printf("%s\n",buffer );
//             fflush(stdout);
            valread = read( sock , buffer, 1024); 
            buffer[valread]='\0';
            printf("\r%s\n",buffer );
            printf("\n%s:",name);
        }
    }
    else{
        while(1){
            strcpy(data,"");
//             printf("Data after strcpy:%s\n",data);
            printf("%s:",name);
            gets(data);
            char buff[1024];
            strcpy(buff,name);
            strcat(buff,data);
//             printf("Data after reading from user :%s\n",data);
            send(sock , buff , strlen(buff) , 0 ); 
        }
    }
//     send(sock , data , strlen(data) , 0 ); 
//     printf("Hello message sent\n"); 
//     valread = read( sock , buffer, 1024); 
//     printf("%s\n",buffer ); 
    return 0; 
} 
