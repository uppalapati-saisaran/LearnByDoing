#include "TaskManager.h"
#include<iostream>
#include<algorithm>

TaskManager::TaskManager() : nextId(1) {

}

void TaskManager::addTask(const std::string& title, const std::string& description) {
	tasks.push_back(std::make_shared<Task>(nextId++, title, description));
	std::cout << "Task added successfully.\n";
}

void TaskManager::displayTasks() const {
	if (tasks.empty()) {
		std::cout << "No tasks available \n";
		return;
	}

	for (const auto& task : tasks) {
		std::cout << "ID: " << task->getId()
			<< "| Title: " << task->getTitle()
			<< "| Description: " << task->getDescription()
			<< "| Status: " << (task->isCompleted() ? "Completed" : "Pending") << "\n";
	}
}

void TaskManager::markTaskComplete(int id) {
	for (auto& task : tasks) {
		if (task->getId() == id)
		{
			task->markedCompleted();
			std::cout << "Task " << id << " marked as completed. \n";
			return;
		}
	}
	std::cout << "Task with ID " << id << "not found.\n"; 
}

void TaskManager::deleteTask(int id) {
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		if ((*it)->getId() == id) {
			tasks.erase(it);
			std::cout << "Task removed.\n";
			return;
		}
	 }
	std::cout << "Task not found.\n";
}

