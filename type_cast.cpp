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
inline const TargetType* isA(const Type& t)
{
	const Type* p = &t;
	return dynamic_cast<const TargetType*>(p);
}

template<class To, class From>
inline To& refCast(From& r)
{
	try
	{
		return dynamic_cast<To&>(r);
	}
	catch (const std::bad_cast&)
	{
		cout << "Attepting to cast type " << typeid(r).name()
			<< " to type " << typeid(To).name() << " "
			<< "abort" << endl;
		exit(1);

		return dynamic_cast<To&>(r);
	}
}

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

class Rect : public Shape
{
private:
	double length, width;

public:
	Rect() : length(0), width(0) {};
	Rect(double l, double w) : Shape(), length(l), width(w) {};

	double calcArea()
	{
		cout << "\nrect function called!\n";
		return length*width;
	}
};

class Square : public Rect
{
private:
	double length;

public:
	Square() : length(0){};
	Square(double len) : Rect(len, len), length(len){};

	double calcArea()
	{
		cout << "\nsquare function called!\n";
		return length*length;
	}
};

int main(int argc, char* argv[])
{
	Circle circle(10);
	if (isA<Shape>(circle)) //if (isA<Shape, Circle>(circle))
	{
		Shape* shape = &circle;
		cout << "shape area = " << shape->calcArea() << endl;
	}
	else
	{
		cout << "Nothing converted!" << endl;
	}

	Rect rect(10, 2);
	cout << "shape area = " << rect.calcArea() << endl;

	Square square(5);
	cout << "shape area = " << square.calcArea() << endl;
	cout << "shape area = " << refCast<Rect>(square).calcArea() << endl;

	return 0;
}
