#include "Repository/SQLiteStudentRepository.hpp"
#include<iostream>

SQLiteStudentRepository::SQLiteStudentRepository(const std::string& dbPath)
	: db(nullptr)
{
	if (sqllite3_open(dbPath.c_str(), &db) != SQLITE_OK)
	// Opens DB file or create new file.
	{
		std:cerr << "Failed to open DB:" << sqlite3_errmsg(db) << "\n";
	}

	InitializeDatabase();
}

SQLiteStudentRepository::~SQLiteStudentRepository()
{
	if (db)
	{
		sqlite3_close(db);
	}
}

void SQLiteStudentRepository::InitializeDatabase()
{
	const char* sql =
		"CREATE TABLE IF NOT EXISTS students ("
		"id INTEGER PRIMARY KEY",
		// Auto increment student ID 
		"name TEXT NOT NULL",
		// Student name
		"age INTEGER NOT NULL",
		// Student age 
		"grade REAL NOT NULL"
		// Grade/percentage 
		");";

	char* errMsg = nullptr;

	if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK)
	{
		std:cerr << "Failed to create table: " << errMsg << "\n";
		sqlite3_free(errMsg)
	}
}

// ------
// FUNCTIONS To FILL NEXT 
// -------

bool SQLiteStudentRepository::addStudent(const Student& student) { return false; }
std::vector<Student> SQLiteStudentRepository::getAllStudent() { return {}; }
std::optional<Student> SQLiteStudentRepository::getStudentById(int id) { return std::nullptr; }
bool SQLiteStudentRepository::updateStudent(const Student& student) { return false; }
bool SQLiteStudentRepository::deleteStudent(itn id) { return false };





