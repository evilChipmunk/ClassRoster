#pragma once
#include <string>
#include <iostream>
#include "stdafx.h"
#include <vector>
#include "degree.h"

class Student
{
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	std::vector<int> daysInCourse;
	std::vector<degree> degreeTypes;

	void set_StudentId(std::string id);
	void set_FirstName(std::string firstName);
	void set_LastName(std::string lastName);
	void set_EmailAddress(std::string emailAddress);
	void set_Age(int age);
	void set_Age(std::string age);
	void set_DaysInCourse(std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3);
  

public:
	Student(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1,
		std::string daysInCourse2, std::string daysInCourse3);
	virtual ~Student();

	std::string get_StudentId();

	std::string get_FirstName();

	std::string get_LastName();

	std::string get_EmailAddress();

	int get_Age();
	 

	std::vector<int> get_DaysInCourse();


	double get_AverageDaysInCourse();
	void printBaseData();
	std::string get_DegreeProgramDescription(degree degreeType);

	virtual degree get_DegreeProgram() { return NETWORKING; }
	virtual void print() { std::cerr << "error, base type unable to print" << std::endl; }
};

