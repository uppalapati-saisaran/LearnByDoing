/***
#include<iostream>
#include<vector>
#include<string>
***/
#include "StudentManager.hpp"

int main() {
	/****
	std::vector<std::string> features = { "C++11","C++14","C++17","C++20" };
	std::cout << "Environment setup verified!\n";
	std::cout << "Supported C++ features:\n";
	for (const auto& f : features)
		std::cout << " - " << f << "\n";
	return 0;
	****/
	StudentManager manager;
	student s1("Alice", 20, 101);
	student s2("Bob", 21, 102);

	manager.addStudent(s1);
	manager.addStudent(s2);

	manager.showAllStudents();

	return 0;
}