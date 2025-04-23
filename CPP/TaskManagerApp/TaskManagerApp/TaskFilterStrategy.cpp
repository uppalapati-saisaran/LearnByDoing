#include "TaskFilterStrategy.h"

bool AllTasks::filter(const Task& task) const
{
	return true;
}

bool CompletedTasks::filter(const Task& task) const 
{
	return task.isCompleted; 
}
