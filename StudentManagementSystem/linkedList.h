#pragma once

#include <iostream>

template <class Type>
class Node
{
public:

	Type Data;
	Node* Next;
	Node* Prev;

	Node<Type>()
	{
		Data = NULL;
		Next = NULL;
		Prev = NULL;
	}

	friend std::ostream& operator << (std::ostream& out, const Node<Type>& val)
	{
		out << val.Data << "	";
		return out;
	}

	void setData(Type data)
	{
		this->Data = data;
	}

	void operator=(Node<Type> secondNode)
	{
		this->Data = secondNode.Data;
		this->Next = secondNode.Next;
		this->Prev = secondNode.Prev;
	}

};

template <class Type>
class List
{
private:
	Node<Type>* DummyNode;
	Node<Type>* head;
	Node<Type>* tail;
	unsigned int Size;

public:
	class iterator
	{
	private:
		Node<Type>* currentNode;
		friend class Node<Type>;
	public:
		iterator()
		{
			currentNode = NULL;
		}

		iterator(Node<Type>* myNode)
		{
			currentNode = myNode;
		}

		iterator operator++()
		{
			if (currentNode == NULL)
				throw std::out_of_range("cannot increase bigger than list size");
			currentNode = currentNode->Next;
			return *this;
		}

		iterator operator--()
		{
			currentNode = currentNode->Prev;
			return *this;
		}

		Node<Type>& operator *()
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

		void operator =(Node<Type>* currNode)
		{
			this->currentNode = currNode;
		}

	protected:

	};

	List<Type>()
	{
		head = NULL;
		tail = NULL;
		Size = 0;
		DummyNode = NULL;
	}

	List<Type>(Type value, int initSize)
	{
		for (int i = 0; i < initSize; i++)
		{
			Node<Type>* newNode = new Node<Type>();
			newNode->setData(value);
			if (i == 0)
			{
				head = newNode;
			}
			if (i == initSize - 1)
			{
				tail = newNode;
			}
		}
		tail->Next = DummyNode;
		DummyNode->Prev = tail;
		Size = initSize - 1;
	}


	void appendFirst(Type newData)
	{
		if (head == NULL && tail == NULL)
		{
			Node<Type>* temp = new Node<Type>();
			temp->setData(newData);
			head = temp;
			tail = temp;
			DummyNode = new Node<Type>();
			DummyNode->Prev = tail;
			tail->Next = DummyNode;
		}
		else
		{
			Node<Type>* temp = new Node<Type>();
			temp->setData(newData);
			temp->Next = head;
			head->Prev = temp;
			head = temp;
		}
		++Size;
	}

	void insert(iterator position, Type newData)
	{
		if (head == NULL && tail == NULL)
		{
			head->setData(newData);
			tail = head;
		}
		else
		{
			if (position == begin())
			{
				appendFirst(newData);
			}

			else if (position == end())
			{
				append(newData);
			}

			else if (position != begin() && position != end())
			{
				iterator current = begin();
				bool Found = false;
				do
				{
					++current;
					if (current == position)
					{
						Found = true;

						Node<Type>* newNode = new Node<Type>();
						newNode->setData(newData);

						Node<Type>* foundNode = &*current;
						Node<Type>* prevNode = foundNode->Prev;

						prevNode->Next = newNode;
						foundNode->Prev = newNode;

						newNode->Next = foundNode;
						newNode->Prev = prevNode;
						++Size;
					}
					else if (current == end())
					{
						append(newData);
						Found = true;
					}

					else if (current == ++end())
					{
						throw std::out_of_range("Trying to insert outside of list");
					}

				} while (!Found);

			}

		}
	}

	void append(Type newData)
	{
		Node<Type>* temp = new Node<Type>();
		temp->setData(newData);
		if (head == NULL && tail == NULL) {
			head = temp;
			tail = temp;
			DummyNode = new Node<Type>();
			tail->Next = DummyNode;
			DummyNode->Prev = tail;
		}

		//[] -> = tail & head
		//[1] -> = tail, prev = prevTail
		//[1, 2] -> = tail, prev = prevTail

		else
		{
			temp->Prev = tail;
			tail->Next = temp;
			tail = temp;

			DummyNode = new Node<Type>();
			tail->Next = DummyNode;

			DummyNode->Prev = tail;
		}
		++Size;
	}

	void erase(iterator position)
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
	}

	int getSize()
	{
		return Size;
	}

	List<Type>& operator=(List<Type> anotherList)
	{

	}

	~List<Type>()
	{
		Node<Type>* temp = new Node<Type>();
		temp = head;

		while (head != NULL) {
			// [1, 2, 3, 4]
			// []
			temp = head->Next;
			delete head;
			head = temp;
		}

		tail = head = DummyNode = NULL;
		delete tail;
		delete head;
		delete DummyNode;
		delete temp;
		Size = 0;
	}

	iterator begin()
	{
		return iterator(head);
	}



	iterator end()
	{
		return iterator(DummyNode);
	}



	friend std::ostream& operator << (std::ostream& out, List<Type>& myList)
	{
		Node<Type>* CurrentNode = new Node<Type>();
		CurrentNode = myList.head;
		for (int i = 0; i < myList.Size; i++)
		{
			out << *CurrentNode;
			CurrentNode = CurrentNode->Next;
		}
		return out;
	}

protected:

	friend class Node<Type>;
};