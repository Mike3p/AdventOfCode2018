//Day 2
#include <iostream>
#include <fstream>
#include <vector>

std::pair<bool, std::string>getCommon(std::string a, std::string b) {
	std::string result2 = "";
	bool result1 = false;
	int c = 0;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == b[i]){
			result2 += a[i];
		}else{
			c = c+1;
		}
	}
	if(c==1){
			result1 = true;
	}	
	return std::make_pair(result1,result2);
}

int main(){
	std::ifstream input("input.txt");
	std::string a;
	std::vector<std::string> words;
	while(input >> a){
		words.push_back(a);
	}
	std::pair<bool, std::string> result;
	for(int i = 0; i < words.size()-1;i++){
		for(int j = i+1; j < words.size();j++){
			result = getCommon(words[i], words[j]);
			if (result.first){
				std::cout << result.second << std::endl;
				return 0;
			}
		}
	}
	return 0;
}