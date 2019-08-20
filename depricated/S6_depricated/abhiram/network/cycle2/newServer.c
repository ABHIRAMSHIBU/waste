#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
int main(){
    int socketID=socket(AF_INET,SOCK_STREAM,0);
    printf("Socket id %d",socketID);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port=htons(8080);
    addr.sin_addr.s_addr=INADDR_ANY;
    int optval=setsockopt(socketID, SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,NULL, 0);
    int bindval = bind(socketID,(struct sockaddr*)&addr,sizeof(addr));
    printf("binval %d",bindval);
    int listen_value=listen(socketID,0);
    printf("listen value %d",listen_value);
    int accept_val= accept(socketID, (struct sockaddr*)&addr,(socklen_t*)sizeof(addr));
    printf("accept value %d",accept_val);
    char buff[100];
    ssize_t a=read(accept_val, buff, 100);
    printf("%s",buff);

    
}
