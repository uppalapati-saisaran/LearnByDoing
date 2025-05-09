#pragma once
#include "TaskFactory.h"
#include "SimpleSchedular.h"
#include <map>
#include <string>
#include <memory>
#include <iostream>

class TaskManager {
private:
	TaskFactory factory;
	SimpleSchedular schedular;
	std::map<std::string, std::unique_ptr<ITask>> runningTasks;
public:
	void createAndScheduleTask(const std::string& taskType,
		std::string& taskName) {
		auto task = factory.createTask(taskType);
		if (task) {
			runningTasks[taskName] = std::move(task);
			schedular.scheduleTask(std::make_unique<PrimeNumberTask>());
			// clone for schedular 
		}
	}

	void runNext() {
		schedular.runNextTask();
	}

	void pauseTask(const std::string& taskName)
	{
		if (runningTasks.count(taskName))
		{
			runningTasks[taskName]->pause();
		}
	}

	void resumeTask(const std::string& taskName)
	{
		if (runningTasks.count(taskName))
		{
			runningTasks[taskName]->resume();
		}
	}

	void stopTask(const std::string& taskName)
	{
		if (runningTasks.count(taskName))
		{
			runningTasks[taskName]->stop();
		}
	}

	void printTaskStatus(const std::string& taskName)
	{
		if (runningTasks.count(taskName)) {
			std::cout << "Status of " << taskName << " : " <<
				runningTasks[taskName]->getStatus() << std::endl;
		}
	}

};