#pragma once

#include <iostream>

class Subject
{
private:
	std::string subjectName;
	double gradePointAverage;
	char grade;
	int total;

public:
	Subject()
	{
		subjectName = "";
		gradePointAverage = 0.0;
		grade = '\0';
		total = 0;
	}
	
	Subject(std::string name, double average, char Grade, int Total)
	{
		subjectName = name;
		gradePointAverage = average;
		grade = Grade;
		total = Total;
	}

	void setData(std::string name, double average, char Grade, int Total)
	{
		subjectName = name;
		gradePointAverage = average;
		grade = Grade;
		total = Total;
	}
};