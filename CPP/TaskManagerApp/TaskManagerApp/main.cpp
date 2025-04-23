#include "TaskManager.h"
#include "TaskFilterStrategy.h"
#include "Task.h"

int main()
{
	TaskManager manager;

	Task task1(1, "Write C++ code");
	Task task2(2, "Refactor code using SOILD");
	Task task3(3, "Test TestManager App");

	task2.isCompleted = true;

	manager.addTask(task1);
	manager.addTask(task2);
	manager.addTask(task3); 

	std::cout << "\n All Task:\n";
	AllTasks all;
	manager.listTask(all);

	std::cout << "\n Completed Tasks:\n";
	CompletedTasks completed;
	manager.listTask(completed); 

	return 0;

}