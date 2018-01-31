#include "stdafx.h"
#include "NetworkStudent.h"


NetworkStudent::NetworkStudent(std::string studentId, std::string firstName, 
	std::string lastName, std::string emailAddress, std::string age, 	
	std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3) 
: Student(studentId, firstName, lastName, emailAddress, age, 
	daysInCourse1, daysInCourse2, daysInCourse3)
{
}

degree NetworkStudent::get_DegreeProgram()
{
	return NETWORKING; 
}

void NetworkStudent::print()
{
	printBaseData();
} 