//AOC Day 1.2
#include <iostream>
#include <fstream>

int main() {
	std::ifstream input("input1.txt");
	int a;
	int b;
	while(input >> a){
		b = b + a;
	}
	std::cout << b << std::endl;
	return 0;
}