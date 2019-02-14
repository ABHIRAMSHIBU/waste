//Author Abhiram Shibu Copyleft 2018
#include<iostream>
using namespace std;
class process{
public:
    int nice;
    int at=0;
    int bt;
    int wt;
    int tat;
    static int count;
    bool ec=false;
    static void sortasc(bool bursttime, process *p){
        for(int i=0;i<process::count;i++){
            for(int j=i+1;j<process::count;j++){
                if(bursttime){
                    if(p[i].bt>p[j].bt){
                        process temp = p[i];
                        p[i]=p[j];
                        p[j]=temp;
                    }
                }
                else{
                    if(p[i].nice>p[j].nice){
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
            if(true){   // P arrived while executing
                int wait_time=execution_time;
                p[i].wt=wait_time;
                execution_time+=p[i].bt;
                p[i].tat=execution_time;
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
    static void display(process p){
        cout<<"Burst Time:"<<p.bt
            <<" Wait Time:"<<p.wt
            <<" Turn Around Time:"<<p.tat
            <<" Nice"<<p.nice
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
    static void assignWaitTurnAroundTimeRR(process * p, int time_slice){
        int pointer=0;
        int finish_count=0;
        long time_elapsed=0;
        while(true){
            if(p[pointer].ec==false){
                if(p[pointer].bt>=time_slice){
                    p[pointer].bt-=time_slice;
                    time_elapsed+=time_slice;
                    for(int i=0;i<process::count;i++){
                        if(pointer!=i && p[i].ec!=true){
                            p[i].wt+=time_slice;
                        }
                    }
                    if(p[pointer].bt==0){
                        finish_count++;
                        p[pointer].tat=time_elapsed;
                        p[pointer].ec=true;
                    }
                }
                else{
                    if(p[pointer].bt==0){
                        finish_count++;
                        p[pointer].tat=time_elapsed;
                        p[pointer].ec=true;
                    }
                    else{
                        if(p[pointer].bt<0){
                        }
                        time_elapsed+=p[pointer].bt;
                        for(int i=0;i<process::count;i++){
                            if(pointer!=i && p[i].ec!=true){
                                p[i].wt+=p[pointer].bt;
                            }
                        }
                        p[pointer].bt=0;
                        if(p[pointer].bt==0){
                            finish_count++;
                            p[pointer].tat=time_elapsed;
                            p[pointer].ec=true;
                        }
                    }
                }
            }
            if(finish_count==process::count){
                break;
            }
            pointer++;
            if(pointer==process::count){
                pointer=0;
            }
        }
    }
    static void assignWaitTurnAroundTimePS(process *p){
        sortasc(false,p);
        assignWaitTurnAroundTimeFCFS(p);
    }
};
void reset_burst_time(process *p,process* p_new){
    for(int i=0;i<process::count;i++){
        p_new[i].bt=p[i].bt;
    }
}
int process::count=0;
int main(){
    process::count=5;
    process p[process::count];
    p[0].bt=20;
    p[0].nice=1;
    p[1].bt=12;
    p[1].nice=2;
    p[2].bt=10;
    p[2].nice=0;
    p[3].bt=8;
    p[3].nice=1;
    p[4].bt=1;
    p[4].nice=0;
    cout<<"RESULT RR"<<endl;
    process * new_p =process::copy(p);
    //process::displayAll(new_p);
    process::assignWaitTurnAroundTimeRR(new_p,10);
    reset_burst_time(p,new_p);
    process::displayAll(new_p);
    cout<<"END RESULT RR"<<endl;
    cout<<"RESULT PS"<<endl;
    new_p =process::copy(p);
    process::assignWaitTurnAroundTimePS(new_p);
    process::displayAll(new_p);
    cout<<"END RESULT PS"<<endl;
    return 0;
}
