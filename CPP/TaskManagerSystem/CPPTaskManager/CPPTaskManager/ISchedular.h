//ISchedular.h - Interface for Scheduleing Algorithms
#pragma once
#include "ITask.h"
#include <memory>

class IScheduler {
public:
	virtual void scheduleTask(std::unique_ptr<ITask> task) = 0;
	virtual void runNextTask() = 0;
	virtual ~IScheduler() = default;
};
