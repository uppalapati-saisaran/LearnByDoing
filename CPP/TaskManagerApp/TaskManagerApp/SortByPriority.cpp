#include "SortByPriority.h"
#include <algorithm>
#include <memory>

void SortByPriority::sort(std::vector<std::shared_ptr<Task>>& tasks) {
	std::sort(tasks.begin(), tasks.end(), [](const std::shared_ptr<Task>& a, const std::shared_ptr<Task>& b) {
		return a->getPriority() < b->getPriority(); // 1 (high) comes first
		});
}
