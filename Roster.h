#pragma once
#include "Student.h"

class Roster
{
	std::vector<Student*> students;
	std::string toUpperCase(std::string& val);
	void create_RosterData();
	bool validateData(std::vector<std::string> data);
	Student* get_Student(std::string studentId);
	bool hasInvalidEmail(std::string email);
public:
	Roster();
	~Roster();

	std::vector<Student*> getStudents();

	void add(std::string studentId, std::string firstName, std::string lastName,
		std::string emailAddress, std::string age, std::string daysInCourse1, std::string daysInCourse2,
		std::string daysInCourse3, std::string program);

	void remove(std::string studentId);

	void printAll();

	void printDaysInCourse(std::string studentId);
	
	void printInvalidEmails();

	void printByDegreeProgram(int degreeProgram);

};

