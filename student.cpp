#include "student.h"
#include <iostream>

//Constructor
Student::Student(std::string_view studentID, std::string_view fName, std::string_view lName, std::string_view email, int age, std::vector<int> numDaysToComplete, DegreeProgram program)
	: m_studentID{ studentID }
	, m_fName{ fName }
	, m_lName{ lName }
	, m_email{ email }
	, m_age{ age }
	, m_numDaysToComplete{ numDaysToComplete }
	, m_program{ program }
{
}

//Accessors
std::string Student::getStudentID() { return m_studentID; }
std::string Student::getFName() { return m_fName; }
std::string Student::getLName() { return m_lName; }
std::string Student::getEmail() { return m_email; }
int Student::getAge() { return m_age; }
std::vector<int> Student::getNumDaysToComplete() { return m_numDaysToComplete; }
DegreeProgram Student::getProgram() { return m_program; }

//Mutators
void Student::setStudentID(std::string_view studentID) { m_studentID = studentID; }
void Student::setFName(std::string_view fName) { m_fName = fName; }
void Student::setLName(std::string_view lName) { m_lName = lName; }
void Student::setEmail(std::string_view email) { m_email = email; }
void Student::setAge(int age) { m_age = age; }
void Student::setNumDaysToComplete(const std::vector<int>& numDaysToComplete) { m_numDaysToComplete = numDaysToComplete; }
void Student::setProgram(DegreeProgram program) { m_program = program; }

//Printer
void Student::print() {
	std::cout << m_studentID << '\t' << m_fName << '\t' << m_lName << '\t' << m_email << '\t' << m_age << "\t{";
	for (const auto& days : m_numDaysToComplete) {
		std::cout << days;
		if (&days != &m_numDaysToComplete.back()) {
			std::cout << ',';
		}
	}
	std::cout << "}\t";
	switch (m_program) {
	case SECURITY: std::cout << "SECURITY\n";
		break;
	case NETWORK: std::cout << "NETWORK\n";
		break;
	case SOFTWARE: std::cout << "SOFTWARE\n";
		break;
	}
}