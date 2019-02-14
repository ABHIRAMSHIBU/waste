/*
 * Dining.cpp
 * CopyLeft 2018
 *  Created on: Oct 7, 2018
 *      Author: Abhiram Shibu
 */
/* Dining philosopher problem */
#include<iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
class dining{
public:
	struct philospher{
		bool *leftCS; // Is the chop stick [ Left ] available or not.
		bool *rightCS;// Is the chop stick [ Right ] available or not.
		bool eating;
		bool idle;
		bool hungry;
	};
	philospher p[5];
	dining(){
		bool * CS = new bool[5];
		for(int i=0;i<5;i++){
			p[i].eating=false;
			p[i].idle=true;
			p[i].hungry=false;
			p[i].leftCS=CS+(i%5);
			p[i].rightCS=CS+((i+1)%5);
			*(p[i].leftCS)=true;
			*(p[i].rightCS)=true;
		}
	}
	void eat(){
		for(int i=0;i<5;i++){
			if(*(p[i].leftCS) && *(p[i].rightCS) && p[i].hungry){
				*(p[i].leftCS)=false;
				*(p[i].rightCS)=false;
				p[i].eating=true;
				p[i].idle=false;
				p[i].hungry=false;
				cout<<i+1<<" eating"<<endl;
			}
		}
	}
	void status(){
		for(int i=0;i<5;i++){
			cout<<i<<" left="<<*(p[i].leftCS)<<" right="<<*(p[i].rightCS)
					<<" hungry="<<p[i].hungry<<" idle="<<p[i].idle<<endl;
		}
	}
	bool finish(int n){
		if(p[n].eating){
			*(p[n].leftCS)=true;
			*(p[n].rightCS)=true;
			p[n].eating=false;
			p[n].idle=true;
			p[n].hungry=false;
			return 0;
		}
		else{
			return 1;
		}
	}
	bool setHungry(int n){
		if(!(p[n].hungry)){
			p[n].hungry=true;
			return 0;
		}
		else{
			return 1;
		}
	}
};
void menu(dining d){
	start:
	cout<<"             Main Menu          "<<endl;
	cout<<"p      print"<<endl;
	cout<<"e      eat"<<endl;
	cout<<"f      finish"<<endl;
	cout<<"s      set hungry"<<endl;
	cout<<"h      Help"<<endl;
	cout<<"q      Quit"<<endl;
	cout<<"             END Menu           "<<endl;
	while(true){
		cout<<"Enter a choice:";
		char c;
		cin>>c;
		if(c=='q'||c=='Q'){
			cout<<"Bye..";
			break;
		}
		if(c=='p'||c=='P'){
			d.status();
		}
		else if(c=='h'||c=='H'){
			goto start;
		}
		else if(c=='e'||c=='E'){
			d.eat();
		}
		else if(c=='s'||c=='S'){
			while(true){
				cout<<"Which one?:[1-5]";
				int n;
				cin>>n;
				if(n>0&&n<6){
					if(d.setHungry(n-1)){
						cout<<"Already hungry"<<endl;
					}
					break;
				}
				cout<<"Wrong Choice! Try again"<<endl;
			}
		}
		else if(c=='f'||c=='F'){
			while(true){
				cout<<"Which one?:[1-5]";
				int n;
				cin>>n;
				if(n>0&&n<6){
					if(d.finish(n-1)){
						cout<<"Not eating"<<endl;
					}
					break;
				}
				cout<<"Wrong Choice! Try again"<<endl;
			}
		}
	}
}
int main(){
	dining d;
	menu(d);
}
