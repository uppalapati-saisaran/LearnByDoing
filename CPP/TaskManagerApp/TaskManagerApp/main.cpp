#include<iostream>
#include "TaskManager.h" 
#include "SortByPriority.h"

int main() {
    TaskManager manager;
    int choice;
    std::string title, description, dueDate;
        int id, priority;

    while (true) {
        std::cout << "\n--- Task Manager Menu ---\n";
        std::cout << "1.Add Task \n2. Show tasks \n3. Complete Task \n4. Delete Task \n5. Exit \n6. Sort by Priority \nChooser";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            std::cout << "Enter date (MM-DD-YYYY):";
            std::getline(std::cin, dueDate);
            std::cout << "Enter priority: ";
            std::cin >> priority;
            manager.addTask(title, description,dueDate,priority);
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
            std::cout << "Enter Task ID to delete :";
            std::cin >> id;
            manager.deleteTask(id);
            break;
        case 5:
            return 0;
        case 6:
            manager.setSortStrategy(new SortByPriority()); 
            manager.sortTask();
            std::cout << "\nSorted by Priority:\n";
            manager.displayTasks(); 

        default:
            std::cout << "Invalid option.\n";
        }
    }

}