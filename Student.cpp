// Author: Abinash Chetia
// Date: 12/09/2021
#include "Student.h"
#include "Course.h"
#include "TheoryCourse.h"
#include "LabCourse.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
Student::Student(){
	courseNum = 0;
}
Student::Student(std::string name_) {
	name = name_;
	std::cout << "\tRoll No.: ";
	std::cin >> rollNo;
	std::cout << "\tNumber of courses taken: ";
	std::cin >> courseNum;
	std::cout << "\tEnter Course details:\n";
	for (int i = 0; i < courseNum; i++) {
		std::cout << "\tCourse " << i + 1 << " :\n";
		std::string id;
		std::cout << "\t\tCourse code: ";
		std::cin >> id;
		int rowNum;
		bool exist = false;
		for (unsigned int j = 0; j < CourseIDs.size(); j++)
			if (id == CourseIDs[j][0]) {
				rowNum = j;
				exist = true;
			}
		if (exist) {
			if (CourseIDs[rowNum][1] == "t") {
				Course** Courses_ = new Course * [courseNum];
				if (i != 0) {
					for (int j = 0; j < i; j++)
						Courses_[j] = courses[j];
					delete[] courses;
				}
				TheoryCourse* c = new TheoryCourse(id, CourseIDs[rowNum][2], std::stoi(CourseIDs[rowNum][3]));
				Courses_[i] = c;
				courses = Courses_;
			}
			else if (CourseIDs[rowNum][1] == "l") {
				Course** Courses_ = new Course * [courseNum];
				if (i != 0) {
					for (int j = 0; j < i; j++)
						Courses_[j] = courses[j];
					delete[] courses;
				}
				LabCourse* c = new LabCourse(id, CourseIDs[rowNum][2], std::stoi(CourseIDs[rowNum][3]));
				Courses_[i] = c;
				courses = Courses_;
			}
		}
		else {
			std::cout << "\t\tInvalid Course code.\n";
			i--;
		}
	}
}
Student::Student(std::string name_, std::string rollNo_) {
	std::vector<std::vector<std::string>> courseIDs;
	std::fstream fin;
	fin.open("Courses.csv", std::ios::in);
	std::string line, word;
	while (!fin.eof()) {
		std::vector<std::string> row;
		row.clear();
		std::getline(fin, line);
		std::stringstream s(line);
		while (std::getline(s, word, ','))
			row.push_back(word);
		courseIDs.push_back(row);
	} 
	name = name_;
	rollNo = rollNo_;
	std::cout << "\tNumber of courses taken: ";
	std::cin >> courseNum;
	std::cout << "\tEnter Course details:\n";
	for (int i = 0; i < courseNum; i++) {
		std::cout << "\tCourse " << i + 1 << " :\n";
		std::string id;
		std::cout << "\t\tCourse code: ";
		std::cin >> id;
		int rowNum;
		bool exist = false;
		for (unsigned int j = 0; j < courseIDs.size(); j++)
			if (id == courseIDs[j][0]) {
				rowNum = j;
				exist = true;
				break;
			}
		if (exist) {
			if (courseIDs[rowNum][1] == "t") {
				Course** Courses_ = new Course * [courseNum];
				if (i != 0) {
					for (int j = 0; j < i; j++)
						Courses_[j] = courses[j];
					delete[] courses;
				}
				TheoryCourse* c = new TheoryCourse(id, courseIDs[rowNum][2], std::stoi(courseIDs[rowNum][3]));
				Courses_[i] = c;
				courses = Courses_;
			}
			else if (courseIDs[rowNum][1] == "l") {
				Course** Courses_ = new Course * [courseNum];
				if (i != 0) {
					for (int j = 0; j < i; j++)
						Courses_[j] = courses[j];
					delete[] courses;
				}
				LabCourse* c = new LabCourse(id, courseIDs[rowNum][2], std::stoi(courseIDs[rowNum][3]));
				Courses_[i] = c;
				courses = Courses_;
			}
		}
		else {
			std::cout << "\t\tInvalid Course code.\n";
			i--;
		}
	}
}
Student::~Student() {
	for (int i = 0; i < courseNum; i++)
		delete courses[i];
	delete[] courses;
}
void Student::getResult() {
	std::cout << "\t" << rollNo;
	for (int i = 0; i < courseNum; i++) {
		if (i == 0)
			std::cout << "\t\t" << courses[i]->getID()  << "\t\t" << courses[i]->result() << "\n";
		else
			std::cout << "\t\t\t\t" << courses[i]->getID() << "\t\t" << courses[i]->result() << "\n";
	}
	std::cout << "\t----------------------------------------------\n";
}
std::string Student::getName() {
	return this->name;
}
std::string Student::getRollno() {
	return this->rollNo;
}
int Student::getCourseNum() {
	return this->courseNum;
}
Course** Student::getCourses() {
	return this->courses;
}