/*
 * directory.cpp
 *
 *  Created on: 03-Sep-2018
 *      Author: abhiram
 */


#include<iostream>
#include<vector>
using namespace std;

int count=0; //Gives id to each and every file

/* Each node can be a file or a directory
 * which is determined by the type
 * if type is f, means file
 * if type is d, means directory
 * name contains the name of a file or directory
 * in is only used if there is directory
 */
struct node{
	char type;
	int id;
	string name;
	vector<node> *in;
};

/* To create a file,
 * id need to be assigned
 * name can be given as an argument,
 * returns a file ( node )
 */
node createFile(string name){
	node n ;
	//n.in=new vector<node>;
	n.id=count;
	count++;
	n.type='f';
	n.name=name;
	return n;
}

/* To create a directory,
 * id need to be assigned
 * name can be given as an argument,
 * returns a directory ( node )
 */
node createDirectory(string name){
	node n ;
	n.in=new vector<node>;
	n.id=count;
	count++;
	n.type='d';
	n.name=name;
	return n;
}

/* Creates a single level directory
 * populates it
 * returns a directory ( node )
 */
node singleLevel(){
	node masterDir=createDirectory("root");
	cout<<"Created master directory "<<count<<endl;
	cout<<"Enter number of files to create:";
	int temp;
	cin>>temp;
	for(int i=0;i<temp;i++){
		cout<<"Enter  name of a the file:";
		string name;
		cin>>name;
		bool detect=false;
		for(int j=0;j<masterDir.in->size();j++){
			if(masterDir.in->at(j).name==name){
				cout<<"Error adding file, name conflict"<<endl;
				i--;
				detect=true;
			}
		}
		if(!detect){
			masterDir.in->push_back(createFile(name));
		}
	}
	return masterDir;
}
node multiLevel(){
	node masterDir=createDirectory("root");
	cout<<"Enter number of directories:";
	int temp;
	cin>>temp;
	bool detect=false;
	for(int j=0;j<masterDir.in->size();j++){
		if(masterDir.in->at(j).name==name){
			cout<<"Error adding directory, name conflict"<<endl;
			i--;
			detect=true;
		}
	}
	if(!detect){
		masterDir.in->push_back(createDirectory(name));

	}
}

/* Print is still single level
 * moves into a directory
 * extracts the vector
 * treats as root and prints all the data
 */
void print(node masterDir){
	cout<<"_______________MASTER DIR_______________"<<endl;
	cout<<"Inode :"<<masterDir.in->size()<<endl;
	for(int i=0;i<masterDir.in->size();i++){
		node current=masterDir.in->at(i);
		cout<<current.name<<" ";
		if(current.type=='f'){
			cout<<"type_file ";
		}
		else{
			cout<<"type_dir ";
		}
		cout<<"id_"<<current.id<<" ";
		cout<<endl;
	}
	cout<<"_____________END MASTER DIR_____________"<<endl;
}
int main() {
	node masterDir=singleLevel();
	print(masterDir);
}



