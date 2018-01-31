#include "stdafx.h"
#include "Student.h"

#pragma region setters

void Student::set_StudentId(std::string id)
{
	//value must be supplied to be a valid object, throws 
	//if not given, else it sets the value
	if (id.empty())
	{
		 throw std::invalid_argument("student id is required");
	}
	this->studentId = id;
}
 
void Student::set_FirstName(std::string firstName)
{
	//a student must have a first name
	if (firstName.empty())
	{
		throw std::invalid_argument("first Name is required");
	}
	this->firstName = firstName;
}

void Student::set_LastName(std::string lastName)
{
	//a student must have a last name
	if (lastName.empty())
	{
		throw std::invalid_argument("last Name is required");
	}
	this->lastName = lastName;
}

void Student::set_EmailAddress(std::string emailAddress)
{
	//a student must have an email address
	if (emailAddress.empty())
	{
		throw std::invalid_argument("email Address is required");
	}
	this->emailAddress = emailAddress;
}

void Student::set_Age(std::string age)
{
	//a value must be supplied for the age of the student.
	if (age.empty())
	{
		throw std::invalid_argument("age is required");
	} 

	//try to convert the value to an integer and pass it to the 
	//overloaded set_Age method to actually set the age
	set_Age(std::stoi(age));
}
 
void Student::set_Age(int age)
{
	//to be a student, you have to at least be one year old
	if (age <= 0)
	{
		throw std::invalid_argument("given age must be greater than 0");
	}
	this->age = age;
}
 
void Student::set_DaysInCourse(std::string daysInCourse1, std::string daysInCourse2, std::string daysInCourse3)
{
	//check to make sure all days were supplied
	if (daysInCourse1.empty() || daysInCourse2.empty() || daysInCourse3.empty())
	{
		throw std::invalid_argument("all days in course are required");
	}

	//convert all of the string values to integers
	int day1 = std::stoi(daysInCourse1);
	int day2 = std::stoi(daysInCourse2);
	int day3 = std::stoi(daysInCourse3);

	//ensure that all values supplied are non-negative
	if (day1 < 0 || day2 < 0 || day3 < 0)
	{
		throw std::invalid_argument("all days in course must be greater or equal to 0");
	}

	//add the days to the array
	this->daysInCourse.push_back(day1);
	this->daysInCourse.push_back(day2);
	this->daysInCourse.push_back(day3);
}
 
#pragma endregion setters

Student::Student(std::string studentId, std::string firstName, std::string lastName,
	std::string emailAddress, std::string age, std::string daysInCourse1,
	std::string daysInCourse2, std::string daysInCourse3)
{
	//student is set up to follow the immutable class pattern with validation
	//called upon construction, this ensures that there is never an object in 
	//the system with an invalid state. 
	//Calling the setters so that constructor is kept clean and setter logic is reused.
	set_StudentId(studentId);
	set_FirstName(firstName);
	set_LastName(lastName);
	set_EmailAddress(emailAddress);
	set_Age(age);
	set_DaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
}


Student::~Student() = default;

#pragma region accessors

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

std::string Student::get_DegreeProgramDescription(degree degreeType)
{
	//convert the degree data type to a usable string description
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
 
double Student::get_AverageDaysInCourse()
{
	//get the days, use the get method so if any future logic
	//is implemented in the get_DaysInCourse method that it is 
	//applied here too
	std::vector<int>  daysInCourse = get_DaysInCourse();

	//add up all of the days
	int sum = 0;
	for (int days : daysInCourse)
	{
		sum += days;
	}

	//convert sum and size variables to double so that precision is not lost in division
	return double(sum) / double(daysInCourse.size());
}

#pragma endregion accesors

void Student::printBaseData()
{
	//print student data to the output stream
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


