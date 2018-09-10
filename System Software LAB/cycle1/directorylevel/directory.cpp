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
node singleLevel(string rootName){
	node masterDir=createDirectory(rootName);
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
	for(int i=0;i<temp;i++){
		cout<<"Enter  name of a the directory:";
		string name;
		cin>>name;
		bool detect=false;
		for(int j=0;j<masterDir.in->size();j++){
			if(masterDir.in->at(j).name==name){
				cout<<"Error adding directory, name conflict"<<endl;
				i--;
				detect=true;
			}
		}
		if(!detect){
			masterDir.in->push_back(singleLevel(name));
		}
	}
	return masterDir;
}
node insertDir(node masterDir,string name){
	bool detect=true;
	for(int i=0;i<masterDir.in->size();i++){
		if(masterDir.in->at(i).name==name){
			detect=false;
			break;
		}
	}
	if(detect){
		masterDir.in->push_back(singleLevel(name));
	}
	else{
		cout<<"Directory exists"<<endl;
	}
	return masterDir;
}
node insertFile(node masterDir,string name){
	bool detect=true;
	for(int i=0;i<masterDir.in->size();i++){
		if(masterDir.in->at(i).name==name){
			detect=false;
			break;
		}
	}
	if(detect){
		masterDir.in->push_back(createFile(name));
	}
	else{
		cout<<"File exists"<<endl;
	}
	return masterDir;
}
node insertFileMulti(node masterDir,string dirName,string fileName){
	for(int i=0;i<masterDir.in->size();i++){
		if(masterDir.in->at(i).name==dirName){
			bool detect = true;
			for(int j=0;j<masterDir.in->at(i).in->size();j++){
				if(masterDir.in->at(i).in->at(j).name==fileName){
					detect=false;
					break;
				}
			}
			if(detect){
				masterDir.in->at(i).in->push_back(createFile(fileName));
			}
		}
	}
	return masterDir;
}
void remDir(node * masterDir,string name){
	bool flag=true;
	for(int i=0;i<masterDir->in->size();i++){
		if(masterDir->in->at(i).name==name){
			cout<<"All files in this directory will be purged!!!"<<endl;
			cout<<"Do you want to continue?[y/n]:";
			char input;
			cin>>input;
			if(input=='y'||input=='Y'||input=='1'){
				masterDir->in->erase(masterDir->in->begin()+i);
				cout<<"Removed "<<name<<endl;
			}
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"No such directory"<<endl;
	}
}
void remFile(node * masterDir,string name){
	bool flag=true;
	for(int i=0;i<masterDir->in->size();i++){
		if(masterDir->in->at(i).name==name){
			masterDir->in->erase(masterDir->in->begin()+i);
			cout<<"Removed "<<name<<endl;
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"No such file"<<endl;
	}
}
void mvFile(node * masterDir,string from,string to){
	bool fromExists=false;
	int fromRelativeID=-1;
	int toRelativeID=-1;
	bool toExists=false;
	for(int i=0;i<masterDir->in->size();i++){
		if(masterDir->in->at(i).name==from){
			fromExists=true;
			fromRelativeID=i;
		}
		if(masterDir->in->at(i).name==to){
			toExists=true;
			toRelativeID=i;
		}
		if(fromExists && toExists){
			break;
		}
	}
	if(fromExists){
		if(toExists){
			cout<<"Replacing already existing!"<<endl;
			masterDir->in->at(toRelativeID)=masterDir->in->at(fromRelativeID);
			masterDir->in->at(toRelativeID).name=to;
			masterDir->in->erase(masterDir->in->begin()+fromRelativeID);
		}
		else{
			masterDir->in->at(fromRelativeID).name=to;
			masterDir->in->push_back(masterDir->in->at(fromRelativeID));
			masterDir->in->erase(masterDir->in->begin()+fromRelativeID);
		}
	}
	else{
		cout<<"No such file"<<endl;
		cout<<fromExists<<toExists<<endl;
	}
}
void mvFileMulti(node * masterDir,string from, string to){
	string fromDir= from.substr(0,from.find('/'));
	int fromDirRelativeID=-1;
	bool fromDirExists=false;
	string fromFile= from.substr(from.find('/')+1);
	int fromFileRelativeID=-1;
	bool fromFileExists=false;
	string toDir= to.substr(0,to.find('/'));
	int toDirRelativeID=-1;
	bool toDirExists=false;
	string toFile= to.substr(to.find('/')+1);
	int toFileRelativeID=-1;
	bool toFileExists=false;
	for(int i=0;i<masterDir->in->size();i++){
		if(masterDir->in->at(i).name==fromDir){
			fromDirExists=true;
			fromDirRelativeID=i;
			for(int j=0;j<masterDir->in->at(i).in->size();j++){
				if(masterDir->in->at(i).in->at(j).name==fromFile){
					fromFileExists=true;
					fromFileRelativeID=j;
				}
			}
		}
		if(masterDir->in->at(i).name==toDir){
			toDirExists=true;
			toDirRelativeID=i;
			for(int j=0;j<masterDir->in->at(i).in->size();j++){
				if(masterDir->in->at(i).in->at(j).name==toFile){
					toFileExists=true;
					toFileRelativeID=j;
				}
			}
		}
		if(fromDirExists && toDirExists){
			break;
		}
	}
	if(fromDirExists && fromFileExists && toDirExists && toFileExists){
		cout<<"Target file exists, Replacing"<<endl;
		masterDir->in->at(toDirRelativeID).in->at(toFileRelativeID)
				= masterDir->in->at(fromDirRelativeID).in->at(fromFileRelativeID);
		masterDir->in->at(fromDirRelativeID).in->erase(
				masterDir->in->at(fromDirRelativeID).in->begin()+fromFileRelativeID);
	}
	else if(fromDirExists && fromFileExists && toDirExists){
		masterDir->in->at(toDirRelativeID).in->push_back(
				masterDir->in->at(fromDirRelativeID).in->at(fromFileRelativeID));
		masterDir->in->at(fromDirRelativeID).in->erase(
					masterDir->in->at(fromDirRelativeID).in->begin()+fromFileRelativeID);
	}
	else if(fromDirExists && fromFileExists){
		cout<<"No such dir "<<toDir<<endl;
	}
	else if(fromDirExists){
		cout<<"No such file "<<fromFile<<endl;
	}
	else if(!fromDirExists){
		cout<<"No such dir "<<fromDir<<endl;
	}
	cout<<fromDirExists<<fromFileExists<<toDirExists<<toFileExists<<endl;
}
void remFileMulti(node * masterDir,string dirName,string fileName){
	bool flag=true;
	for(int i=0;i<masterDir->in->size();i++){
		if(masterDir->in->at(i).name==dirName){
			for(int j=0;j<masterDir->in->at(i).in->size();j++){
				if(masterDir->in->at(i).in->at(j).name==fileName){
					masterDir->in->erase(masterDir->in->at(i).in->begin()+j);
					cout<<"Removed "<<dirName<<"/"<<fileName<<endl;
					flag=false;
					break;
				}
			}
			break;
		}
	}
	if(flag){
		cout<<"No such file"<<endl;
	}
}
void print(node);
void processCMD(node  head){
	node current = head;
	cout<<"Command Line v1.0"<<endl;
	while(true){
		cout<<">";
		string in;
		getline(cin,in);
		if(in=="help" || in == "hp"){
			cout<<"-------------HELP----------------"<<endl;
			cout<<"hp               Displays Help"<<endl;
			cout<<"cd <path>        Change path"<<endl;
			cout<<"ls <path>        List path"<<endl;
			cout<<"rm <path>        Removes path"<<endl;
			cout<<"mv <path> <path> Moves path"<<endl;
			cout<<"mk <path>        Creates dir/file"<<endl;
			cout<<"exit             Exits Interpreter"<<endl;
			cout<<"-----------END HELP--------------"<<endl;
		}
		else if(in.substr(0,2)=="cd"){
			string process=in.substr(3);
			cout<<"Paramenter is:"<<process<<endl;
			if(process=="root"){
				current=head;
			}
			else if(process=="/"){
				cout<<"Use of / is depricated, use root instead"<<endl;
				cout<<"No change"<<endl;
			}
			else{
				node * temp;
				for(int i=0;i<current.in->size();i++){
					if(current.in->at(i).name==process){
						current=current.in->at(i);
						cout<<"Changing current dir"<<endl;
						break;
					}
				}
			}
		}
		else if(in.substr(0,2)=="mk"){
			if(current.name!="root"){ //In a dir
				insertFile(current,in.substr(3));
			}
			else{
				insertDir(current,in.substr(3));
			}
		}
		else if(in.substr(0,2)=="mv"){
			string data=in.substr(3);
			string from=data.substr(0,data.find(' '));
			string to=data.substr(data.find(' ')+1);
			if(current.name=="root"){
				mvFileMulti(&current,from,to);
			}
			else{
				mvFile(&current,from,to);
			}
		}
		else if(in.substr(0,2)=="rm"){
			if(current.name=="root"){
				remDir(&current,in.substr(3));
			}
			else{
				remFile(&current,in.substr(3));
			}
		}
		else if(in=="ls"){
			print(current);
		}
		else if(in=="exit"){
			cout<<"bye..";
			break;
		}
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
	bool file=true;
	if(masterDir.name=="root"){
		file=false;
	}
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
	cout<<"_____________END MASTER DIR_____________"<<endl<<endl;
	if(!file){
		for(int i=0;i<masterDir.in->size();i++){
			node current1=masterDir.in->at(i);
			cout<<"___________"<<current1.name<<" DIR____________"<<endl;
			for(int j=0;j<current1.in->size();j++){
					node current=current1.in->at(j);
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
			cout<<"________END "<<current1.name<<" DIR__________"<<endl<<endl;
		}
	}
}
int main() {
	node masterDir=multiLevel();
	processCMD(masterDir);
	//print(masterDir);
}
