#pragma once
#include "degree.h"
#include <string>
#include <vector>

class Student {
public:
	Student(std::string_view studentID, std::string_view fName, std::string_view lName, std::string_view email, int age, std::vector<int> numDaysToComplete, DegreeProgram program);

	std::string getStudentID();
	std::string getFName();
	std::string getLName();
	std::string getEmail();
	int getAge();
	std::vector<int> getNumDaysToComplete();
	DegreeProgram getProgram();

	void setStudentID(std::string_view studentID);
	void setFName(std::string_view fName);
	void setLName(std::string_view lName);
	void setEmail(std::string_view email);
	void setAge(int age);
	void setNumDaysToComplete(const std::vector<int>& numDaysToComplete);
	void setProgram(DegreeProgram program);

	void print();

private:
	std::string m_studentID;
	std::string m_fName;
	std::string m_lName;
	std::string m_email;
	int m_age;
	std::vector<int> m_numDaysToComplete;
	DegreeProgram m_program;

};