//Day 2
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

std::map<std::string,bool> checkWord(std::string a) { //returns 0 if nothing, 1 if double, 2 if triple and 3 if double and triple
	std::map<std::string,bool> result;
	result["dubs"] = false;
	result["trips"] = false;
	std::map<char, int> counter;
	for(char c : a){
		//std::cout << "current char: " << c << std::endl;
		if(counter.find(c)!=counter.end()){
			counter[c] = counter[c]+1;
		}
		else{
			counter.insert ( std::pair<char, int>(c,1));
		}
	}
	for(auto const& [key, value] : counter){
		if(value==2){
				result["dubs"] = true;
		}
		if(value==3){
				result["trips"] = true;
		}
	}
	return result;
}


int main(){
	std::ifstream input("input.txt");
	int two = 0;
	int three = 0;
	std::string a;
	std::vector<std::string> words;
	
	while(input >> a){
		words.push_back(a);
	}
	
	for(auto i : words){
		std::map<std::string,bool> x = checkWord(i);
		if(x["dubs"]){
		two= two +1;
		}
		if(x["trips"]){
		three=three+1;
		}
		std::cout << "Word: " << i << ", dubs: " << x["dubs"] << " trips: " << x["trips"] << " " << std::endl;
	}
	std::cout << two * three << std::endl;
	return 0;
		
}


