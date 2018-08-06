// Author Abhiram Shibu Copyleft 2018
#include<iostream>
using namespace std;
class process{
public:
    int at;
    int bt;
    int wt;
    int tat;
    static int count;
    bool ec=false;
    static void sortasc(bool burstTime, process *p){
        for(int i=0;i<process::count;i++){
            for(int j=i+1;j<process::count;j++){
                if(burstTime){
                    if(p[i].bt>p[j].bt){
                        process temp = p[i];
                        p[i]=p[j];
                        p[j]=temp;
                    }
                }
                else{
                    if(p[i].at>p[j].at){
                        process temp = p[i];
                        p[i]=p[j];
                        p[j]=temp;
                    }
                }
            }
        }
    }
    static void assignWaitTurnAroundTimeFCFS(process * p){
        long execution_time=0;
        int last_burst=0;
        for(int i=0;i<process::count;i++){
            if(p[i].at<execution_time){   // P arrived while executing
                int wait_time=execution_time-p[i].at;
                p[i].wt=wait_time;
                execution_time+=p[i].bt;
                p[i].tat=execution_time-p[i].at;
                p[i].ec=true;
            }
            else{                        // P arrived after executing
                int wait_time=0;
                execution_time=p[i].at;
                p[i].wt=wait_time;
                execution_time+=p[i].bt;
                p[i].tat=execution_time-p[i].at;
                p[i].ec=true;
            }
        }
    }
    static void assignWaitTurnAroundTimeSJF(process * p){
        process::sortasc(false,p);
        int process_of_choice=0;
        long execution_time=0;
        for(int i=0;i<process::count;i++){
            bool proc_select=false;
            int min=-1;
            int minPoss=-1;
            for(int j=0;j<process::count;j++){
                if(p[j].at<=execution_time && p[j].ec==false){ //eligibility criteria
                    if(min==-1){
                        min=p[j].bt;
                        minPoss=j;
                    }
                    else{
                        if(min>p[j].bt){
                            min=p[j].bt;
                            minPoss=j;
                        }
                    }
                    proc_select=true;
                }
            }
            process_of_choice=minPoss;
            if(proc_select==false){
                for(int i=0;i<process::count;i++){
                    if(p[i].ec==false){
                        proc_select=true;
                        process_of_choice=i;
                        break;
                    }
                }
            }
            if(proc_select==false){
                break;
            }
            if(execution_time<=p[process_of_choice].at){
                execution_time=p[process_of_choice].at;
                p[process_of_choice].wt=0;
                p[process_of_choice].tat=p[process_of_choice].bt;
                execution_time+=p[process_of_choice].bt;
                p[process_of_choice].ec=true;
            }
            else{
                p[process_of_choice].wt=execution_time-p[process_of_choice].at;
                execution_time+=p[process_of_choice].bt;
                p[process_of_choice].tat=p[process_of_choice].wt+p[process_of_choice].bt;
                p[process_of_choice].ec=true;
            }
        }
    }
    static void display(process p){
        cout<<"Arraival Time:"<<p.at
            <<" Burst Time:"<<p.bt
            <<" Wait Time:"<<p.wt
            <<" Turn Around Time:"<<p.tat
            <<endl;
    }
    static void displayAll(process *p){
        int awt=0;
        int atat=0;
        for(int i=0;i<process::count;i++){
         process::display(p[i]);
         awt+=p[i].wt;
         atat+=p[i].tat;
        }
        awt/=process::count;
        atat/=process::count;
        cout<<"Average wait time:"<<awt
            <<" Average turn around time:"<<atat
            <<endl;
    }
    static process * copy(process * p){
        process * new_p = new process[process::count];
        for(int i=0;i<process::count;i++){
            new_p[i]=p[i];
            new_p[i].tat=0;
            new_p[i].wt=0;
            new_p[i].ec=false;
        }
        return new_p;
    }
};
void doFCFS(process * p){
    cout<<"FCFS RESULT"<<endl;
    process * new_p = process::copy(p);
    process::sortasc(false,new_p);
    process::assignWaitTurnAroundTimeFCFS(new_p);
    process::displayAll(new_p);
    cout<<"END FCFS RESULT"<<endl;
}
void doSJF(process * p){
    cout<<"SJF RESULT"<<endl;
    process * new_p = process::copy(p);
    process::assignWaitTurnAroundTimeSJF(new_p);
    process::displayAll(new_p);
    cout<<"END SJF RESULT"<<endl;
}
int process::count=0;
int main(){
    process::count=5;
    process p[process::count];
    p[0].at=0;
    p[0].bt=20;
    p[1].at=100;
    p[1].bt=12;
    p[2].at=101;
    p[2].bt=10;
    p[3].at=0;
    p[3].bt=8;
    p[4].at=100;
    p[4].bt=1;
    doFCFS(p);
    doSJF(p);
    return 0;
}
