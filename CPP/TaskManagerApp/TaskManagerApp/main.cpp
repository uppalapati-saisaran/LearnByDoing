#include<iostream>
#include "TaskManager.h" 

int main() {
	TaskManager manager;

	manager.addTask("Learn C++", "Pratice classes and vectors");
	manager.addTask("Do homework", "Finish math and science");

	std::cout << "\n All Tasks:\n";
	manager.displayAllTasks();

	manager.markTaskComplete(1);

	std::cout << "\n After completing task 1:\n";
	manager.displayAllTasks();

	manager.deleteTask(2);

	std::cout << "\nAfter deleting task 2:\n";
	manager.displayAllTasks();

	std::cout << "\n Press Enter to exit...";
	std::cin.ignore();
	std::cin.get(); 

	return 0; 

}