/*
 * producerconsumer.cpp
 *
 *  Created on: 17-Sep-2018
 *      Author: Abhiram S and Abhijith N Raj
 */
#include<iostream>
#include<vector>
using namespace std;
class memory{
private:
	vector<int> mem;
	int maxSize = 0;
public:
	memory(int size){
		maxSize=size;
	}
	void setBuffer(int size){
		maxSize=size;
	}
	bool add(int data){
		if(mem.size()<maxSize){
			mem.push_back(data);
			return true;
		}
		else{
			return false;
		}
	}
	int currentSize(){
		return mem.size();
	}
	int remove(){
		if(mem.size()>0){
			int temp = mem.at(0);
			mem.erase(mem.begin());
			return temp;
		}
		else{
			return -1;
		}
	}
	void displayAll(){
		cout<<"==========Data in Memory=========="<<endl;
		int i;
		for(i=0;i<mem.size();i++){
			cout<<mem.at(i)<<"\t";
		}
		for(i;i<maxSize;i++){
			cout<<"-"<<"\t";
		}
		cout<<endl<<"-----------------------------------"<<endl;
	}
}a(4);

class producer{
private:
	int count = 0;
public:
	void produce(){
		if(a.add(count)){
			count++;
			cout<<"Produced "<<count<<" Successfully!"<<endl;
		}
		else{
			cout<<"Buffer overflow... Not able to produce"<<endl;
		}
	}
	void produce(int n){
		for(int i=0;i<n;i++){
			produce();
		}
	}
};
class consumer{
public:
	void consume(){
		int temp=a.remove();
		if(temp>-1){
			cout<<"Consumed "<<temp<<endl;
		}
		else{
			cout<<"Buffer underflow, not able to consume"<<endl;
		}
	}
	void consume(int n){
		for(int i=0;i<n;i++){
			consume();
		}
	}
};
void menu(producer p,consumer c){
	cout<<"Producer consumer problem"<<endl;
	cout<<"p  produce"<<endl;
	cout<<"c  consume"<<endl;
	cout<<"o  output"<<endl;
	cout<<"b  set buffer size"<<endl;
	cout<<"e  exit"<<endl;
	char in;
	while(true){
		cout<<"Enter a choice:";
		cin>>in;
		if(in=='p'||in=='P'){
			cout<<"Enter number of items to produce:";
			int n;
			cin>>n;
			p.produce(n);
		}
		else if(in=='c'||in=='C'){
			cout<<"Enter number of items to consume:";
			int n;
			cin>>n;
			c.consume(n);
		}
		else if(in=='o'||in=='O'){
			a.displayAll();
		}
		else if(in=='e'||in=='E'){
			cout<<"Bye..."<<endl;
			break;
		}
		else if(in=='b'||in=='B'){
			cout<<"Enter buffer size"<<endl;
			int n;
			cin>>n;
			if(n<0){
				cout<<"Don't tease me"<<endl;
				continue;
			}
			if(n>a.currentSize()){
				a.setBuffer(n);
				cout<<"Operation successful"<<endl;
			}
			else{
				cout<<"Increasing is easy but decreasing is hard and im lazy"<<endl;
			}
		}
		else{
			cout<<"Invalid choice, please try again";
		}
	}
}
int main(){
	producer p;
	consumer c;
	menu(p,c);
}
