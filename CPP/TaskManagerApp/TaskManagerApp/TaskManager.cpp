#include "TaskManager.h"
#include<iostream>
#include<algorithm>

TaskManager::TaskManager() : nextId(1) {

}

void TaskManager::addTask(const std::string& title, const std::string& description) {
	Task newTask(nextId, title, description);
	tasks.push_back(newTask);
	std::cout << "Task added with ID:" << nextId << "\n";
	nextId++; 
}

void TaskManager::displayAllTasks() const {
	if (tasks.empty()) {
		std::cout << "No tasks available \n";
		return;
	}

	for (const Task& task : tasks) {
		task.display();
		std::cout << "-----------------------------\n"; 
	}
}

void TaskManager::markTaskComplete(int id) {
	for (Task& task : tasks) {
		if (task.getId() == id)
		{
			task.markedCompleted();
			std::cout << "Task " << id << " marked as completed. \n";
			return;
		}
	}
	std::cout << "Task with ID " << id << "not found.\n"; 
}

void TaskManager::deleteTask(int id) {
	auto it = std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
		return task.getId() == id;
		});

	if (it != tasks.end()) {
		tasks.erase(it, tasks.end());
		std::cout << "Task " << id << " deleted.\n";
	}
	else {
		std::cout << "Task with ID " << id << " not found.\n"; 
	}
}

