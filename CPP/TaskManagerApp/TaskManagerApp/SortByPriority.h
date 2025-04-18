#pragma once
#include "SortStrategy.h"
#include<vector>
class SortByPriority : public SortStrategy
{
public:
	void sort(std::vector<std::shared_ptr<Task>>& tasks) override;
};

