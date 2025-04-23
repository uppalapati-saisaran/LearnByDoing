#include "TaskManager.h"
#include "TaskPrinter.h"

void TaskManager::addTask(const Task& task)
{
	tasks.push_back(task); 
}

void TaskManager::listTask(const TaskFilterStrategy& strategy)
{
	for (const auto& task : tasks) {
		if (strategy.filter(task)) {
			TaskPrinter::print(task); 
		}
	}
}

