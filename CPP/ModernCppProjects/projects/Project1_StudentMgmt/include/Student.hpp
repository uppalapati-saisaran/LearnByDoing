#ifndef STUDENT_HPP
#define STUDENT_HPP 

#include<string>
#include<iostream>

class student {
private:
	std::string name;
	int age;
	int rollnumber;

public:
	//Constructor 
	Student(const std::string& name, int age, int rollNumber);

	//Getter amd Setter functions (Encapsulation)
	std::string getName() const;
	void setName(const std::string& name);

	int getAge() const;
	void setAge(int age);

	int getRollNumber() const;
	void setRollNumber(int rollNumber);

	//Behaviour (Abstraction)
	void displayInfo() const; 
};

#endif 