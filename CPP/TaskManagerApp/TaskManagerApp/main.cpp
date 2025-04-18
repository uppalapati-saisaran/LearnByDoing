#include<iostream>
#include "TaskManager.h" 

int main() {
	std::cout << "\n After completing task 1:\n";
    int choice;
    std::string title, description;
    int id;

    while (true) {
        std::cout << "\n--- Task Manager Menu ---\n";
        std::cout << "1.Add Task \n2. Show tasks \n3. Complete Task \n4. Delete Task \n5. Exit \nChooser";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            manager.addTask(title, description);
            break;
        case 2:
            manager.displayTasks();
            break;
        case 3:
            std::cout << "Enter Task ID to complete:";
            std::cin >> id;
            manager.markTaskComplete(id);
            break;
        case 4:
            std::cin >> id;
            manager.deleteTask(id);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid option.\n";
        }
    }

}