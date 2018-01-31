#pragma once
#include "Student.h"
class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1,
		std::string daysInCourse2, std::string daysInCourse3); 

	/// <summary>
	/// Gets the degree program of the student. Must be implemented by subclass.
	/// </summary>
	/// <returns></returns>
	degree get_DegreeProgram() override;

	/// <summary>
	/// Prints the student properties.
	/// </summary>
	void print() override;
};

