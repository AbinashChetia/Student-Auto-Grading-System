// Author: Abinash Chetia
// Date: 12/09/2021
#pragma once
#include "Course.h"
#include <iostream>
#include <string>
#include <vector>
class Student
{
private:
	std::string name, rollNo;
	int courseNum;
	Course** courses = NULL;
	std::vector<std::vector<std::string>> CourseIDs = {
		{"CSE401", "t", "Discrete Mathematics", "4" },
		{"CSE402", "t", "Operating System", "3"},
		{"CSE412", "l", "Operating System Lab", "2"},
		{"CSE403", "t", "Object Oriented Programming", "3"},
		{"CSE413", "l", "Object Oriented Programming Lab", "2"},
		{"CSE404", "t", "Database Management System", "3"},
		{"CSE414", "l", "Database Management System Lab", "2"},
	};
public:
	Student();
	Student(std::string);
	Student(std::string, std::string);
	~Student();
	void getResult();
	std::string getName();
	std::string getRollno();
	int getCourseNum();
	Course** getCourses();
};