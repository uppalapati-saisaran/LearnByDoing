#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include "TaskFilterStrategy.h"
#include <vector>

class TaskManager {
	std::vector<Task> tasks;

public:
	TaskManager() = default;
	void addTask(const Task& task);
	void listTask(const TaskFilterStrategy& strategy);
};

#endif 
