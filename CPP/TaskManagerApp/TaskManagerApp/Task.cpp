#include "Task.h"
#include<iostream>

Task::Task(int id, std::string title, std::string description) :
	id(id), title(title), description(description), completed(false) {
}

std::string Task::getTitle() const
{
	return title;
}

std::string Task::getDescription() const
{
	return description;
}

int Task::getId() const {
	return id;
}

bool Task::isCompleted() const {
	return completed;
}

void Task::markedCompleted() {
	completed = true;
}