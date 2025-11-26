/***
Inteface segregation principle 
Dependency inversion principle 
Repository pattern
***/

#pragma once 
// Prevents multiple inclusion of the same file - a header guard 
#include<vector>
#include<optional>
#include "Student.hpp"

class IStudentRepository {
/*
Starts with I to indicate "Interface"
Provides pure virtual funcions
No data members 
No implementation 
*/
public:
	virtual ~IStudentRepository() = default;

	//Add a student - returns true if inserted successfui.
	virtual bool addStudent(const Student& student) = 0;

	//Get all students
	virtual std::vector<student> getAllStudents() = 0;

	//Find student by ID optional because it may not exist
	viruatl optional<Student> getStudentById(int id) = 0;
	/**
	Because sometimes a student may NOT exist
	Real world repositories always use Optional/maybe types. 
	**/

	// Update a student - returns True if updated 
	virtual bool updateStudent(const Student& student) = 0;

	//Delete student - returns true if deleted 
	virtual bool deleteStudent(int id) = 0;
};

