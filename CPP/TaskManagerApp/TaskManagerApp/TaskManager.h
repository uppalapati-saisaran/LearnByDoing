#ifndef TASKMANAGER_H
#define TASKMANAGER_H

//#include "Task.h"
#include "SortStrategy.h"
#include <vector>

class TaskManager {
	std::vector<std::shared_ptr<Task>> tasks;
	SortStrategy* strategy = nullptr;
	int nextId;

public:
	TaskManager();
	void addTask(const std::string& title, const std::string& description,const std::string& dueDate,const int& priority);
	void displayTasks() const;
	void markTaskComplete(int id);
	void deleteTask(int id);

	void setSortStrategy(SortStrategy* s);
	void sortTask(); 

};

#endif 
