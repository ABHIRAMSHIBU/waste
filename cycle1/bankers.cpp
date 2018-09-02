/*
 * bankers.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: abhiram
 */

/* Header files */
#include<iostream>
#include<vector>

/* Definitions */
#define DEBUG true

/* std:: not working on eclipse so need this */
using namespace std;

/* Variable declarations */
int * available,resourceCount=-1,processCount=-1;
vector<int> * need, * maximum, * allocated;
bool safe=true;

/* Functions */
void printAllVector(vector<int> v){
	for(long i=0;i<v.size();i++){
		cout<<v.at(i)<<endl;
	}
}
void printAllMatrix(vector<int> * v){
	for(int i=0;i<processCount;i++){
		for(int j=0;j<resourceCount;j++){
			cout<<v[j].at(i)<<"\t";
		}
		cout<<endl;
	}
}
void computeNeedMatrix(){
	for(int i=0;i<resourceCount;i++){
		for(int j=0;j<processCount;j++){
			/* need = Max - allocated */
			need[i].push_back(maximum[i].at(j)-allocated[i].at(j));
		}
	}
}
void initalizeValues(){
	cout<<"Now we are going to input available resources"<<endl;
	for(int i=0;i<resourceCount;i++){
		cout<<"Enter resource "<<i<<" available :";
		cin>>available[i];
	}
	cout<<"Enter number of processes (total) :";
	cin>>processCount;
	cout<<"Okie Dokie"<<endl
		<<"Now we are going to fill in maximum need"<<endl;
	for(int i=0;i<processCount;i++){
		cout<<"This going to be matrix way "<<endl
			<<"Insert in this way, value by value"<<endl;
		for(int j=0;j<resourceCount;j++){
			int temp;
			cout<<"Enter process "<<i<<" resource "<<j<<" value:";
			cin>>temp;
			maximum[j].push_back(temp);
		}
	}
	cout<<"OO We are 75% in!"<<endl
		<<"Now we are going to fill in allocated matrix"<<endl;
	for(int i=0;i<processCount;i++){
		cout<<"This going to be matrix way "<<endl
			<<"Insert in this way, value by value"<<endl;
		for(int j=0;j<resourceCount;j++){
			int temp;
			cout<<"Enter process "<<i<<" resource "<<j<<" value:";
			cin>>temp;
			allocated[j].push_back(temp);
		}
	}
	cout<<"All set"<<endl
		<<"Now computing need matrix"<<endl;
	computeNeedMatrix();
}
void initalizeMatrix(){
	cout<<"Enter number of resources:";
	cin>>resourceCount;
	available = (int *)malloc(sizeof(int)*resourceCount);
	need = (vector<int> *)malloc(sizeof(vector<int>)*resourceCount);
	maximum = (vector<int> *)malloc(sizeof(vector<int>)*resourceCount);
	allocated = (vector<int> *)malloc(sizeof(vector<int>)*resourceCount);
	initalizeValues();
}
vector<int> safety(){
	vector<int> pending;
	vector<int> safeSequence;
	for(int i=0;i<processCount;i++){
		pending.push_back(i);
	}
	int pendingSize=pending.size();
	int tempAvailable[resourceCount];
	for(int i=0;i<resourceCount;i++){ //Copy available
		tempAvailable[i]=available[i];
	}
	while(pending.size()>0){
		for(int i=0;i<pending.size();i++){
			bool acceptable=true;
			for(int j=0;j<resourceCount;j++){
				if(need[j].at(pending.at(i))>tempAvailable[j]){
					acceptable=false;
				}
			}
			if(acceptable){
				for(int j=0;j<resourceCount;j++){
					tempAvailable[j]+=allocated[j].at(pending.at(i));
				}
				safeSequence.push_back(pending.at(i));
				pending.erase(pending.begin()+i);
			}
		}
		if(pending.size()==pendingSize){
			safe=false;
			break;
		}
		else{
			pendingSize=pending.size();
			safe=true;
		}
	}
	return safeSequence;
}
bool request(){
	bool success=true;
	cout<<"Request manipulation"<<endl;
	cout<<"Which process to manipulate:";
	int process;
	cin>>process;
	cout<<"Enter the request"<<endl;
	for(int i=0;i<resourceCount;i++){
		int temp;
		cout<<"Enter value for resource "<<i<<" for process "<<process<<" :";
		cin>>temp;
		need[i].at(process)-=temp;
		allocated[i].at(process)+=temp;
		available[i]-=temp;
		if(need[i].at(process)<0 || allocated[i].at(process)<0 || available[i]<0){
			success=false;
			need[i].at(process)+=temp;
			allocated[i].at(process)-=temp;
			available[i]+=temp;
		}
	}
	return success;
}
/* Main Function */
int main(){
	initalizeMatrix();
	cout<<"Printing need matrix"<<endl;
	printAllMatrix(need);
	cout<<"Printing maximum matrix"<<endl;
	printAllMatrix(maximum);
	cout<<"Printing allocated matrix"<<endl;
	printAllMatrix(allocated);
	vector<int> safeSequence = safety();
	if(safe){
		cout<<"ITS SAFE!"<<endl;
		cout<<"Safe sequence is"<<endl;
		printAllVector(safeSequence);
	}
	else{
		cout<<"NOT SAFE!"<<endl;
	}
	char input;
	while(true){
		cout<<"Do you want to add a request?[y/n]:";
		cin>>input;
		if(input=='Y'|| input=='y' || input == '1'){
				if(request()){
					vector<int> safeSequence = safety();
					if(safe){
						cout<<"ITS SAFE!"<<endl;
						cout<<"Safe sequence is"<<endl;
						printAllVector(safeSequence);
					}
					else{
						cout<<"NOT SAFE!"<<endl;
					}
				}
				else{
					cout<<"Request violating some condition"<<endl;
				}
		}
		else{
			cout<<"Bye..."<<endl;
			break;
		}
	}
}
