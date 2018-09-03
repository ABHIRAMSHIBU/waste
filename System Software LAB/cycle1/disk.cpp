/*
 * disk.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: abhiram
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<list>
using namespace std;
vector<int> Q;
int start;
void printAllVector(vector<int> v){
	for(long i=0;i<v.size();i++){
		cout<<v.at(i)<<endl;
	}
}
void getQ(){
	int temp;
	cout<<"How many in the queue (n):";
	cin>>temp;
	for(int i=temp;i>0;i--){
		cout<<"Enter the disk cylinder :";
		cin>>temp;
		Q.push_back(temp);
	}
	cout<<"Enter start location:";
	cin>>start;
}
void fcfs(){
	int seektime=0;
	int head=start;
	vector<int> seekVector;
	for(int i=0;i<Q.size();i++){
		seektime+=abs(Q.at(i)-head);
		seekVector.push_back(abs(Q.at(i)-head));
		head=Q.at(i);
	}
	cout<<"Total seek time with FCFS is:"<<seektime<<" units"<<endl;
	cout<<"Average seek time with FCFS is:"<<(seektime/seekVector.size())<<" units"<<endl;
}
void fcfs(vector<int> Q){
	int seektime=0;
	int head=start;
	vector<int> seekVector;
	for(int i=0;i<Q.size();i++){
		seektime+=abs(Q.at(i)-head);
		seekVector.push_back(abs(Q.at(i)-head));
		head=Q.at(i);
	}
	cout<<"Total seek time is:"<<seektime<<" units"<<endl;
	cout<<"Average seek time is:"<<(seektime/seekVector.size())<<" units"<<endl;
}
void scan(){
	int seektime=0;
	int head=start;
	vector<int> Q_temp=Q;
	cout<<"Enter head direction:[L/R]";
	char direction;
	cin>>direction;
	cout<<"Enter disk max cylinder:";
	int diskMAX;
	cin>>diskMAX;
	if(direction=='L' || direction=='l' || direction=='1'){
		int min=0;
		int max=0;
		for(int i=0;i<Q_temp.size();i++){
			if(max<Q_temp.at(i)){
				max=Q_temp.at(i);
			}
		}
		while(Q_temp.size()>0){
			min=max;
			int pos=-1;
			for(int i=0;i<Q_temp.size();i++){
				if(Q_temp.at(i)<head){
					if(abs(head-Q_temp.at(i))<min){
						min=abs(head-Q_temp.at(i));
						pos=i;
					}
				}
			}
			if(pos!=-1){
				seektime+=min;
				head=Q_temp.at(pos);
			}
			Q_temp.erase(Q_temp.begin()+pos);
			if(pos==-1){
				if(head!=0){
					seektime+=head;
				}
				while(Q_temp.size()>0){
					min=max;
					pos=-1;
					for(int i=0;i<Q_temp.size();i++){
						if(Q_temp.at(i)>head){
							if(abs(head-Q_temp.at(i))<min){
								min=abs(head-Q_temp.at(i));
								pos=i;
							}
						}
					}
					if(pos!=-1){
						seektime+=min;
						head=Q_temp.at(pos);
						Q_temp.erase(Q_temp.begin()+pos);
					}
					if(pos==-1){
						if(head!=diskMAX){
							seektime+=diskMAX-head;
						}
					}
				}
				cout<<Q_temp.size()<<endl;
			}
			cout<<Q_temp.size()<<endl;
		}
	}
	else{
		int min=0;
		int max=0;
		for(int i=0;i<Q_temp.size();i++){
			if(max<Q_temp.at(i)){
				max=Q_temp.at(i);
			}
		}
		while(Q_temp.size()>0){
			min=max;
			int pos=-1;
			for(int i=0;i<Q_temp.size();i++){
				if(Q_temp.at(i)>head){
					if(abs(head-Q_temp.at(i))<min){
						min=abs(head-Q_temp.at(i));
						pos=i;
					}
				}
			}
			if(pos!=-1){
				seektime+=min;
				head=Q_temp.at(pos);
				Q_temp.erase(Q_temp.begin()+pos);
			}
			if(pos==-1){
				if(head!=diskMAX){
					seektime+=diskMAX-head;
				}
				while(Q_temp.size()>0){
					min=max;
					pos=-1;
					for(int i=0;i<Q_temp.size();i++){
						if(Q_temp.at(i)<head){
							if(abs(head-Q_temp.at(i))<min){
								min=abs(head-Q_temp.at(i));
								pos=i;
							}
						}
					}
					if(pos!=-1){
						seektime+=min;
						head=Q_temp.at(pos);
						Q_temp.erase(Q_temp.begin()+pos);
					}
					if(pos==-1){
						if(head!=0){
							seektime+=head;
						}
					}
					cout<<Q_temp.size()<<endl;
				}
			}
			cout<<Q_temp.size()<<endl;
		}
	}
}
vector<int> scanStringCreator(){
	int seektime=0;
	int head=start;
	vector<int> Q_temp=Q;
	cout<<"Enter head direction:[L/U]";
	char direction;
	cin>>direction;
	cout<<"Enter disk max cylinder:";
	int diskMAX;
	cin>>diskMAX;
	if(direction=='L' || direction=='l' || direction=='1'){
		list<int> l;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)<=head){
				l.push_back((Q_temp.at(i)));
			}
		}
		l.sort();
		l.reverse();
		vector<int> v(l.begin(),l.end());
		bool trigger=false;
		for(int i=0;i<v.size();i++){
			if(v.at(i)==0){
				trigger=true;
			}
		}
		if(!trigger){
			l.push_back(0);
			l.sort();
			l.reverse();
			vector<int> z(l.begin(),l.end());
			v=z;
		}
		list<int> k;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)>head){
				k.push_back((Q_temp.at(i)));
			}
		}
		k.sort();
		vector<int> v1(k.begin(),k.end());
		for(int i=0;i<v1.size();i++){
			v.push_back(v1.at(i));
		}

		cout<<"Stored vector is"<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v.at(i)<<"\t";
		}
		cout<<endl;

		return v;
	}
	else{
		list<int> l;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)>=head){
				l.push_back((Q_temp.at(i)));
			}
		}
		l.sort();
		//l.reverse();
		vector<int> v(l.begin(),l.end());
		bool trigger=false;
		for(int i=0;i<v.size();i++){
			if(v.at(i)==diskMAX){
				trigger=true;
			}
		}
		if(!trigger){
			l.push_back(diskMAX);
			l.sort();
			//l.reverse();
			vector<int> z(l.begin(),l.end());
			v=z;
		}
		list<int> k;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)<head){
				k.push_back((Q_temp.at(i)));
			}
		}
		k.sort();
		k.reverse();
		vector<int> v1(k.begin(),k.end());
		for(int i=0;i<v1.size();i++){
			v.push_back(v1.at(i));
		}

		cout<<"Stored vector is"<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v.at(i)<<"\t";
		}
		cout<<endl;

		return v;
	}
}
void new_scan(){
	fcfs(scanStringCreator());
}


vector<int> cscanStringCreator(){
	int seektime=0;
	int head=start;
	vector<int> Q_temp=Q;
	cout<<"Enter head direction:[L/U]";
	char direction;
	cin>>direction;
	cout<<"Enter disk max cylinder:";
	int diskMAX;
	cin>>diskMAX;
	if(direction=='L' || direction=='l' || direction=='1'){
		list<int> l;
		vector<int> erase;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)<=head){
				l.push_back((Q_temp.at(i)));
				erase.push_back(i);
			}
		}
		int offset=0;
		for(int i=0;i<erase.size();i++){
			Q_temp.erase(Q_temp.begin()+erase.at(i)-offset);
			offset++;
		}
		l.sort();
		l.reverse();
		vector<int> v(l.begin(),l.end());
		bool trigger=false;
		for(int i=0;i<v.size();i++){
			if(v.at(i)==0){
				trigger=true;
			}
		}
		if(!trigger){
			l.push_back(0);
			l.sort();
			l.reverse();
			vector<int> z(l.begin(),l.end());
			v=z;
		}
		if(Q_temp.size()){
			v.push_back(diskMAX);
			head=diskMAX;
		}

		list<int> k;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)<head){
				k.push_back((Q_temp.at(i)));
			}
		}
		k.sort();
		k.reverse();
		vector<int> v1(k.begin(),k.end());
		for(int i=0;i<v1.size();i++){
			v.push_back(v1.at(i));
		}
		cout<<"Stored vector is"<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v.at(i)<<"\t";
		}
		cout<<endl;


		return v;
	}



	else{
		list<int> l;
		vector<int> erase;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)>=head){
				l.push_back((Q_temp.at(i)));
				erase.push_back(i);
			}
		}
		int offset=0;
		for(int i=0;i<erase.size();i++){
			Q_temp.erase(Q_temp.begin()+erase.at(i)-offset);
			offset++;
		}
		l.sort();
		//l.reverse();
		vector<int> v(l.begin(),l.end());
		bool trigger=false;
		for(int i=0;i<v.size();i++){
			if(v.at(i)==diskMAX){
				trigger=true;
			}
		}
		if(!trigger){
			l.push_back(diskMAX);
			l.sort();
			//l.reverse();
			vector<int> z(l.begin(),l.end());
			v=z;
		}
		if(Q_temp.size()){
			v.push_back(0);
			head=0;
		}

		list<int> k;
		for(int i=0;i<Q_temp.size();i++){
			if(Q_temp.at(i)>head){
				k.push_back((Q_temp.at(i)));
			}
		}
		k.sort();
		//k.reverse();
		vector<int> v1(k.begin(),k.end());
		for(int i=0;i<v1.size();i++){
			v.push_back(v1.at(i));
		}
		cout<<"Stored vector is"<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v.at(i)<<"\t";
		}
		cout<<endl;


		return v;
	}
}

void cscan(){
	fcfs(cscanStringCreator());
}

int main(){
	getQ();
	fcfs();
	new_scan();
	cscan();

}



