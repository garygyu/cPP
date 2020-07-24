// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//T** pointer to an array containig element type T
//array name is the address of its first element
template<class T>
void bubbleSort(T**, int);

template<class T>
void bubbleRevSort(T**, int);

template<class T>
void order(T**, T**);

template <class T>
void reverseOrder(T**, T**);

template<class T>
void disp(T**);

template<class T>
void del(T**);

class person
{
private:
	string name_;
public:
	person(string name) : name_(name)
	{}
	inline string getName() 
	{
		return name_; 
	}
};

int main(int argc, char* argv[])
{
	person* persPtrArr[4] =
	{new person("Jefferson"), new person("Midison"), new person("Washington"), new person("Adams")};

	//char* persPtrArr[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	disp(persPtrArr);

	cout << endl;

	bubbleSort(persPtrArr, 4);

	disp(persPtrArr);
	cout << "\n";

// reverse the ordered array
	bubbleRevSort(persPtrArr, 4);

	disp(persPtrArr);

	del(persPtrArr);

	return 0;
}

template<class T> void bubbleSort(T** ptrPtr, int Max)
{
	for (int i = 0; i < Max - 1; i++)
	{
		for (int j = i + 1; j < Max; j++)
		{
			order(ptrPtr + i, ptrPtr + j);
		}
	}
}


template<class T> void order(T** pp1, T** pp2)
{
	if ((*pp1)->getName() > (*pp2)->getName())
	{
		T* temp = *pp1;
		*pp1 = *pp2;
		*pp2 = temp;
	}
}

template<class T>
void bubbleRevSort(T** pp, int n)
{
	for(auto i=0; i<n-1; i++)
	{
		for(auto j=i+1; j<n; j++)
		{
			reverseOrder(pp+i, pp+j);
		}
	}
}
template<class T>
void reverseOrder(T** pp1, T** pp2)
{
	if((*pp1)->getName() < (*pp2)->getName())
	{
		T* temp = *pp1;
		*pp1 = *pp2;
		*pp2 = temp;
	}
}

template<class T> void disp(T** ptoPoiter)
{
	for (int i = 0; i < 4; i++)
	{
		cout << ptoPoiter[i]->getName() << endl;
	}
}

template<class T> void del(T** ptoPoiter)
{
	for (int i = 0; i < 4; i++)
	{
		delete *(ptoPoiter+i);
	}
}
