#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<pthread.h>
#include<string.h>
//#include<types.h>
void main(){
    key_t key=ftok("p",0);
    printf("Got token :%d\n",key);
    int s = shmget(key,1024,0666|IPC_CREAT);
    printf("Shared memory id:%d\n",s);
    pid_t p=fork();
    if(p==0){
        char *str=(char*)shmat(s,NULL,0);
        printf("(Child)Enter data to send:");
        scanf("%s",str);
        shmdt(str);
    }
    else{
        char *str=(char*)shmat(s,NULL,0);
        printf("(Parent)Child started with pid:%d\n",p);
	printf("(Parent)Waiting for child %d\n",p);
        wait();
	printf("(Parent)Child %d completed\n",p);
        printf("(Parent)Data receved from child:%s\n",str);
        shmctl(s,IPC_RMID,NULL);
    }
}
