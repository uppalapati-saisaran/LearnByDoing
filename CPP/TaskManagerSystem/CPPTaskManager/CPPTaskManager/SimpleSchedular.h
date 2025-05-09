#pragma once
#include "ISchedular.h"
#include <queue>
#include <mutex>
#include <memory>
#include <iostream>

class SimpleSchedular : public IScheduler {
private:
	std::queue < std::unique_ptr<ITask> > taskQueue;
	std::mutex mtx;

public:
	void scheduleTask(std::unique_ptr<ITask> task) override {
		std::lock_guard<std::mutex> lock(mtx);
		taskQueue.push(std::move(task));
	}

	void runNextTask() override {
		std::lock_guard<std::mutex> lock(mtx);
		if(!taskQueue.empty()) {
			std::unique_ptr<ITask> task = std::move(taskQueue.front());
			taskQueue.pop();
			try {
				task->execute();
			}
			catch (const std::exception& ex) {
				std::cerr << "Exception during task execution: " << ex.what() << std::endl;
			}
			catch (...) {
				std::cerr << "UnKnown exception during task execution. " << std::endl;
			}
		}
	}
	~SimpleSchedular() = default; 
};
