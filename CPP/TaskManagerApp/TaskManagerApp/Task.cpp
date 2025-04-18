#include "Task.h"
#include<iostream>

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

