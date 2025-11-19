#ifndef STUDENTMANAGER_HPP
#define STUDENTMANAGER_HPP 

#include<vector>
#include "Student.hpp"

class StudentManager {
private:
	std::vector<student> students; // composition: contains multiple student objects 
public:
	// Add a new student to the system. 
	void addStudent(const student& student);
	// Displays all students 
	void showAllStudents() const;
};

#endif 



