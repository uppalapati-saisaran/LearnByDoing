#include "TaskPrinter.h"
#include<iostream>

void TaskPrinter::print(const Task& task)
{
	std::cout << task.id << ": " << task.title
		<< (task.isCompleted ? "[Done]" : "[Pending]") << std::endl;
}
