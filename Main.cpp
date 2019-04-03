//Developed by Abhiram Shibu for college in the year 2019
#include<iostream>
#include<queue>
#define Version 1.0
#define True 1
#define False 0
using namespace std;
/* QSSQ Queue Sender Send Queue */
queue<int> initQSSQ(queue<int> senderSQ){
	for(int i=0;i<10;i++){
		senderSQ.push(i);
	}
	return senderSQ;
}
void senderSend(queue<int> * senderSQ,queue<int> * receiverRQ){
	if(!senderSQ->empty()){
		cout<<"Sending packet :"<<senderSQ->front()<<endl;
		receiverRQ->push(senderSQ->front());
		senderSQ->pop();
	}
}
void receverReceive(queue<int> * receiverRQ, queue<int> * senderRQ){
	if(!receiverRQ->empty()){
		cout<<"Received packet and placed an ack :"<<receiverRQ->front()<<endl;
		senderRQ->push(receiverRQ->front());
		receiverRQ->pop();
	}
}
void senderAckReceive(queue<int> * senderRQ){
	if(!senderRQ->empty()){
		cout<<"Ack received :"<<senderRQ->front()<<endl;
		senderRQ->pop();
	}
}
void stopAndWaitNoDelay(){
	queue<int> receverRQ,senderRQ,senderSQ;
	senderSQ=initQSSQ(senderSQ);
	cout<<senderSQ.empty()<<endl;
	while((!senderSQ.empty()) || (!receverRQ.empty()) || (!senderRQ.empty())){
		senderSend(&senderSQ,&receverRQ);
		receverReceive(&receverRQ,&senderRQ);
		senderAckReceive(&senderRQ);
	}
}
int main(){

	cout<<"Starting!"<<endl;
	/*
	 * RQ Receive Queue
	 * SQ Send Queue
	 */
	int DELAY=3;
	queue<int> receverRQ,senderRQ,senderSQ;
	senderSQ=initQSSQ(senderSQ);
	cout<<senderSQ.empty()<<endl;
	int i=0;
	while((!senderSQ.empty()) || (!receverRQ.empty()) || (!senderRQ.empty())){
		senderSend(&senderSQ,&receverRQ);
		if(i>=DELAY){
			receverReceive(&receverRQ,&senderRQ);
		}
		if(i>=DELAY*2){
			senderAckReceive(&senderRQ);
		}
		i++;
	}

}



