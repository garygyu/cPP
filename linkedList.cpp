// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct link
{
	int data_;
	link* next_;
	link* previous_;
};

class linkedList
{
private:
	link* first_;

	void swap(link**, link**);

public:
	linkedList() : first_(nullptr)
	{}

	virtual ~linkedList();

	void putData(int);
	void displayList();

	void sorted();
};

void linkedList::putData(int d)
{
	link* newlink = new link;
	newlink->data_ = d;
	newlink->next_ = first_;
	if (first_) first_->previous_ = newlink;

	first_ = newlink;
	first_->previous_ = nullptr;
}

void linkedList::displayList()
{
	link* current = first_;
	while (current)
	{
		cout << current->data_ << endl;
		current = current->next_;
	}

	//// find the last
	//link* last = first_;
	//while (last->next_)
	//{
	//	last = last->next_;
	//} 
	//
	//current = last;
	//while (current)
	//{
	//	cout << current->data_ << endl;
	//	current = current->previous_;
	//}
}

void linkedList::swap(link** ptrFirst, link** ptrSecond)
{
	link* first = *ptrFirst;
	link* second = *ptrSecond;

	if (first->data_ > second->data_)
	{
		link* firstNext = first->next_;
		link* firstPrevious = first->previous_;
		link* secondNext = second->next_;
		link* secondPrevious = second->previous_;
		link* temp = first;

		first = second;
		first->next_ = (firstNext == first) ? temp : firstNext;
		first->previous_ = firstPrevious;
		first->next_->previous_ = first;
		if (first->previous_) first->previous_->next_ = first;

		second = temp;
		second->next_ = secondNext;
		second->previous_ = (secondPrevious == temp) ? first : secondPrevious;
		second->previous_->next_ = second;
		if (second->next_) second->next_->previous_ = second;
	}
	*ptrFirst = first;
	*ptrSecond = second;
}

void linkedList::sorted()
{
	int count = 0;
	link* current = first_;
	while (current)
	{
		count++;
		current = current->next_;
	}

	current = first_;
	link* next = nullptr;
	for (int i = 0; i < count - 1; i++)
	{
		next = current->next_;
		for (int j = i + 1; j < count; j++)
		{
			swap(&current, &next);
			next = next->next_;
		}
		if (i == 0) first_ = current;
		current = current->next_;
	}
}

linkedList::~linkedList()
{
	while (first_)
	{
		link* current = first_;
		first_ = current->next_;
		delete current;
	}
}

int main(int argc, char* argv[])
{
	linkedList ll;

	ll.putData(25);
	ll.putData(36);
	ll.putData(10);
	ll.putData(49);
	ll.putData(64);
	ll.putData(11);
	ll.putData(121);


	ll.displayList();
	cout << "\n";
	ll.sorted();
	ll.displayList();
	return 0;
}
