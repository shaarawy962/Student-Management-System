#pragma once

#include "Student.h"

struct Node
{
	Student data;
	Node* next;

	Node()
	{
		next = NULL;
	}
	Node(Student Data)
	{
		data = Data;
	}

	void setData(Student Data)
	{
		data = Data;
	}
};

class List
{
private:
	Node* head;
	Node* tail;

public:

};