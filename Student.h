#pragma once
#include <string>
#include <iostream>
#include "stdafx.h"
#include <vector>
#include "degree.h"

/// <summary>
/// Base class representing a student. Must be inherited to use.
/// </summary>
class Student
{

#pragma region fields

	/// <summary>
	/// The student identifier
	/// </summary>
	std::string studentId;

	/// <summary>
	/// The first name of the student
	/// </summary>
	std::string firstName;

	/// <summary>
	/// The last name of the student
	/// </summary>
	std::string lastName;

	/// <summary>
	/// The email address of the student
	/// </summary>
	std::string emailAddress;

	/// <summary>
	/// The age of the student
	/// </summary>
	int age;

	/// <summary>
	/// The number of days in 3 courses taken
	/// </summary>
	std::vector<int> daysInCourse;

	/// <summary>
	/// The degree types available
	/// </summary>
	std::vector<degree> degreeTypes;
#pragma endregion fields

#pragma region mutators

	/// <summary>
	/// Sets the student identifier.
	/// </summary>
	/// <param name="id">The identifier of the student.</param>
	void set_StudentId(std::string id);

	/// <summary>
	/// Sets the first name of the student.
	/// </summary>
	/// <param name="firstName">The first name of the student.</param>
	void set_FirstName(std::string firstName);

	/// <summary>
	/// Sets the last name of the student.
	/// </summary>
	/// <param name="lastName">The last name of the student.</param>
	void set_LastName(std::string lastName);

	/// <summary>
	/// Sets the email address of the student.
	/// </summary>
	/// <param name="emailAddress">The email address of the student.</param>
	void set_EmailAddress(std::string emailAddress);

	/// <summary>
	/// Sets the age of the student.
	/// </summary>
	/// <param name="age">The age of the student.</param>
	void set_Age(int age);

	/// <summary>
	/// Sets the age from a string value.
	/// </summary>
	/// <param name="age">The age of the student.</param>
	void set_Age(std::string age);

	/// <summary>
	/// Sets the number of days in course.
	/// </summary>
	/// <param name="daysInCourse1">The days in course1.</param>
	/// <param name="daysInCourse2">The days in course2.</param>
	/// <param name="daysInCourse3">The days in course3.</param>
	void set_DaysInCourse(std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3);
#pragma endregion mutators

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Student"/> class.
	/// </summary>
	/// <param name="studentId">The student identifier.</param>
	/// <param name="firstName">The first name.</param>
	/// <param name="lastName">The last name.</param>
	/// <param name="emailAddress">The email address.</param>
	/// <param name="age">The age.</param>
	/// <param name="daysInCourse1">The days in course1.</param>
	/// <param name="daysInCourse2">The days in course2.</param>
	/// <param name="daysInCourse3">The days in course3.</param>
	Student(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1,
		std::string daysInCourse2, std::string daysInCourse3);

	/// <summary>
	/// Finalizes an instance of the <see cref="Student"/> class.
	/// </summary>
	virtual ~Student();

#pragma region accessors

	/// <summary>
	/// Gets the student identifier.
	/// </summary>
	/// <returns></returns>
	std::string get_StudentId();

	/// <summary>
	/// Gets the first name of the student.
	/// </summary>
	/// <returns></returns>
	std::string get_FirstName();

	/// <summary>
	/// Gets the last name of the student.
	/// </summary>
	/// <returns></returns>
	std::string get_LastName();

	/// <summary>
	/// Gets the email address of the student.
	/// </summary>
	/// <returns></returns>
	std::string get_EmailAddress();

	/// <summary>
	/// Gets the age of the student.
	/// </summary>
	/// <returns></returns>
	int get_Age();
	  
	/// <summary>
	/// Gets the days in course.
	/// </summary>
	/// <returns></returns>
	std::vector<int> get_DaysInCourse();
	 
	/// <summary>
	/// Gets the average days in the 3 courses.
	/// </summary>
	/// <returns></returns>
	double get_AverageDaysInCourse();
	
	/// <summary>
	/// Gets the degree program description.
	/// </summary>
	/// <param name="degreeType">Type of the degree.</param>
	/// <returns></returns>
	std::string get_DegreeProgramDescription(degree degreeType);

#pragma endregion accessors

	/// <summary>
	/// Prints the student properties. Is called by the virtual method "print", and relies
	/// on the virtual method get_DegreeProgram. This allows for the print action to 
	/// use the Template pattern and code to follow the DRY principle
	/// </summary>
	void printBaseData();

	/// <summary>
	/// Gets the degree program of the student. Must be implemented by subclass.
	/// </summary>
	/// <returns></returns>
	virtual degree get_DegreeProgram() { throw std::exception("not implemented"); }

	/// <summary>
	/// Prints the student properties. Virtual method that has to be implemented in subclass.
	/// This is kept as a virtual method to honor the specification, but printBaseData
	/// does the actual print work. Implementations of the print method call printBaseData.
	/// </summary>
	virtual void print() { std::cerr << "error, base type unable to print" << std::endl; }
};

