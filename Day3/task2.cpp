//Day3 task 2
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
struct rect{
	int id, x, y, w, h;
};

int main(){
	std::ifstream input("input.txt");
	std::string a;
	std::regex numbers("#([0-9]+) @ ([0-9]+),([0-9]+): ([0-9]+)x([0-9]+)");
	std::vector<rect> rects;
	int grid[1000][1000] = {};
	int x,y,w,h,id;
	while(getline(input,a)){
		id = std::stoi(std::regex_replace(a, numbers, "$1"));
		x = std::stoi(std::regex_replace(a, numbers, "$2"));
		y = std::stoi(std::regex_replace(a, numbers, "$3"));
		w = std::stoi(std::regex_replace(a, numbers, "$4"));
		h = std::stoi(std::regex_replace(a, numbers, "$5"));
		rect r = {id, x, y, w, h};
		rects.push_back(r);
		for(int i = x; i < x+w; i++){
			for(int j = y; j < y+h; j++){
				grid[i][j] += 1;
			}			
		}
	}
	bool correct = true;
	for(rect r : rects){
		correct = true;
		for(int i = r.x; i < r.x+r.w; i++){
			for(int j = r.y; j < r.y+r.h; j++){
				if(!(grid[i][j]==1)){correct=false;} 
			}			
		}
		if(correct){
			std::cout << "this has no overlap:" << r.id << " " << r.x << " " << r.y << " " << r.w << " " << r.h << " " << std::endl;
		}
	}
}