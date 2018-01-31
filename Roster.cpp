#include "stdafx.h"
#include "Roster.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include <sstream>
#include <algorithm>



/// <summary>
/// Entry point for the applicaton
/// </summary>
/// <returns></returns>
int main()
{
	//run the application, catch any errors that occur and print them to the screen
	try
	{
		//create a roster object, and then call aggregated print methods
		Roster classRoster = Roster();

		classRoster.printAll();
		classRoster.printInvalidEmails();

		//loop through the students and print the average days they've taken 3 courses
		for (Student* student : classRoster.getStudents())
		{
			const std::string studentId = student->get_StudentId();

			classRoster.printDaysInCourse(studentId); 
		}
		std::cout << "\r\n"; //added to make output easier to read

		//print out all of the students in the software degree program
	    classRoster.printByDegreeProgram(degree::SOFTWARE);
		std::cout << "\r\n";

		//remove the student with id A3
		classRoster.remove("A3");
		//try again, this will print an error to the screen
		classRoster.remove("A3");

		//explicitly call to destroy the roster
		classRoster.~Roster();

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << "\r\n";
	}

	//allow for user to view data before exiting the program
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

	//create the roster data
	create_RosterData();
}
 
/// <summary>
/// Finalizes an instance of the <see cref="Roster"/> class.
/// </summary>
Roster::~Roster() = default;


void Roster::create_RosterData()
{  
	//loop through each line of data 
	for (std::string dataLine : studentData)
	{
		//split the line of data on the comma delimiter
		std::istringstream splitDataStream(dataLine);
		std::string token;

		//create a vector of strings, for each string value
		//given by the split function add it to the vector
		std::vector<std::string> dataArray;
		while (std::getline(splitDataStream, token, ','))
		{
			dataArray.push_back(token);  
		}

		//make sure that that the values were split correctly so that the student object
		//can be created
		if (!validateData(dataArray))
		{
			throw std::invalid_argument("intial class roster data is invalid");
		}

		//call the add method, each index will point to the appropriate value for the given method
		add(dataArray[0], dataArray[1], dataArray[2], dataArray[3], dataArray[4], dataArray[5], dataArray[6], dataArray[7], dataArray[8]);
	} 
}

bool Roster::validateData(std::vector<std::string> data)
{
	//this is currently set to the data element count needed to validate
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
	//make sure a degree program has been supplied or the application won't work properly
	if (program.empty())
	{
		throw std::invalid_argument("degree program is required");
	}

	//convert the string to upper case before checking if it matches,
	//this is in case the data supplied has been typed in with lower or mixed case
	std::string degreeProgram = toUpperCase(program);

	//create the appropriate type of student based on degree
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

	//add student to list
	students.push_back(student);

}

void Roster::remove(std::string studentId)
{
	//try to get the student, if the student wasn't found the result will
	//be null, in that case report that the student wasn't found.
	//if the student was found, remove from the roster
	Student* student = get_Student(studentId);
	if (student == nullptr)
	{
		std::cout << "Student Id : " << studentId << " not found";
	}
	else
	{
		//delete the student from memory
		students.erase(std::remove(students.begin(), students.end(), student), students.end()); 
		std::cout << "Removed Student ID : " << studentId;
	}
	std::cout << "\r\n";
}

void Roster::printAll()
{
	//get all of the students and print them. variable i is added as a row number
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
	//try to get the student, if found, get the average of course days and print
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
	//loop through all of the students, if the student id matches
	//the supplied studenId parameter then return the student.
	//if not return null
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
	//check to see if email has a ".", if not it is invalid
	if (email.find(".") == std::string::npos)
	{
		return true;
	}

	//check to see if email has "@", if not it is invalid
	if (email.find("@") == std::string::npos)
	{
		return true;
	}

	//make sure that email doesn't have a space, if it does it is invalid
	return email.find(" ") != std::string::npos; 
}
  
 

void Roster::printInvalidEmails()
{
	//loop through all of the students,  check to see if an invalid email exists for the student
	//if so then print info to the screen
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
	//loop through all of the students, if the degree program matches then print the student info
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
	//convert the string to upper case
	for (unsigned int i = 0; i<val.length(); i++)
	{
		val[i] = toupper(val[i]);
	}
	return val;
}

 
