/*
 * main.c
 *
 *  Created on: 11-Apr-2019
 *      Author: students
 */


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<malloc.h>
#include<stdlib.h>
#define PORT 5000
int main(){
	extern FILE *stdout;
	char * buff= malloc(sizeof(char));
	int socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd<0){
		//printf("Error opening port!\n");
		exit(-1);
	}
	else{
		//printf("Socket file descriptor:%d\n",socketfd);
	}
	struct sockaddr_in serverAddress, clientAddress;
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_port=htons(PORT);
	serverAddress.sin_addr.s_addr=INADDR_ANY;
	if(bind(socketfd,(struct sockaddr *) &serverAddress,sizeof(serverAddress))){
		//printf("Error binding to port\n");
		exit(-1);
	}
	else{
		//printf("Binding complete!\n");
	}
	listen(socketfd,1);
	int clientAddress_len=sizeof(clientAddress);
	int clientsocketfd = accept(socketfd,(struct sockaddr *)&clientAddress,(socklen_t *)&clientAddress_len);
	if(clientsocketfd<0){
		//printf("Error accepting\n");
	}
	else{
		//printf("Connection accepted id:%d\n",clientsocketfd);
	}
	while(1){
		int n=read(clientsocketfd,buff,1);
		if(*buff==EOF){
			break;
		}
		if(n<0){
			//printf("Error reading!\n");
		}
		else{
			//printf("Read :%c",*buff);
			fputc(*buff,stdout);
		}
	}
	return 0;
}
