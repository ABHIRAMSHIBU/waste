#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<malloc.h>
#define N 5
#define THINKING 0
#define HUNGRY 1
#define TRUE 1
#define FALSE 0
sem_t s[N];
sem_t *mutex;

// void *run(void *v){
//     sem_wait(mutex);
//     int *sval=malloc(sizeof(int));
//     sem_getvalue(mutex,sval);
//     printf("The mutex value %d\n",*sval);
//     printf("This is the thread %d\n",pthread_self());
//     printf("The pid is %d\n",getpid());
//     sleep(1);
//     sem_post(mutex);
// }
void *philosopher(void *p){
    int *pno=p;
    int left;
    int right;
    printf("Philosopher no %d alive\n",*pno);
    while(TRUE){
            left=(*pno-1)%N;
            right=(*pno)%N;
            printf("Philosopher %d is hungry \n",*pno);
            sem_wait(s+left);
            printf("Philosopher %d got left chopstick\n",*pno);
            sem_wait(s+right);
            printf("Philosopher %d got right chopstick\n",*pno);
            printf("Philosopher %d is eating\n",*pno);
            sleep(2);
            
            printf("Philosopher %d has finished eating \n",*pno);
            sem_post(s+left);
            printf("Philosopher %d dropped left chopstick\n",*pno);
            sem_post(s+right);
            printf("Philosopher %d dropped right chopstick\n",*pno);
            printf("Philosopher %d is thinking\n",*pno);
            sleep(1);
            
    }

}
void main(){
     mutex=malloc(sizeof(sem_t));
     sem_init(mutex,0,1);
     for(int i=0;i<N;i++){
         sem_init(s+i,0,1);
    }
     pthread_t t[5];
     int *z;
     for(int i=0;i<5;i++){
         z=malloc(sizeof(int));
         *z=i+1;
         pthread_create(&t[i],NULL,philosopher,z);
    }
    pthread_exit(NULL);
    printf("After all threads");
     
}