#pragma once

#include <iostream>
#include <string>

class Student;
class SubjectList;

class Subject
{
private:
	std::string subjectName;
	double gradePointAverage;
	char grade;
	int total;
	Subject* nextSubject;
public:
	Subject* next()
	{
		return nextSubject;
	}

	Subject()
	{
		subjectName = "";
		gradePointAverage = 0.0;
		grade = '\0';
		total = 0;
		nextSubject = NULL;
	}
	
	Subject(std::string name, double average, char Grade, int Total)
	{
		subjectName = name;
		gradePointAverage = average;
		grade = Grade;
		total = Total;
		nextSubject = NULL;
	}

	void setData(std::string name, double average, char Grade, int Total)
	{
		subjectName = name;
		gradePointAverage = average;
		grade = Grade;
		total = Total;
		nextSubject = NULL;
	}

	friend class SubjectList;

	friend std::istream& operator >>(std::istream& in, Subject& param)
	{
		std::getline(in, param.subjectName);
		in >> param.gradePointAverage;
		in >> param.grade;
		in >> param.total;
		return in;
	}

	friend std::ostream& operator <<(std::ostream& out, Subject& param)
	{
		out << "Subject name: " << param.subjectName << "\n";
		out << "GPA: " << param.gradePointAverage << "\n";
		out << "Grade: " << param.grade << "\n";
		out << "Total marks: " << param.total << "\n";
		return out;
	}
};

//class SubjectList
//{
//private:
//	Subject* head;
//	Subject* tail;
//	
//	void insert()
//	{
//
//	}
//public:
//
//	SubjectList()
//	{
//		head = nullptr;
//	}
//
//	void AddSubject()
//	{
//
//	}
//};	

class SubjectList
{
private:
	Subject* DummyNode;
	Subject* head;
	Subject* tail;
	unsigned int Size;
	unsigned int maxSize;
	int count = 0;

public:
	class iterator
	{
	private:
		Subject* currentNode;
		friend class Subject;
	public:
		iterator()
		{
			currentNode = NULL;
		}

		iterator(Subject* myNode)
		{
			currentNode = myNode;
		}

		iterator operator++()
		{
			if (currentNode == NULL)
				throw std::out_of_range("cannot increase bigger than list size");
			currentNode = currentNode->nextSubject;
			return *this;
		}

		Subject& operator *()
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

		void operator =(Subject* currNode)
		{
			this->currentNode = currNode;
		}

	protected:

	};

	SubjectList()
	{
		head = NULL;
		tail = NULL;
		Size = 0;
		DummyNode = NULL;
	}

	void append(Subject* param)
	{


		if (head == NULL && tail == NULL) {
			head = param;
			tail = param;
			tail->nextSubject = DummyNode;
		}

		//[] -> = tail & head
		//[1] -> = tail, prev = prevTail
		//[1, 2] -> = tail, prev = prevTail

		else
		{
			tail->nextSubject = param;
			tail = param;
			tail->nextSubject = DummyNode;
		}
		++Size;
	}

	void setMax(unsigned int size)
	{
		maxSize = size;
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

	//~SubjectList()
	//{
	//	Subject* temp = new Node<Type>();
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

	/*friend std::ostream& operator << (std::ostream& out, SubjectList& myList)
	{
		Subject* CurrentNode = new Node<Type>();
		CurrentNode = myList.head;
		for (int i = 0; i < myList.Size; i++)
		{
			out << *CurrentNode;
			CurrentNode = CurrentNode->Next;
		}
		return out;
	}*/

	void AddSubject()
	{
		while (count < maxSize)
		{
			Subject* curr = new Subject();
			std::cin >> *curr;
			append(curr);
			count++;
			return;
		}
		std::cout << "Subject list is full\n";
	}

	friend std::ostream& operator <<(std::ostream& out, SubjectList& param)
	{
		Subject* curr = param.head;
		while (curr !=NULL)
		{
			out << *curr;
			curr = curr->next();
		}
		return out;
	}

protected:
};