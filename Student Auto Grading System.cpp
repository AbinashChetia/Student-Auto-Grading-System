// Author: Abinash Chetia
// Date: 12/09/2021
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Course.h"
#include "Student.h"
#include "TheoryCourse.h"
#include "LabCourse.h"
void exportCSV(Student**, int);
int main() {
	std::cout << "\tSTUDENT AUTO GRADING SYSTEM\n";
	char opt;
	int n;
	std::cout << "Enter number of students: ";
	std::cin >> n;
	Student** stud = new Student*[n];
	std::cout << "Do you want to use the CSV file, Courses.csv, containing the courses available for students? (Y/n): ";
	bool chk = true;
	while (chk) {
		std::cin >> opt;
		if (opt == 'Y' || opt == 'y') {
			std::cout << "Courses.csv will be used.\n";
			chk = false;
			std::cout << "\nEnter Student details:\n";
			for (int i = 0; i < n; i++) {
				std::string name;
				std::cout << "\tStudent " << i + 1 << " :\n\tName: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::string rollNo;
				std::cout << "\tRoll No.: ";
				std::cin >> rollNo;
				Student* s = new Student(name, rollNo);
				stud[i] = s;
			}
		}
		else if (opt == 'N' || opt == 'n') {
			std::cout << "The integrated data of courses available for the students will be used.\n";
			chk = false;
			std::cout << "\nEnter Student details:\n";
			for (int i = 0; i < n; i++) {
				std::string name;
				std::cout << "\tStudent " << i + 1 << " :\n\tName: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				Student* s = new Student(name);
				stud[i] = s;
			}
		}
		else
			std::cout << "\nError: Invalid entry.\nEnter a valid entry: ";
	}
	std::cout << "\nStudent results:\n\tRoll No.\t\tCourse ID\tResult\n\t----------------------------------------------\n";
	for (int i = 0; i < n; i++)
		stud[i]->getResult();
	std::cout << "\nDo you want to export the data into a CSV file? (Y/n): ";
	chk = true;
	while (chk) {
		std::cin >> opt;
		if (opt == 'Y' || opt == 'y') {
			chk = false;
			exportCSV(stud, n);
		}
		else if (opt == 'N' || opt == 'n') {
			chk = false;
			break;
		}
		else
			std::cout << "Error: Invalid input.\nEnter a valid input: ";
	}
	delete[] stud;
	std::cout << "Program exited successfully.\n";
	return 0;
}
void exportCSV(Student** stud, int n) {
	struct tm tPtr;
	time_t now = time(0);
	localtime_s(&tPtr, &now);
	std::fstream fout;
	fout.open("Results.csv", std::ios::out | std::ios::app);
	fout << "Name,Roll No.,Course Code,Course Name,In-sem Marks,End-sem Marks,Result," << tPtr.tm_hour << ":" << tPtr.tm_min << ":" << tPtr.tm_sec << "," << tPtr.tm_mday << "/" << tPtr.tm_mon + 1 << "/" << tPtr.tm_year + 1900 << "\n";
	for (int i = 0; i < n; i++) {
		fout << stud[i]->getName() << "," << stud[i]->getRollno();
		int count = 0;
		for (int j = 0; j < stud[i]->getCourseNum(); j++) {
			if (count == 0) {
				fout << "," << stud[i]->getCourses()[j]->getID() << "," << stud[i]->getCourses()[j]->getName() << "," << stud[i]->getCourses()[j]->getMarksIn() << "," << stud[i]->getCourses()[j]->getMarksEnd() << "," << stud[i]->getCourses()[j]->result() << "\n";
				count++;
			}
			else
				fout << ",," << stud[i]->getCourses()[j]->getID() << "," << stud[i]->getCourses()[j]->getName() << "," << stud[i]->getCourses()[j]->getMarksIn() << "," << stud[i]->getCourses()[j]->getMarksEnd() << "," << stud[i]->getCourses()[j]->result() << "\n";
		}
	}
	std::cout << "\nExported to Results.csv.\n";
}