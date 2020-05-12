#pragma once

#include <iostream>
#include <string>

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

	friend std::istream& operator >>(std::istream& in, Subject& param)
	{
		std::getline(in, param.subjectName);
		in >> param.gradePointAverage;
		in >> param.grade;
		in >> param.total;
		return in;
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
			currentNode = currentNode->next;
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
			tail->next = DummyNode;
		}

		//[] -> = tail & head
		//[1] -> = tail, prev = prevTail
		//[1, 2] -> = tail, prev = prevTail

		else
		{
			tail->next = param;
			tail = param;
			tail->next = DummyNode;
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
		Subject* curr = new Subject();
		std::cin >> *curr;
		append(curr);
	}

protected:
};