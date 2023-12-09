#pragma once
#include "student.h"
#include <vector>

class Roster {
public:
	~Roster();

	void parse(std::string_view row);
	void add(std::string_view studentID, std::string_view fName, std::string_view lName, std::string_view email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);
	void remove(std::string_view studentID);
	void printAll();
	void printAverageDaysInCourse(std::string_view studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram program);

	std::vector<Student> classRosterArray;

};