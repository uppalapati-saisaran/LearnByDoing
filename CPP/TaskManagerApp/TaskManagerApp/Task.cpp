#include "Task.h"
#include<iostream>

Task::Task(int id, const std::string& title)
	  :id(id), title(title), isCompleted(false) {
}