//AOC Day 1.2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
	std::ifstream input("input1.txt");
	std::vector<int> changes;
	std::unordered_set<int> seenFreqs;
	int a;
	int cFreq = 0;
	while(input >> a){
		changes.push_back(a);
	}
	/*for(std::vector<int>::iterator it = changes.begin(); it != changes.end(); ++it){
		std::cout << *it;
	}*/
	
	
	//this is similar to the above code
	while(true){
		for(auto i : changes){
			if(seenFreqs.find(cFreq)!=seenFreqs.end()){
				std::cout << cFreq;//std::endl;
				return 0;
			}
			else{
				//std::cout << "current freq " << cFreq;
				seenFreqs.insert(cFreq);
			}
			cFreq = cFreq + i;	//std::cout << i;
		}
	}
	
}