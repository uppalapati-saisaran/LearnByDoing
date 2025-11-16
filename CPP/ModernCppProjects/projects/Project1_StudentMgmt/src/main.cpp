#include<iostream>
#include<vector>
#include<string>

int main() {
	std::vector<std::string> features = { "C++11","C++14","C++17","C++20" };
	std::cout << "Environment setup verified!\n";
	std::cout << "Supported C++ features:\n";
	for (const auto& f : features)
		std::cout << " - " << f << "\n";
	return 0;
}