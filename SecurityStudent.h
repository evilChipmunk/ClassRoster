#pragma once
#include "Student.h"
class SecurityStudent :
	public Student
{
public:
	SecurityStudent(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1,
		std::string daysInCourse2, std::string daysInCourse3);
	degree get_DegreeProgram();
	void print();
 
};
 
