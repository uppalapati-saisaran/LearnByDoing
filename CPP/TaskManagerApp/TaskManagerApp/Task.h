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

	int getId() const;
	std::string getTitle() const;
	std::string getDescription() const;

	bool isCompleted() const;
	void markedCompleted();
};

#endif

