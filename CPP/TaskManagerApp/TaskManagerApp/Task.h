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

	std::string dueDate; // or use a custom Date class 
	int priority; // 1-High 2- Medium 3- Low
public:
	Task(int id,std::string t, std::string d, std::string date, int p)
		: id(id),title(t), description(d), dueDate(date), priority(p), completed(false) {
	}

	int getId() const;
	std::string getTitle() const;
	std::string getDescription() const;
	int getPriority() const { return priority; }
	std::string getDueDate() const { return dueDate; }

	bool isCompleted() const;
	void markedCompleted();

};

#endif

