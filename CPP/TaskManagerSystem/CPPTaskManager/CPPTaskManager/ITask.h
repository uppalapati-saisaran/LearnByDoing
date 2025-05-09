// ITask.h - Base Interface for All Tasks
#pragma once
#include <string>

class ITask {
public:
	virtual void execute() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
	virtual void stop() = 0;
	virtual std::string getStatus() const = 0;
	virtual ~ITask() = default;

};
