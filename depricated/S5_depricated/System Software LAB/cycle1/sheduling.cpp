/*Author Abhiram Shibu Copyleft 2018*/
#include<iostream>
class program{
public:
    int burstTime;
    int arraivalTime;
    int pid;
    void displayAll(){
        std::cout<<"Burst time :"<<burstTime<<" arraival time :"<<arraivalTime<<std::endl;
    }
    void getAll(){
        std::cout<<"Enter bust time, arraival time"<<std::endl;
        std::cin>>burstTime>>arraivalTime;
    }
};
void sort(bool burst,program * p,int length){
    if(burst){ // Sort brust time
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(p[i].burstTime>p[j].burstTime){
                    program temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
    }
    else{
        for(int i=0;i<length;i++){ // Sort by arraivalTime
            for(int j=i+1;j<length;j++){
                if(p[i].arraivalTime>p[j].arraivalTime){
                    program temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
    }
}
int count=0;

//Depricated function
program * getProgram(){
    using namespace std;
    program a[100];
    cout<<"Maximum number of processes are 100";
    for(int i=0;i<100;i++){
        a[i].getAll();
        count++;
        cout<<"Do you want to enter more ?[1/0]:";
        int choice;
        cin>>choice;
        if(choice==0){
            break;
        }
    }
    return a;
}
void fcfs(program * p,int length){
    sort(false,p,length);
    float averageWaitTime;
    float waitTime[count];
    for(int i=0;i<length;i++){
        if(i==0){
            waitTime[i]=0;
        }
        else{
            for(int j=0;j<i;j++){
                waitTime+=p[i-1].burstTime;
            }
        }
    }
    averageWaitTime/=length;
    std::cout<<"Average wait time is :"<<averageWaitTime;
}
int main(){
    using namespace std;
    program a[100];
    cout<<"Maximum number of processes are 100";
    for(int i=0;i<100;i++){
        a[i].getAll();
        count++;
        cout<<"Do you want to enter more ?[1/0]:";
        int choice;
        cin>>choice;
        if(choice==0){
            break;
        }
    }
    sort(false,a,count);
    for(int i=0;i<count;i++){
        a[i].displayAll();
    }
}