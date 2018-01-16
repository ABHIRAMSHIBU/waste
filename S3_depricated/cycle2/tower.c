/*Copyright (c) 2017 Abhiram Shibu
 *Copyright (c) 2017 Team Destroyer Projects\
 */     
#include<stdio.h>
#include "color.h"
/* Tower of Hanoi recursive way */
int pilla[20],pillb[20],pillc[20],topa=-1,topb=-1,topc=-1;
void display(){//display each pillar
    int t1=topa,t2=topb,t3=topc;
    printf("\n Stack:");
    printf("\n Rod \t %sA%s\t B %s\t C\n%s",RED,GRN,BLU,RESET);
    while(t1!=-1||t2!=-1||t3!=-1){
        printf("\t");
        if(t1!=-1)
        {
            printf("%s %d %s",RED,pilla[t1],RESET);
            t1--;
        }
        printf("\t");
        if(t2!=-1){
            printf("%s %d%s",GRN,pillb[t2],RESET);
            t2--;
        }
        printf("\t");
        if(t3!=-1){
            printf("%s %d%s",BLU,pillc[t3],RESET);
            t3--;
        }
        printf("\n");	
    }
}
void pusha(int key){//push disc to a
    topa++;
    if(topa==20){
        printf("\noverflow");
        topa--;
    }
    else{
        pilla[topa]=key;
    }
}
void pushb(int key){//push disc to b
    topb++;
    if(topb==20){
            printf("\noverflow");
            topb--;
    }
    else{
            pillb[topb]=key;
    }
}
void pushc(int key){//push disc to c
    topc++;
    if(topc==20){
        printf("\noverflow");
        topc--;
    }
    else{
        pillc[topc]=key;
    }
}
int popa(){//pop disc from a
    int x;
    if(topa==-1)
        printf("\nunderflow");
    else{
        x=pilla[topa];
        topa--;
        return x;
    }
}
int popb(){//pop disc from b
    int x;
    if(topb==-1)
        printf("\nunderflow");
    else{
        x=pillb[topb];
        topb--;
        return x;
    }
}
int popc(){//pop disc from c
    int x;
    if(topc==-1)
        printf("\nunderflow");
    else{
        x=pillc[topc];
        topc--;
        return x;
    }
}


void brahma(int num,char from,char to,char aux){//perform brahma tower operation
    int x;
    if(num==1){
        printf("\nMove disk 1 from rod %c to rod %c",from,to);
        if(from=='A' && to=='B'){
            x=popa();
            pushb(x);
        }
        else if(from=='A' && to=='C'){
            x=popa();
            pushc(x);
        }
        else if(from=='B' && to=='C'){
            x=popb();
            pushc(x);
        }
        else if(from=='B' && to=='A'){
            x=popb();
            pusha(x);
        }
        else if(from=='C' && to=='B'){
            x=popc();
            pushb(x);
        }
        else if(from=='C' && to=='A'){
            x=popc();
            pusha(x);
        }
        else
            ;
        display();
        return;
    }
    brahma(num-1,from,aux,to);
    printf("\nMove disk %d from pillar %c to pillar %c",num,from,to);
    if(from=='A' && to=='B'){
        x=popa();
        pushb(x);
    }
    else if(from=='A' && to=='C'){
        x=popa();
        pushc(x);
    }
    else if(from=='B' && to=='C'){
        x=popb();
        pushc(x);
    }
    else if(from=='B' && to=='A'){
        x=popb();
        pusha(x);
    }
    else if(from=='C' && to=='B'){
        x=popc();
        pushb(x);
    }
    else if(from=='C' && to=='A'){
        x=popc();
        pusha(x);
    }
    else;
    display();
    brahma(num-1,aux,to,from);
}

void towerOfHanoi(int * step,int n, char from, char to, char sub)
{
    if (n == 1)
    {
	printf("\t%sStep:%s%d, ",RED,GRN,* step);
        printf("%smove disk %s1",RED,GRN, from, to);
        printf("%s from rod %s%c",RED,GRN, from);
        printf("%s to rod %s%c%s\n",RED,GRN,to,RESET );
        *step=*step+1;
	return;
    }
    towerOfHanoi(step,n-1, from, sub, to);
    printf("\t%sStep:%s%d, ",RED,GRN,* step);
    printf("%smove disk %s%d",RED,GRN,n);
    printf("%s from rod %s%c",RED,GRN, from);
    printf("%s to rod %s%c%s\n",RED,GRN,to,RESET );
    *step=*step+1;
	towerOfHanoi(step,n-1, sub, to, from);
}

int main()
{
    printf("%sProgram Written by %sAbhiram Shibu\n \t\tTOWER!%s\n",BLU,RED,RESET);
	int n;
	int step=1;
    printf("%sEnter number of disks:%s",RED,GRN);
    printf("%s",RESET);
    scanf("%d",&n);
    towerOfHanoi(&step,n, 'A', 'B', 'C');
    printf("\nDo you want to see stack?[1/0]:");
    int c;
    scanf("%d",&c);
    if(c==1){
        /* Push values to stack */
        for(int i=n;i>0;i--)
            pusha(i);
        /* Run display */
        brahma(n,'A','B','C');
    }
    return 0;
    
}
