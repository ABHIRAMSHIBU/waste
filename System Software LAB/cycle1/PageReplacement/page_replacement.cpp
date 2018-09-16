#include <iostream>
#include<stdlib.h>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
class Memory {
public:
	int *cache;
	int n;
	Memory(int n) { //creating a cache with n blocks
		this->n = n;
		cache_full = 0;
		cache = (int *) malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			cache[i] = -10;
		}
	}
	Memory(int n, Memory m) { //copy constructor for debugging -> remove later
		this->n = n;
		cache_full = 0;
		cache = (int *) malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			this->cache[i] = m.cache[i];
		}
	}
	int cache_full;
	int full() { //returns 0 if cache is not full, returns 1 if cache is full
		cache_full = 1;
		for (int i = 0; i < n; i++) {
			if (cache[i] == -10) {
				cache_full = 0;
				break;
			}
		}
		return cache_full;
	}
};
void display_cache_states(int cache_size, std::vector<Memory> cache_states);

void LRU(int cache_size, vector<int> page_string, vector<Memory> cache_states) {
	int page_faults = 0;
	Memory m(cache_size);
	vector<int> lru_stack;
	for (int i = 0; i < page_string.size(); i++) {
		int temp_pos;
		if (m.full() == 0) {
			m.cache[i] = page_string[i];
			lru_stack.push_back(i);
			page_faults++;
		} else {
			int pos = -1;
			for (int j = 0; j < cache_size; j++) {
				if (m.cache[j] == page_string[i]) {
					pos = j;
					break;
				}
			}
			if (pos == -1) {
				m.cache[(lru_stack[0])] = page_string[i];
				lru_stack.erase(lru_stack.begin());
				lru_stack.push_back(i);
				page_faults++;
			} else {
				temp_pos = lru_stack[pos];
				lru_stack.erase(lru_stack.begin() + pos);
				lru_stack.push_back(temp_pos);
			}
		}
		Memory *temp_memory = new Memory(cache_size, m);
		cache_states.push_back(*temp_memory);
	}
	display_cache_states(cache_size, cache_states);
	cout << "\n" << "The no of page faults :" << page_faults << endl;
}
void display_cache_states(int cache_size, std::vector<Memory> cache_states) { //works perfectly
	// to display the cache states nicely
	cout << "The different cache states are " << endl;
	for (int j = 0; j < cache_size; j++) {
		for (int i = 0; i < cache_states.size(); i++) {
			if (cache_states[i].cache[j] == -10) {
				cout << "." << setw(6);
				continue;
			}
			std::cout << cache_states[i].cache[j] << setw(6);

		}
		cout << "\n";
	}

}

void FIFO(int cache_size, vector<int> page_string,
		vector<Memory> cache_states) {
	Memory *temp;
	int page_faults = 0;
	int n = page_string.size();
	int current_page;
	int present_already = 0;
	int changing_index = 0;
	temp = new Memory(cache_size);
	for (int i = 0; i < n; i++) {
		if (cache_states.size() != 0) {
			temp = new Memory(cache_size, *temp);
		}
		present_already = 0;
		current_page = page_string[i];
		for (int j = 0; j < cache_size; j++) {
			if (current_page == temp->cache[j]) {
				present_already = 1;
			}
		}
		int temp_value;
		if (present_already == 1) {
			cache_states.push_back(*temp);
			continue;

		} else {

			if (temp->full() == 0) {
				temp->cache[changing_index] = current_page;
				changing_index = (changing_index + 1) % cache_size;
			} else if (temp->full() == 1) {
				temp->cache[changing_index] = current_page;
				changing_index = (changing_index + 1) % cache_size;
			}
			page_faults += 1;

		}
		cache_states.push_back(*temp);
	}
	display_cache_states(cache_size, cache_states);
	cout << "The no of page faults occurring = " << page_faults << endl;
}
void LFU(int cache_size, vector<int> page_string, vector<Memory> cache_states) {
	Memory m(cache_size);
	int page_faults = 0;
	int count[cache_size];

	for (int i = 0; i < page_string.size(); i++) {
		if (m.full() == 0) {
			m.cache[i] = page_string[i];
			page_faults++;

		}
		int pos = -1;
		for (int j = 0; j < cache_size; j++) {
			if (m.cache[j] == page_string[i]) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			for (int j = 0; j < cache_size; j++) {
				count[j] = 0;
			}
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k < cache_size; k++) {
					if (page_string[j] == m.cache[k]) {
						count[k] += 1;
					}
				}
			}
			int lfu_index = 0;
			for (int j = 0; j < cache_size; j++) {
				if (count[j] <= count[lfu_index]) {
					lfu_index = j;
				}
			}
			m.cache[lfu_index] = page_string[i];
			page_faults++;
		}
		Memory *temp_state = new Memory(cache_size, m);
		cache_states.push_back(*temp_state);
	}
	display_cache_states(cache_size, cache_states);
	cout << "The no of page faults: " << page_faults << endl;
}
int main() {
	vector<Memory> cache_states;
	vector<int> page_string;
	int cache_size;
	cout << "Enter the cache size" << endl;
	cin >> cache_size;
	cout << "Enter the pages" << "\n" << "Enter -1 to stop" << endl;
	int page;
	while (1) {
		cout << "Enter page: ";
		cin >> page;
		if (page == -1) {
			break;
		}
		page_string.push_back(page);
	}
	cout << "page string is \n";
	for (int i = 0; i < page_string.size() - 1; i++) {
		cout << page_string[i] << ",";
	}
	cout << page_string[page_string.size() - 1] << endl;
	cout << "\nFIFO" << endl;
	FIFO(cache_size, page_string, cache_states);
	cout << "\nLRU" << endl;
	LRU(cache_size, page_string, cache_states);
	cout << endl << "LFU" << endl;
	LFU(cache_size, page_string, cache_states);
	cout << "Thank you for using this pgm";
	return 0;

}

