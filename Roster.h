#pragma once
#include "Student.h"

class Roster
{
	/// <summary>
	/// The list of students
	/// </summary>
	std::vector<Student*> students;

	/// <summary>
	/// converts a string value to all upper case
	/// </summary>
	/// <param name="val">The string value.</param>
	/// <returns></returns>
	std::string toUpperCase(std::string& val);

	/// <summary>
	/// Creates the roster data -- the list of students for the program.
	/// </summary>
	void create_RosterData();

	/// <summary>
	/// Validates the data to make sure that all values supplied can be 
	/// converted into a student object.
	/// </summary>
	/// <param name="data">A line of data converted into a vector.</param>
	/// <returns></returns>
	bool validateData(std::vector<std::string> data);

	/// <summary>
	/// Gets a student from the roster list by the student id. Returns null if not found
	/// </summary>
	/// <param name="studentId">The student identifier.</param>
	/// <returns></returns>
	Student* get_Student(std::string studentId);

	/// <summary>
	/// Determines whether [has invalid email] [the specified email].
	/// </summary>
	/// <param name="email">The email.</param>
	/// <returns>
	///   <c>true</c> if [has invalid email] [the specified email]; otherwise, <c>false</c>.
	/// </returns>
	bool hasInvalidEmail(std::string email);

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Roster"/> class.
	/// </summary>
	Roster();

	/// <summary>
	/// Finalizes an instance of the <see cref="Roster"/> class.
	/// </summary>
	~Roster();

	/// <summary>
	/// Gets the available roster students.
	/// </summary>
	/// <returns></returns>
	std::vector<Student*> getStudents();

	/// <summary>
	/// Adds a student to the roster
	/// </summary>
	/// <param name="studentId">The student identifier.</param>
	/// <param name="firstName">The first name.</param>
	/// <param name="lastName">The last name.</param>
	/// <param name="emailAddress">The email address.</param>
	/// <param name="age">The age.</param>
	/// <param name="daysInCourse1">The days in course1.</param>
	/// <param name="daysInCourse2">The days in course2.</param>
	/// <param name="daysInCourse3">The days in course3.</param>
	/// <param name="program">The program.</param>
	void add(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1, std::string daysInCourse2,
		std::string daysInCourse3, std::string program);

	/// <summary>
	/// Removes the specified student from the roster
	/// </summary>
	/// <param name="studentId">The student identifier.</param>
	void remove(std::string studentId);

	/// <summary>
	/// Prints all of the student information in the roster.
	/// </summary>
	void printAll();

	/// <summary>
	/// Prints the average course days for a student
	/// </summary>
	/// <param name="studentId">The student identifier.</param>
	void printDaysInCourse(std::string studentId);
	
	/// <summary>
	/// Prints student information for any student that has an invalid email address
	/// </summary>
	void printInvalidEmails();

	/// <summary>
	/// Prints all student information that are in the supplied degree 
	/// </summary>
	/// <param name="degreeProgram">The degree program.</param>
	void printByDegreeProgram(int degreeProgram);

};

