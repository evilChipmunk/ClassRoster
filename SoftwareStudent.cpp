#include "stdafx.h"
#include "SoftwareStudent.h"


SoftwareStudent::SoftwareStudent(std::string studentId, std::string firstName,
	std::string lastName, std::string emailAddress, std::string age,
	std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3)
	: Student(studentId, firstName, lastName, emailAddress, age,
		daysInCourse1, daysInCourse2, daysInCourse3)
{
}

degree SoftwareStudent::get_DegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	printBaseData();
}

//void Student::print()
//{
//	printBaseData();
//}
//
//degree Student::get_DegreeProgram()
//{
//	return SOFTWARE;
//}