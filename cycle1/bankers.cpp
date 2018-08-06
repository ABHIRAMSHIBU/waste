//Author Abhiram Shibu Copyleft 2018
#include<iostream>
using namespace std;
class process{
public:
    static int resourceCount;
    static int numberOfProcesses;
    static int * totalResource;
    static int * available;
    int * needMat;
    int * maxMat;
    int * allocatedMat;
    int * resources;
    static void calcNeedAllocation(process p){
        p.needMat = new int[process::resourceCount];
        for(int i=0;i<resourceCount;i++){
            p.needMat[i]=p.maxMat[i]-p.allocatedMat[i];
        }
    }
    process(int pid){
        cout<<"Enter max Request matrix for pid "<<pid<<":";
        maxMat = new int[process::resourceCount]; 
        for(int i=0;i<process::resourceCount;i++){
            cin>>process::maxMat[i];
            cout<<"Loop :"
                <<i
                <<endl;
        }
        cout<<"Enter allocated matrix for pid "<<pid<<":";
        allocatedMat = new int[process::resourceCount]; 
        for(int i=0;i<process::resourceCount;i++){
            cin>>process::maxMat[i];
        }
    }
};
int * process::totalResource;
int process::resourceCount;
int * process::available;
int process::numberOfProcesses;
// process::totalResource;
int main(){
    cout<<"Enter number of processes:";
    int n;
    cin>>n;
    process::numberOfProcesses=n;
    cout<<"Enter maximum resources:";
    int max;
    cin>>max;
    process::resourceCount=max;
    process::totalResource=new int[max];
    cout<<"Enter Total Resource:";
    for(int i=0;i<max;i++)
        cin>>process::totalResource[i];
    for(int i=0;i<max;i++)
        cout<<process::totalResource[i]<<" ";
    cout<<endl;
    process::available=new int[max];
    cout<<"Enter Total Resource Available:";
    for(int i=0;i<max;i++)
        cin>>process::available[i];
    for(int i=0;i<max;i++)
        cout<<process::available[i]<<" ";
    cout<<endl;
    process * p = new process(2);
}