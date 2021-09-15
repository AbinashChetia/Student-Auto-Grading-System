// Author: Abinash Chetia
// Date: 12/09/2021
#include "TheoryCourse.h"
#include <string>
TheoryCourse::TheoryCourse() : Course() { }
TheoryCourse::TheoryCourse(std::string courseID_, std::string courseName_, int credit_) : Course(courseID_, courseName_, credit_) { }
std::string TheoryCourse::result() {
	if (getMarksEnd() >= 28 && (getMarksIn() + getMarksEnd() >= 40))
		return "Pass";
	else
		return "Fail";
}