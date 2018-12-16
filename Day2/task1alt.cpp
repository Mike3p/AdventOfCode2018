//Day 2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

std::pair<bool, bool>checkWord(std::string a) { 
	std::pair<bool, bool> groups;
	groups = std::make_pair(false, false);
	std::string word = a;
	std::sort(word.begin(), word.end());
	int counter = 1;
	for(int i = 0; i < word.length(); i=i+1){
		if(word[i] == word[i+1]){
			counter++;
		}
		else{
			if(counter == 2) groups.first = true;
			if(counter == 3) groups.second = true;
			counter = 1;
		}
		
	}
	return groups;
	
}


int main(){
	std::ifstream input("input.txt");
	int two = 0;
	int three = 0;
	std::string a;
	std::vector<std::string> words;
	while(getline(input, a)){
		std::pair<bool,bool> res = checkWord(a);
		two = two + res.first;
		three = three + res.second;	
	}

	std::cout << two * three << std::endl;
	return 0;
		
}


