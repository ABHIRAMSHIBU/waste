#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<malloc.h>
#define True 1
#define False 0
static sem_t *s;
void run(){
    
    printf("Trying semaphore:");
}
void main(){
    int *sval=malloc(sizeof(int));
    s=malloc(sizeof(sem_t));
    sem_init(s,1,1);
    pid_t pid= fork();
    while(True){
        if(pid==0){
            sem_getvalue(s,sval);
            printf("Child semaphore value is %d\n",*sval);
            sem_post(s);
            sleep(1);
        }
        else if(pid>0){
            sem_wait(s);
            sem_getvalue(s,sval);
            printf("Parent semaphore value is %d\n",*sval);
        }
        else{
            printf("Error\n");
        }
    }
}