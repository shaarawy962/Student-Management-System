#pragma once

#include "Subject.h"

class StudentList;

class Student
{
private:
	std::string Name;
	std::string dept;
	int numberOfCourses;
	SubjectList* Courses;
	unsigned int ID;
	Student* nextStud;
	static unsigned int StudentCount;

public:

	Student()
	{
		Name = "";
		dept = "";
		numberOfCourses = 0;
		Courses = new SubjectList;
		nextStud = nullptr;
		ID = ++StudentCount;
	}

	Student(std::string name, std::string department, int numOfCourses)
	{
		Name = name;
		dept = department;
		numberOfCourses = numOfCourses;
		nextStud = NULL;
	}

	friend std::istream& operator >>(std::istream& in, Student& param)
	{
		std::getline(in, param.Name);
		in >> param.dept;
		in >> param.numberOfCourses;
		return in;
	}

	SubjectList* GetCourses()
	{
		return this->Courses;
	}

	friend class StudentList;
};

class StudentList
{
private:
	Student* DummyNode;
	Student* head;
	Student* tail;
	Student* curr;
	unsigned int Size;

	/*Student* search(Student* param)
	{
		Student* curr = head;
		
		while (curr != NULL)
		{
			if (curr == param)
				return curr;
			else
			{
				curr = curr->nextStud;
			}
		}
	}*/

public:
	class iterator
	{
	private:
		Student* currentNode;
		friend class Student;
	public:
		iterator()
		{
			currentNode = NULL;
		}

		iterator(Student* myNode)
		{
			currentNode = myNode;
		}

		iterator operator++()
		{
			if (currentNode == NULL)
				throw std::out_of_range("cannot increase bigger than list size");
			currentNode = currentNode->nextStud;
			return *this;
		}

		Student& operator *()
		{
			return *currentNode;
		}

		bool operator ==(iterator it)
		{
			if (it.currentNode == this->currentNode)
				return true;
			return false;
		}

		bool operator !=(iterator it)
		{
			if (it.currentNode != this->currentNode)
				return true;
			return false;
		}

		void operator =(iterator it)
		{
			this->currentNode = it.currentNode;
		}

		void operator =(Student* currNode)
		{
			this->currentNode = currNode;
		}

	protected:

	};

	StudentList()
	{
		head = NULL;
		tail = NULL;
		Size = 0;
		DummyNode = NULL;
		curr = NULL;
	}

	void append(Student* param)
	{
		
		
		if (head == NULL && tail == NULL) {
			head = param;
			tail = param;
			curr = param;
			tail->nextStud = DummyNode;
		}

		//[] -> = tail & head
		//[1] -> = tail, prev = prevTail
		//[1, 2] -> = tail, prev = prevTail

		else
		{
			tail->nextStud = param;
			tail = param;
			tail->nextStud = DummyNode;
			curr = param;
		}
		++Size;
	}

	/*void erase(iterator position)
	{
		if (position == end())
			throw std::out_of_range("Trying to erase outside the list");

		else
		{
			if (position == begin())
			{
				head = head->Next;
				delete head->Prev;
			}

			else if (position == --end())
			{
				tail = tail->Prev;
				delete tail->Next;
			}

			else
			{
				iterator current = begin();
				while (current != position)
				{
					++current;
				}

				Node<Type>* currNode = &*current;
				Node<Type>* prevNode = currNode->Prev;

				prevNode->Next = currNode->Next;
				currNode->Next->Prev = prevNode;
				delete currNode;
			}
		}
		--Size;
	}*/

	int getSize()
	{
		return Size;
	}

	//~StudentList()
	//{
	//	Student* temp = new Node<Type>();
	//	temp = head;

	//	while (head != NULL) {
	//		// [1, 2, 3, 4]
	//		// []
	//		temp = head->Next;
	//		delete head;
	//		head = temp;
	//	}

	//	tail = head = DummyNode = NULL;
	//	delete tail;
	//	delete head;
	//	delete DummyNode;
	//	delete temp;
	//	Size = 0;
	//}

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{
		return iterator(DummyNode);
	}

	/*friend std::ostream& operator << (std::ostream& out, StudentList& myList)
	{
		Student* CurrentNode = new Node<Type>();
		CurrentNode = myList.head;
		for (int i = 0; i < myList.Size; i++)
		{
			out << *CurrentNode;
			CurrentNode = CurrentNode->Next;
		}
		return out;
	}*/

	void AddStudent()
	{
		Student* curr = new Student();
		std::cin >> *curr;
		append(curr);
		std::cin.ignore(1000, '\n');
	}

	Student* getCurr()
	{
		return curr;
	}


	protected:
};

unsigned int Student::StudentCount = 2018000;