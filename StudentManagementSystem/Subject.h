#pragma once

#include <iostream>
class SubjectList;

class Subject
{
private:
	std::string subjectName;
	double gradePointAverage;
	char grade;
	int total;
	Subject* next;

public:
	Subject()
	{
		subjectName = "";
		gradePointAverage = 0.0;
		grade = '\0';
		total = 0;
		next = NULL;
	}
	
	Subject(std::string name, double average, char Grade, int Total)
	{
		subjectName = name;
		gradePointAverage = average;
		grade = Grade;
		total = Total;
		next = NULL;
	}

	void setData(std::string name, double average, char Grade, int Total)
	{
		subjectName = name;
		gradePointAverage = average;
		grade = Grade;
		total = Total;
		next = NULL;
	}

	friend class SubjectList;
};

class SubjectList
{
private:
	Subject* head;

public:

	SubjectList()
	{
		head = nullptr;
	}

	SubjectList(int numOfSubjects)
	{
	}
};
