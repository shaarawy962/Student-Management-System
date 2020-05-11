#pragma once

#include "Subject.h"

class StudentList;

class Student
{
private:
	std::string Name;
	std::string dept;
	int numberOfCourses;

public:


	friend class StudentList;
};
