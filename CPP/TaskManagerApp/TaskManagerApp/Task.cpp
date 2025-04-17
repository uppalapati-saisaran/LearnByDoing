#include "Task.h"
#include<iostream>

Task::Task(int id, std::string title, std::string description) :
	id(id), title(title), description(description), completed(false) {
}

void Task::markedCompleted() {
	completed = true;
}

void Task::display() const {
	std::cout << "ID :" << id << "\nTitle: " << title
		<< "\nDescription: " << description
		<< "\nCompleted:" << (completed ? "Yes" : "No") << "\n";
}

int Task::getId() const {
	return id;
}

bool Task::isCompleted() const {
	return completed;
}