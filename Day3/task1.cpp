//Day3 task 1
#include <iostream>
#include <fstream>
#include <regex>
#include <string>


int main(){
	std::ifstream input("input.txt");
	std::string a;
	std::regex numbers("#([0-9])+ @ ([0-9]+),([0-9]+): ([0-9]+)x([0-9]+)");
	int grid[1000][1000] = {};
	int x,y,w,h;
	int counter= 0;
	while(getline(input,a)){
		x = std::stoi(std::regex_replace(a, numbers, "$2"));
		y = std::stoi(std::regex_replace(a, numbers, "$3"));
		w = std::stoi(std::regex_replace(a, numbers, "$4"));
		h = std::stoi(std::regex_replace(a, numbers, "$5"));
		
		for(int i = x; i < x+w; i++){
			for(int j = y; j < y+h; j++){
				grid[i][j] += 1;
				if(grid[i][j] == 2){
					counter++;
				}
			}			
		}
	}
	
	std::cout << counter << std::endl;
	
	//std::cout << x << y << w << h << std::endl;

	
}