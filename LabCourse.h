// Author: Abinash Chetia
// Date: 12/09/2021
#pragma once
#include "Course.h"
class LabCourse : public Course
{
public:
	LabCourse();
	LabCourse(std::string, std::string, int);
	std::string result();
};