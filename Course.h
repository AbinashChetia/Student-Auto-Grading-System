// Author: Abinash Chetia
// Date: 12/09/2021
#pragma once
#include <string>
class Course
{
private:
	std::string courseID, name;
	float marksInsem, marksEndsem;
	int credit;
public:
	Course();
	Course(std::string, std::string, int);
	std::string getID();
	std::string getName();
	float getMarksIn();
	float getMarksEnd();
	virtual std::string result() = 0;
};