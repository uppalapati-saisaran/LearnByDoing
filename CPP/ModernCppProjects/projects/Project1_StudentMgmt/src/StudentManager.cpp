#include "StudentManager.hpp"
#include <iostream>


void StudentManager::addStudent(const student& student) {
	students.push_back(student);
}

void StudentManager::showAllStudents() const {
	std::cout << "\n---student List--\n"; 
	for (const auto& student : students) {
		student.displayInfo(); // Delegation: calls student's method 
	}
}

