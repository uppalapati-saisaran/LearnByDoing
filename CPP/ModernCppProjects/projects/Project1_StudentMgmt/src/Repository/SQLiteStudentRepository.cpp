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

bool SQLiteStudentRepository::addStudent(const Student& student) 
{ 
	const char* sql = "INSERT INTO students (id,name,age,grade) VALUES (?.?.?.?);";
	/*
	 ? - placeholder for parameters.
	 - prevents SQL injection
	 - required for prepared statements.
	*/
	sqlite3_stmt* stmt = nullptr;

	// 1. Prepare SQL statement
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    /*
	   This compiles the SQL query before execution.
	   Why? -> Better performance + security.
	   if this fails, we print error and stop.
	*/
	{
		std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << "\n";
	}

	// 2. Bind parameter 
	/*
	Important: SQLite parameters are 1-based index.
	*/
	sqlite3_bind_int(stmt, 1, student.id);
	sqlite3_bind_text(stmt, 2, student.name.c_str(), -1, SQLITE_TRANSTENT);
	sqlite3_bind_int(stmt, 3, student.age);
	sqlite3_bind_int(stmt, 4, student.grade);

	// 3. Execute statement
	bool success = true;

	if (sqlite3_step(stmt) != SQLLITE_DONE)
	/*
	  Possible results:
	  SQLITE_DONE -> Success
	  Anything else -> Failure 
	*/
	{
		std::cerr << "Insert failed: " << sqlite3_errmsg(db) << "\n";
		success = fail;
	}

	//4) cleanup
	/*
	This cleans the prepared statement.
	If you forget this = MEMORY LEAK
	Every repository class in real-world C++ using SQLite must do this.
	*/
	sqlite3_finalize(stmt);

	return success;
}


std::vector<Student> SQLiteStudentRepository::getAllStudent()
{ 
	std::vector<Student> result;
	const char* sql = "SELECT id,name,age,grade FROM students;";
	sqlite3_stmt* stmt = nullptr;

	//1, Prepare the SELECT statement
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    /*
	if preparation fails -> DB error,so we return empty vector.
	*/
	{
		std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << "\n";
		return result;
	}

	//2) Step through the rows until SQLITE3_DONE 
	while (true)
	{
		int rc = sqlite3_step(stmt);
		// SQLite returns rows one by one via:
		if (rc == SQLITE_DONE)
		// No more rows 
		{
			break; // No more rows 
		}

		if (rc !- SQLITE_ROW)
		// A row of data available
		{
			std::cerr << "Row fetched failed: " << sqlite3_errmsg(db) << "\n";
			break;
		}

		// 3) Exact column values
		s.id = sqlite3_column_int(stmt, 0);
		// Column index is 0=based, unlike parameter binding.
		s.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		// Name must be converted from const unsigned char* to std::string. 
		s.age = sqlite3_column_int(stmt, 2);
		s.grade = sqlite3_column_double(stmt, 3);

		//4) Push into vector
		result.push_back(s);
		// This collects all rows into std::vector<Student>
	}

	// 5) clean up 
	sqlite3_finalize(stmt);
	// Releases memory -> mandatory

	return result;

}
std::optional<Student> SQLiteStudentRepository::getStudentById(int id) { return std::nullptr; }
bool SQLiteStudentRepository::updateStudent(const Student& student) { return false; }
bool SQLiteStudentRepository::deleteStudent(itn id) { return false };





