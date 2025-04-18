#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>

class TaskManager {
	std::vector<std::shared_ptr<Task>> tasks;
	int nextId;

public:
	TaskManager();
	void addTask(const std::string& title, const std::string& description);
	void displayTasks() const;
	void markTaskComplete(int id);
	void deleteTask(int id);
};

#endif 
