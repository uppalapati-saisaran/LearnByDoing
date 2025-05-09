//ITaskFactory.h  - Factory Pattern Interface
#pragma once

#include "ITask.h"
#include <memory>
#include <string>

class ITaskFactory {
public:
	virtual std::unique_ptr<ITask> createTask(const std::string& taskType) = 0;
	virtual ~ITaskFactory() = default;
};

