// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib> // use of atoi() and atof()
#include <fstream>
#include <list>
#include <deque>
#include <algorithm>
#include <typeinfo>

using namespace std;


// When called Only one type of template parameter can be deduced by complier
// from function argument. i.e. "class Type" can be deduced
// the "class TargetType " should be explicitly specified by 
// isA<TargetType>(t)
// checking if t can be cast as TargetType


template<class TargetType, class Type>
inline bool isType(const Type& t)
{
	return typeid(TargetType) == typeid(t);
}

template<class TargetType>
struct isTypeOp
{
	template<class Type>
	inline bool operator() (const Type& t) const
	{
		return isType<TargetType, Type>(t);
	}
};

class Shape
{
protected:

public:
	virtual double calcArea() = 0;
};

class Circle : public Shape
{
private:
	double radius;
	
public:
	Circle() : radius(0){};
	Circle(double r) : Shape(), radius(r){};

	double calcArea()
	{
		return 3.14*radius*radius;
	}
};

class Square : public Shape
{
private:
	double length;

public:
	Square() : length(0){};
	Square(double len) : Shape(), length(len){};

	double calcArea()
	{
		return length*length;
	}
};

// only one operator is defined in the class
class MultiplyBy
{
private:
	int factor;
public:
	MultiplyBy(int x) : factor(x) {};

	inline int operator()(int other) const
	{
		return factor*other;
	}
};

struct Add
{
private:
	int x;
public:
	Add(int val) : x(val) {};
	inline int operator()(int y)
	{
		return x + y;
	}
};

int main(int argc, char* argv[])
{
	//int array[5] = { 1, 2, 3, 4, 5 };
	int array[] = { 1, 2, 3, 4, 5 };
	auto y = 3;
	//std::transform(array, array + 5, array, MultiplyBy(3));
	std::transform(array, array+5, array, [y](auto x){return y*x;});

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << array[i] << " ";
	//}

	std::for_each(array, array+5, [](auto x){ cout << x << " ";});
	cout << "\n";

	for(auto& i : array)
	{
		i = i + 3;
		//cout << i << " ";
	}

	std::for_each(array, array+5, [](auto x){ cout << x << " ";});

	cout << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << Add(3)(array[i]) << " ";
	//}
	//cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << MultiplyBy(3)(array[i]) << " ";
	}
	cout << endl;

	Circle circle(10);
	Square square(5);
	
	// isTypeOp<Circle>() 
	// 0-argument constructor, default constructor
	// to create an unamed isTypeOp<Circle> object
	// which then invokes its member operator () with argument "square"
	// isTypeOp<Circle>()(square)
	// equivalent to

	isTypeOp<Circle> isCircle;
	if (isCircle(square))
	//if (isTypeOp<Circle>()(circle))
	{
		cout << " Identicle !!!" << endl;
	}
	else
	{
		cout << "Not identical\n";
	}

	return 0;
}
