#pragma once
#include<vector>
#include "Task.h"
class SortStrategy
{
public:
	virtual void sort(std::vector<std::shared_ptr<Task>>& tasks) = 0;
	virtual ~SortStrategy() = default;
};

