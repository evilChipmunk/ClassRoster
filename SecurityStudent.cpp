#include "stdafx.h"
#include "SecurityStudent.h"

 

SecurityStudent::SecurityStudent(std::string studentId, std::string firstName,
	std::string lastName, std::string emailAddress, std::string age,
	std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3)
	: Student(studentId, firstName, lastName, emailAddress, age,
		daysInCourse1, daysInCourse2, daysInCourse3)
{
}
degree SecurityStudent::get_DegreeProgram()
{
	return SECURITY;
}
void SecurityStudent::print()
{
	printBaseData();
}
// 
//void Student::print()
//{
//	printBaseData();
//}
//
//degree Student::get_DegreeProgram()
//{
//	return SECURITY;
//}