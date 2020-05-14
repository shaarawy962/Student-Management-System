#pragma once

#include "Student.h"

struct Interface
{
	StudentList* List = new StudentList();

	void Greetings()
	{
		std::cout << std::string(15, '-') 
			<< " Welcome to Student Management System project " 
			<< std::string(15, '-') 
			<< std::endl;

		MainMenu();
	}

	void DisplayMenu()
	{
		std::cout << "[1]	Add student\n";
		std::cout << "[2]	Add several students\n";
		std::cout << "[3]	Add Subject to a certain student\n";
		std::cout << "[4]	Print out a certain student\n";
		std::cout << "[5]	Print out all students\n";
		std::cout << "[6]	Exit\n";
	}

	void run()
	{
		Greetings();
	}

	void MainMenu()
	{
		bool isProgramclosed = false;
		char Answer;
		while (!isProgramclosed)
		{
			DisplayMenu();
			Input(Answer);
			int numberOfStudents = 1;
			switch (Answer)
			{
			case '1':
				List->AddStudents();
				std::cout << "Student's details\n" << *List->getCurr();
				isProgramclosed = false;
				break;
			case '2':
				std::cout << "Please enter number of students: ";
				std::cin >> numberOfStudents;
				std::cin.ignore(256, '\n');
				List->AddStudents(numberOfStudents);
				break;
			case '3':
				searchForStudent();
				List->getCurr()->GetCourses()->AddSubject();
				isProgramclosed = false;
				break;
			case '4':
				searchForStudent();
				std::cout << *(List->getCurr());
				isProgramclosed = false;
				break;
			case '5':
				std::cout << *List;
				break;
			case'6':
				isProgramclosed = true;
				break;
			default:
				isProgramclosed = false;
				break;
			}

		}
	}

	char Input(char& param)
	{
		std::cin >> param;
		std::cin.ignore(256, '\n');
		return param;
	}

	bool checkInput(char Input, bool isValid)
	{
		
	}

	void searchForStudent()
	{
		unsigned int ID = 0;
		std::cout << "Please enter the student's ID: ";
		std::cin >> ID;
		std::cin.ignore(256, '\n');
		List->find(ID);
	}
};