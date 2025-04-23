#ifndef TASKFILTERSTRATEGY_H 
#define TASKFILTERSTRATEGY_H

#include "Task.h"
class TaskFilterStrategy
{
public:
	virtual bool filter(const Task& task) const = 0;
};

class AllTasks : public TaskFilterStrategy
{
public:
	bool filter(const Task& task) const override;
};

class CompletedTasks : public TaskFilterStrategy
{
public:
	bool filter(const Task& task) const override; 
};

#endif