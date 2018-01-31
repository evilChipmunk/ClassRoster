#pragma once
#include "Student.h"
class NetworkStudent :
	public Student
{
public: 
	/// <summary>
	/// Initializes a new instance of the <see cref="NetworkStudent"/> class.
	/// </summary>
	/// <param name="studentId">The student identifier.</param>
	/// <param name="firstName">The first name.</param>
	/// <param name="lastName">The last name.</param>
	/// <param name="emailAddress">The email address.</param>
	/// <param name="age">The age.</param>
	/// <param name="daysInCourse1">The days in course1.</param>
	/// <param name="daysInCourse2">The days in course2.</param>
	/// <param name="daysInCourse3">The days in course3.</param>
	NetworkStudent(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1,
		std::string daysInCourse2, std::string daysInCourse3);

	/// <summary>
	/// Gets the degree program of the student.  
	/// </summary>
	/// <returns></returns>
	degree get_DegreeProgram() override;

	/// <summary>
	/// Prints the student properties.
	/// </summary>
	void print() override;
};

