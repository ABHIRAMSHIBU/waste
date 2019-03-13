#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
typedef struct msg{
    int a[10][10];
    int r,c;
}m;
int main(){
    //char a[100]="Hello World";
    key_t key;
    key=ftok("p",1);
    //printf("%d",key);
    int msgid=msgget(key,0666|IPC_CREAT);
    
    //printf("%d\n",msgid);
    if(fork()!=0){
        m b;
        wait();
        msgrcv(msgid,&b,sizeof(b),0,MSG_NOERROR|IPC_NOWAIT);
        int r=b.r,c=b.c;
        printf("The read matrix is \n");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("a[%d][%d]=%d\n",i,j,b.a[i][j]);
            }
        }
        printf("The diagonal elements are :\n");
        for(int i=0;i<r;i++){
             printf("a[%d][%d]=%d\n",i,i,b.a[i][i]);
        }
        msgctl(msgid,IPC_RMID,NULL);
    }
    else{
        m a;        
        int r,c;
        printf("Enter the no of rows and columns : \n");
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("Enter the element in %d %d : ",i,j);
                scanf("%d",&a.a[i][j]);
            }
        }
        a.r=r;
        a.c=c;
        msgsnd(msgid,&a,sizeof(a),IPC_NOWAIT);
    }
}
