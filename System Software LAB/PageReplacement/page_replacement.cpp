#include <iostream>
#include<stdlib.h>
#include<vector>
#include<iomanip>
using namespace std;
class Memory{
	public :
		int *cache;
		int n;
		Memory(int n){ //creating a cache with n blocks
			this->n=n;
			cache_full=0;
			cache=(int *) malloc(n*sizeof(int));
			for(int i=0;i<n;i++){
				cache[i]=0;
			}
		}
		Memory(int n,Memory m){ //copy constructor for debugging -> remove later
			this->n=n;
			cache_full=0;
			cache=(int *) malloc(n*sizeof(int));
			for(int i=0;i<n;i++){
				this->cache[i]=m.cache[i];
			}
		}
		int cache_full;
		int full(){ //returns 0 if cache is not full, returns 1 if cache is full
			cache_full=1;
			for(int i=0;i<n;i++){
				if(cache[i]==0){
					cache_full=0;
				//	cout<<"NOT FULL"<<endl;
					break;
				}
			}
			return cache_full;
		}
};
void display_cache_states(int cache_size,std::vector<Memory> cache_states){ //works perfectly 
	// to display the cache states nicely
	cout<<"The different cache states are "<<endl;
	for(int j=0;j<cache_size;j++){
			for(int i=0;i<cache_states.size();i++){
				if(cache_states[i].cache[j]==0){
					cout<<"."<<setw(6);
					continue;
				}
				std::cout<<cache_states[i].cache[j]<<setw(6);

			}
			cout<<"\n";
	}

}
void page_replace(int algorithm,int cache_size,vector<int> page_string,vector<Memory> cache_states){ //works perfectly
	std::cout << "FIFO" << '\n';
	Memory *temp;
	int page_faults=0;
	int n=page_string.size();
	int current_page;
	int present_already=0;
	int changing_index=0;
	temp=new Memory(cache_size);
	for(int i=0;i<n;i++){
		if(cache_states.size()!=0){
			temp= new Memory(cache_size,*temp);
		}
		present_already=0;
		current_page=page_string[i];
		for(int j=0;j<cache_size;j++){
			if(current_page==temp->cache[j]){
				present_already=1;
			}
		}
		vector <int> lru_stack;
		int temp_value;
		if(present_already==1){
			// cout<<current_page<<"present already"<<endl;
			//cout<<"full is "<<temp->full()<<endl;
			cache_states.push_back(*temp);
			if(algorithm==2){
				int pos=-1;
				for(int k=0;k<cache_size;k++){
					if(lru_stack.size()>0){
						if(lru_stack[i]==page_string[i]){
							pos=k;
							break;
						}
					}
				}
				temp_value=lru_stack[pos];
				lru_stack.erase(lru_stack.begin()+pos);
			}
			continue;


		}
		else{

			if(temp->full()==0){
			//	cout<<"Empty still present"<<endl;
				temp->cache[changing_index]=current_page;
				lru_stack.push_back(changing_index);
				changing_index=(changing_index+1)%cache_size;
			}
			else if(temp->full()==1){
					// std::cout <<current_page<<"Not present " << '\n';
					// cout<<"\nchanging index->"<<changing_index<<"\n";
					if(algorithm==1){
						temp->cache[changing_index]=current_page;
						changing_index=(changing_index+1)%cache_size;
					}
					else if(algorithm==2){
					// 	int no_block=0;
					// 	int can_break=0;
					// 	for(int k=i;k>=0;k--){
					// 		for(int p=0;p<cache_size;p++){
					// 			if(temp->cache[p]==page_string[k]){
					// 				no_block++;
					// 				if(no_block==cache_size){
					// 					changing_index=k;
					// 					cout<<"broken for "<<page_string[i]<<" at "<<page_string[changing_index]<<"for count "<<no_block<<endl;
					// 					can_break=1;
					// 					break;
					// 				}
					// 			}
					//
					// 		}
					// 		if(can_break==1){
					// 			break;
					// 		}
					// 	}
					// 	cout<<"changing"<<endl;
					// 	temp->cache[changing_index]=current_page;
					//
					// }
					if(lru_stack.size()>0){
						changing_index=lru_stack[0];
					}
					temp->cache[changing_index]=current_page;

					}
			}
			page_faults+=1;

	}
		cache_states.push_back(*temp);
	}
	display_cache_states(cache_size,cache_states);
	cout<<"The no of page faults occurring = "<<page_faults<<endl;
}

int main() {
		vector <Memory> cache_states;
		vector <int> page_string;
		int cache_size;
                cout<<"Enter the cache size"<<endl;
                cin>>cache_size;
		cout<<"Enter the pages"<<"\n"<<"Enter -1 to stop"<<endl;
		int page;
		while(1){
			cout<<"Enter page: ";
			cin>>page;
			if(page==-1){
				break;
			}
			page_string.push_back(page);
		}
		cout<<"page string is \n";
		for(int i=0;i<page_string.size()-1;i++){
			cout<<page_string[i]<<",";
		}
		cout<<page_string[page_string.size()-1]<<endl;
		page_replace(2,cache_size,page_string,cache_states); // 1->FIFO 2->LRU
		cout<<"Thank you for using this pgm";
		return 0;

}
