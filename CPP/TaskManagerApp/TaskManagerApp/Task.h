//Task.h 
#ifndef TASK_H
#define TASH_H 

#include <iostream>
#include <string>

class Task {
private:
	int id;
	std::string title;
	std::string description;
	bool completed;
public:
	Task(int id, std::string title, std::string description);
	void markedCompleted(); 
	void display() const; 
	int getId() const; 
	bool isCompleted() const;
};

#endif

