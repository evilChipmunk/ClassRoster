#include "stdafx.h"
#include "Roster.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include <sstream>
#include <algorithm>

int main()
{
	try
	{
		Roster classRoster = Roster();
		classRoster.printAll();
		classRoster.printInvalidEmails();

		for (Student* student : classRoster.getStudents())
		{
			std::string studentId = student->get_StudentId();

			classRoster.printDaysInCourse(studentId); 
		}
		std::cout << "\r\n";
	    classRoster.printByDegreeProgram(degree::SOFTWARE);
		std::cout << "\r\n";
		classRoster.remove("A3");
		classRoster.remove("A3");

		classRoster.~Roster();

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << "\r\n";
	}
	std::cout << "\r\n";
	std::cout << "enter any key to exit program";
	std::string ending;
	std::cin >> ending;
	return 0;
}

const std::string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,James,West,jwes140@wgu.edu,43,1,1,1,SOFTWARE" };

Roster::Roster()
{
	students = std::vector<Student*>();
	create_RosterData();
}
 
Roster::~Roster() = default;


void Roster::create_RosterData()
{  
	for (std::string dataLine : studentData)
	{
		std::vector<std::string> dataArray;
		std::istringstream splitDataStream(dataLine);
		std::string token;

		while (std::getline(splitDataStream, token, ','))
		{
			dataArray.push_back(token);  
		}

		if (!validateData(dataArray))
		{
			throw std::invalid_argument("intial class roster data is invalid");
		}
		add(dataArray[0], dataArray[1], dataArray[2], dataArray[3], dataArray[4], dataArray[5], dataArray[6], dataArray[7], dataArray[8]);
	} 
}

bool Roster::validateData(std::vector<std::string> data)
{
	return data.size() == 9; 
}

std::vector<Student*> Roster::getStudents()
{
	return students;
}

void Roster::add(std::string studentId, std::string firstName, std::string lastName,
	std::string emailAddress, std::string age, std::string daysInCourse1,
	std::string daysInCourse2, std::string daysInCourse3, std::string program)
{
	if (program.empty())
	{
		throw std::invalid_argument("degree program is required");
	}

	std::string degreeProgram = toUpperCase(program);
	Student* student;
	if (degreeProgram == "NETWORK")
	{ 
		student = new NetworkStudent(studentId, firstName, lastName, emailAddress, age
			, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	else if (degreeProgram == "SECURITY")
	{
		student = new SecurityStudent(studentId, firstName, lastName, emailAddress, age
			, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	else if (degreeProgram == "SOFTWARE")
	{
		student = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age
			, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	else
	{
		throw std::invalid_argument("invalid degree program");
	}
	students.push_back(student);

}

void Roster::remove(std::string studentId)
{
	Student* student = get_Student(studentId);
	if (student == nullptr)
	{
		std::cout << "Student Id : " << studentId << " not found";
	}
	else
	{
		students.erase(std::remove(students.begin(), students.end(), student), students.end()); 
		std::cout << "Removed Student ID : " << studentId;
	}
	std::cout << "\r\n";
}

void Roster::printAll()
{
	int i = 1;
	for (Student* student : getStudents())
	{
		std::cout << i << "\t";
		student->print();
		i++;
	}
	std::cout << "\r\n";
}

void Roster::printDaysInCourse(std::string studentId)
{
	std::vector<Student*> data = getStudents();
	Student* student = get_Student(studentId);
	if (student != nullptr)
	{
		double avg = student->get_AverageDaysInCourse();
		std::cout << "Student ID : " << studentId << "\t" << "Average Days in Course : " << avg;
	}
	std::cout << "\r\n";
}

Student * Roster::get_Student(std::string studentId)
{
	std::vector<Student*> data = getStudents();
	for (Student* student : data)
	{
		if (student->get_StudentId() == studentId)
		{
			return student;
		}
	}
	return nullptr;
}

bool Roster::hasInvalidEmail(std::string email)
{ 
	
	if (email.find(".") == std::string::npos)
	{
		return true;
	}

	if (email.find("@") == std::string::npos)
	{
		return true;
	}

	return email.find(" ") != std::string::npos; 
}
  
 

void Roster::printInvalidEmails()
{
	std::vector<Student*> data = getStudents();
	for (Student* student : data)
	{
		if (hasInvalidEmail(student->get_EmailAddress()))
		{
			std::cout << "Invalid email address found for Student ID : " << student->get_StudentId();
			std::cout << "\t" << "Email Address : " << student->get_EmailAddress() << "\r\n";
		}
	}
	std::cout << "\r\n";

}

void Roster::printByDegreeProgram(int degreeProgram)
{
	std::vector<Student*> data = getStudents();
	for (Student* student : data)
	{
		if (student->get_DegreeProgram() == degreeProgram)
		{
			student->print();
		}
	}
	std::cout << "\r\n";
}

std::string Roster::toUpperCase(std::string& val)
{
	for (unsigned int i = 0; i<val.length(); i++)
	{
		val[i] = toupper(val[i]);
	}
	return val;
}

 
