#include "TaskManager.h"
#include <iostream>

int main() {
	TaskManager manager;
	std::string command;

	std::cout << "Welcome to C++ Task Manager!" << std::endl;
	std::cout << "Commands: create, run, pause, resume, stop, status, exit" << std::endl;

	while (true) {
		std::cout << "\n>";
		std::cin >> command;

		if (command == "create") {
			std::string type, name;
			std::cout << "Enter task type (PrimeNumber): ";
			std::cin >> type;
			std::cout << "Enter task name :";
			std::cin >> name;
			manager.createAndScheduleTask(type, name);
		}
		else if (command == "run")
		{
			manager.runNext();
		}
		else if (command == "stop")
		{
			std::string name;
			std::cout << "Enter task name to get status: ";
			std::cin >> name;
			manager.stopTask(name); 
		}
		else if (command == "status")
		{
			std::string name;
			std::cout << "Enter task name to get status: ";
			std::cin >> name;
			manager.printTaskStatus(name);
		}
		else if (command == "exit")
		{
			std::cout << "Existing Task Manager. " << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}
}