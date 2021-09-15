// Author: Abinash Chetia
// Date: 12/09/2021
#pragma once
#include "Course.h"
class TheoryCourse : public Course
{
public:
	TheoryCourse();
	TheoryCourse(std::string, std::string, int);
	std::string result();
};