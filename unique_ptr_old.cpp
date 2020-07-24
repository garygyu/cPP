/*
Use of copy-and-swap idiom <=> assignment operator
Class must have a workable copy-constructor and a workable destructor 
A way of implementing the assignment operator in terms of a swap function
A move-constructor changes the ownership of some resource one object manages to another object
The old object's ownership is set to nullptr
OR, in other words:
The goal of move-construction is to take the resources from another instance of the class, 
leaving it in a state guaranteed to be assignable and destructible.

std::move 
is a way of saying, "ok, honest to God I know I have an lvalue, but I want it to be an rvalue." std::move does not, in and of itself, move anything; it just turns an lvalue into an rvalue, so that you can invoke the move constructor.
*/


#include <iostream>
#include <algorithm>

template<typename T>
class unique_ptr
{
	T* ptr;
public:
	explicit unique_ptr(T* p = nullptr) : ptr(p)
	{
		std::cout << "unique_ptr constructor called \n";
		if(ptr != nullptr) ptr->count++;
	};

	unique_ptr(const unique_ptr& p)
	{
		std::cout << "unique_ptr copy constructor called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		ptr->count++;
	}

	unique_ptr(unique_ptr&& p)
	{
		std::cout << "unique_ptr move constructor called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		p.ptr = nullptr;
	}

	unique_ptr& operator =(const unique_ptr& p)
	{
		std::cout << "unique_ptr assignment operator called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		ptr->count++;
		return *this;
	}

	unique_ptr& operator= (unique_ptr&& p)
	{
		std::cout << "unique_ptr move assignment operator called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		p.ptr = nullptr;
		return *this;
	}

	virtual ~unique_ptr() {if(ptr->count == 1) delete ptr;}

//	T* operator->() const
//	{
//		return ptr;
//	}

//	T& operator*() const
//	{
//		return *ptr;
//	}
};

class Shape
{
	protected:
		double area;

	public:
		static int count;

		Shape() : area(0.) {std::cout << "Shape ctor called\n";}
		virtual ~Shape(){};

		inline double getArea() {return area;}
};
class Triangle : public Shape
{
	private:
		double height;
		double width;

		void calcArea()
		{
			area = 0.5*height*width;
		}
	public:
		Triangle() : Shape(), height(0), width(0) 
				{std::cout << "Triangle default ctor called\n";}
		Triangle(double h, double w) : height(h), width(w) 
		{
			std::cout << "Triangle 2-arg ctor called\n";
			calcArea();
		}
		
		virtual ~Triangle(){};
};

template<class T>
decltype(auto) makeAtriangle(T&&)
//unique_ptr<T> makeAtriangle()
{
	//std::cout << "Inside factory function\n";
	return unique_ptr<T>(new T);
}

int Shape::count = 0;

int main(int argc, char* argv[])
{
	unique_ptr<Shape> a (new Triangle); // Shape ctor
										// Triangle ctor
										// unique_ptr ctor
										// a is an lvalue
	//unique_ptr<Shape> b(std::move(a)); // unique_ptr move ctor called
	//unique_ptr<Shape> c(a); // unique_ptr copy ctor called
	
	//unique_ptr<Shape> d; // unique_ptr ctor
	//d = a;  // unique_ptr assign operator called

	//d = make_triangle(); // make_triangle() returns rvalue
						// unique_ptr move assign operator called
	//unique_ptr<Shape> e(std::forward<unique_ptr<Shape>>(makeAtriangle()));
	unique_ptr<Shape> e(makeAtriangle(Triangle()));
	//unique_ptr<Shape> f(std::forward<unique_ptr<Shape>>(a));
//	std::cout << "Outside factory function\n";
    return 0;
}

