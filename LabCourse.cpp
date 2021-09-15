// Author: Abinash Chetia
// Date: 12/09/2021
#include "LabCourse.h"
#include <string>
LabCourse::LabCourse() : Course() { }
LabCourse::LabCourse(std::string courseID_, std::string courseName_, int credit_) : Course(courseID_, courseName_, credit_) { }
std::string LabCourse::result() {
	if (getMarksEnd() >= 35 && (getMarksIn() + getMarksEnd() >= 50))
		return "Pass";
	else
		return "Fail";
}