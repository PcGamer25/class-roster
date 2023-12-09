#include "roster.h"
#include <iostream>
#include <sstream>

//Destructor
Roster::~Roster() {
	classRosterArray.clear();
	std::cout << "DONE.";
}

void Roster::parse(std::string_view row) {
	std::stringstream line;
	line << row;

	std::string word;
	std::vector<std::string> wordArr;
	while (getline(line, word, ',')) {
		wordArr.emplace_back(word);
	}

	DegreeProgram program;
	if (wordArr[8] == "SECURITY")
		program = SECURITY;
	if (wordArr[8] == "NETWORK")
		program = NETWORK;
	if (wordArr[8] == "SOFTWARE")
		program = SOFTWARE;

	add(wordArr[0], wordArr[1], wordArr[2], wordArr[3], stoi(wordArr[4]), stoi(wordArr[5]), stoi(wordArr[6]), stoi(wordArr[7]), program);
}

void Roster::add(std::string_view studentID, std::string_view fName, std::string_view lName, std::string_view email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
	std::vector<int> numDaysToComplete{ daysInCourse1, daysInCourse2, daysInCourse3 };
	Student newStudent{ studentID, fName, lName, email, age, numDaysToComplete, program };
	classRosterArray.emplace_back(newStudent);
}

void Roster::remove(std::string_view studentID) {
	bool found{ false };

	auto remove = [studentID](auto& student) { student.setFName("bob"); return student.getStudentID() == studentID; };
	if (found = erase_if(classRosterArray, remove)) {
		std::cout << "\nRemoving " << studentID << '\n';
	}

	if (!found) {
		std::cout << "\nThe student with the ID: " << studentID << " was not found.\n";
	}
}

void Roster::printAll() {
	std::cout << "\nDisplaying all students:\n";
	for (auto& student : classRosterArray) {
		student.print();
	}
}

void Roster::printAverageDaysInCourse(std::string_view studentid) {
	for (auto& student : classRosterArray) {
		if (student.getStudentID() == studentid) {
			int total{ 0 };
			int count{ 0 };
			for (const auto& days : student.getNumDaysToComplete()) {
				total += days;
				++count;
			}
			int average{ total / count };

			std::cout << "Student ID: " << studentid << ", average days in course is: " << average << '\n';
		}
	}
}

void Roster::printInvalidEmails() {
	std::cout << "\nDisplaying invalid emails:\n\n";

	for (auto& student : classRosterArray) {
		if ((student.getEmail().find("@") == std::string::npos) ||
			(student.getEmail().find(".") == std::string::npos) ||
			(student.getEmail().find(" ") != std::string::npos)) {
			std::cout << student.getEmail() << " - is invalid.\n";
		}
	}
	std::cout << '\n';
}

void Roster::printByDegreeProgram(DegreeProgram program) {
	std::cout << "\nShowing students in degree program: ";
	switch (program) {
	case SECURITY: std::cout << "SECURITY\n\n";
		break;
	case NETWORK: std::cout << "NETWORK\n\n";
		break;
	case SOFTWARE: std::cout << "SOFTWARE\n\n";
		break;
	}

	for (auto& student : classRosterArray) {
		if (student.getProgram() == program) {
			student.print();
		}
	}
}