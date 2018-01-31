#pragma once
#include "Student.h"
class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1,
		std::string daysInCourse2, std::string daysInCourse3); 
	degree get_DegreeProgram();
	void print();
};

