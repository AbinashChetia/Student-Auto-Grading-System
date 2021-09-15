// Author: Abinash Chetia
// Date: 12/09/2021
#include "Course.h"
#include <iostream>
#include <string>
Course::Course() {
	marksInsem = 0;
	marksEndsem = 0;
	credit = 0;
}
Course::Course(std::string courseID_, std::string courseName_, int credit_) {
	name = courseName_;
	courseID = courseID_;
	credit = credit_;
	std::cout << "\t\tIn-semester Exam marks: ";
	std::cin >> marksInsem;
	std::cout << "\t\tEnd-semester Exam marks: ";
	std::cin >> marksEndsem;
}
std::string Course::getID() {
	return this->courseID;
}
std::string Course::getName() {
	return this->name;
}
float Course::getMarksIn() {
	return this->marksInsem;
}
float Course::getMarksEnd() {
	return this->marksEndsem;
}