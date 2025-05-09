#pragma once
#include "ITaskFactory.h"
#include "PrimeNumberTask.h"
#include <memory>
#include <unordered_map>
#include <functional>

class TaskFactory : public ITaskFactory {
public:
	using TaskCreator = std::function<std::unique_ptr<ITask>()>;

	TaskFactory() {
		// Register available task types
		registerTask("PrimeNumber", []() {
			return std::make_unique<PrimeNumberTask>();
		});
	}

	std::unique_ptr<ITask> createTask(const std::string& taskType) override
	{
		auto it = creators.find(taskType);
		if (it != creators.end()) {
			return it->second();
		}
		return nullptr;
	}

	void registerTask(const std::string& taskType, TaskCreator creator)
	{
		creators[taskType] = creator; 
	}

private:
	std::unordered_map<std::string, TaskCreator> creators;
};

