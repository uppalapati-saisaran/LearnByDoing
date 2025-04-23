//Task.h 
#ifndef TASK_H
#define TASK_H 

#include <iostream>
#include <string>

class Task {
public:
	int id;
	std::string title;
	bool isCompleted;

	Task(int id, const std::string& title);
};

#endif

