/*
 * main.c
 *
 *  Created on: 11-Apr-2019
 *      Author: students
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <malloc.h>
#include <unistd.h>
#include <arpa/inet.h>
#define SERVER_PORT 5000
#define SERVER_ADDR "127.0.0.1"
int main(){
	extern FILE *stdin;
	char * buff=malloc(sizeof(char));
	*(buff)='c';
	struct sockaddr_in serverAddress;
	if(inet_pton(AF_INET,SERVER_ADDR,&serverAddress.sin_addr.s_addr)<0){
		//printf("Address conversion to binary failed\n");
	}
	else{
		//printf("Address successfully translated\n");
	}
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_port=htons(SERVER_PORT);
	int socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd<0){
		//printf("Error encountered while creading socket\n");
	}
	else{
		//printf("Socket created!\n");
	}
	if(connect(socketfd,(struct sockaddr *)&serverAddress,(socklen_t)sizeof(serverAddress))<0){
		//printf("Connecting to server failure\n");
	}
	while(1){
		*buff=fgetc(stdin);
		int n=write(socketfd,buff,1);
		if(*buff==EOF){
			break;
		}
	}
	return 0;
}
