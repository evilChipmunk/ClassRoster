#include "stdafx.h"
#include "Student.h"


void Student::set_StudentId(std::string id)
{
	if (id.empty())
	{
		 throw std::invalid_argument("student id is required");
	}
	this->studentId = id;
}

void Student::set_FirstName(std::string firstName)
{
	if (firstName.empty())
	{
		throw std::invalid_argument("first Name is required");
	}
	this->firstName = firstName;
}

void Student::set_LastName(std::string lastName)
{
	if (lastName.empty())
	{
		throw std::invalid_argument("last Name is required");
	}
	this->lastName = lastName;
}

void Student::set_EmailAddress(std::string emailAddress)
{
	if (emailAddress.empty())
	{
		throw std::invalid_argument("email Address is required");
	}
	this->emailAddress = emailAddress;
}

void Student::set_Age(std::string age)
{
	if (age.empty())
	{
		throw std::invalid_argument("age is required");
	} 
	set_Age(std::stoi(age));
}
 
void Student::set_Age(int age)
{
	if (age <= 0)
	{
		throw std::invalid_argument("given age must be greater than 0");
	}
	this->age = age;
}
 
void Student::set_DaysInCourse(std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3)
{
	if (daysInCourse1.empty() || daysInCourse2.empty() || daysInCourse3.empty())
	{
		throw std::invalid_argument("all days in course are required");
	}
	int day1 = std::stoi(daysInCourse1);
	int day2 = std::stoi(daysInCourse2);
	int day3 = std::stoi(daysInCourse3);

	if (day1 <= 0 || day2 <= 0 || day3 <= 0)
	{
		throw std::invalid_argument("all days in course must be greater than 0");
	}
	this->daysInCourse.push_back(day1);
	this->daysInCourse.push_back(day2);
	this->daysInCourse.push_back(day3);
}
 
Student::Student(std::string studentId, std::string firstName, std::string lastName,
	std::string emailAddress, std::string age, std::string daysInCourse1,
	std::string daysInCourse2, std::string daysInCourse3)
{
	//student is set up to follow the immutable class pattern
	set_StudentId(studentId);
	set_FirstName(firstName);
	set_LastName(lastName);
	set_EmailAddress(emailAddress);
	set_Age(age);
	set_DaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
}


Student::~Student()
{
 
}

std::string Student::get_StudentId()
{
	return studentId;
}

std::string Student::get_FirstName()
{
	return firstName;
}

std::string Student::get_LastName()
{
	return lastName;
}

std::string Student::get_EmailAddress()
{
	return emailAddress;
}

int Student::get_Age()
{
	return age;
}

std::vector<int> Student::get_DaysInCourse()
{
	return daysInCourse;
}


double Student::get_AverageDaysInCourse()
{
	std::vector<int>  daysInCourse = get_DaysInCourse();
	int sum = 0;
	for (int days : daysInCourse)
	{
		sum += days;
	}

	return sum / daysInCourse.size();
}

void Student::printBaseData()
{
	std::cout << "First Name : " << firstName << "\t";
	std::cout << "Last Name : " << lastName << "\t";
	std::cout << "Age : " << age << "\t";
	std::cout << "daysInCourse : {";
	std::cout << daysInCourse[0] << ", ";
	std::cout << daysInCourse[1] << ", ";
	std::cout << daysInCourse[2] << "} " << "\t";
	std::cout << "Degree Program : " << get_DegreeProgramDescription(get_DegreeProgram()); 
	std::cout << "\r\n";
}

std::string Student::get_DegreeProgramDescription(degree degreeType)
{
	switch (degreeType)
	{
	case NETWORKING:
		return "Network";
	case SECURITY:
		return "Security";
	case SOFTWARE:
		return "Software";
	default:
		return "New Degee not categorized";
	}
}



