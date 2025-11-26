#pragma once 
#include "IStudentRepository.hpp"
#include<sqlite3.h>
#include<string>

class SQLiteStudentRepository : public IStudentRepository {
public:
	SQLiteStudentRepository(const std::string& dbPath);
	~SQLiteStudentRepository();

	bool addStudent(const Student& student) override;
	std::vector<Student> getAllStudent() override;
	std::optional<Student> getStudentById(int id) override;
	bool updateStudent(const Student& student) override;
	bool deleteStudent(int id) override;

private: 
	sqlite3* db; // the actual database connectin pointer
	/**
	Raw  pointer because sqlite3 C-API works like this 
	We manage it with RAII in constructor/destructor
	**/

	void InitializeDatabase(); // Creates the table if not exists 
	/**
	Runs CREATE TABLE IF NOT EZXISTS
	Ensure database is ready.
	**/
};