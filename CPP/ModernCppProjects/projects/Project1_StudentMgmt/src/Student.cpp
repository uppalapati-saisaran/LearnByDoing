#include "Student.hpp"

//constructor 
student::student(const std::string& name, int age, int rollNumber)
	: name(name), age(age), rollnumber(rollNumber) 
{
}

//Getters and setters 
std::string student::getName() const { return name; }
void student::setName(const std::string& name) { this->name = name;  }

int student::getAge() const { return age;  }
void student::setAge(int age) { this->age = age;  }

int student::getRollNumber() const { return rollnumber;  }
void student::setRollNumber(int rollNumber) { this->rollnumber = rollNumber;  }

//Display behaviour 
void student::displayInfo() const {
	std::cout << "Name :" << name
		<< ",Age :" << age
		<< ",Roll No: " << rollnumber << std::endl;

}
