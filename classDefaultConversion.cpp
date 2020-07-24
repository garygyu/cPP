#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A
{
private:
	int a_;
public:
	//explicit A(int a) : a_(a) {};
	A(int a) : a_(a) {}; // default conversion an int to class A
	inline int getValue() const {return a_;}
	//explicit operator int(){return a_+10;}
	operator int() {return a_;} // default conversion from A->int
};
//const member function MUST be called by const class object
inline void f(const A& a) {cout << a.getValue() << "\n";}
inline void g(int a) {cout << a << "\n";}

int main()
{
	int b = 30;
	A a(10);
	f(a);

	f(b); // with default constructor int -> class A
	//f(static_cast<A>(b));// with expilicit constructor
	 
	g(a); // used with default conversion 
	//g(static_cast<int>(a)); // used with explicit conversion
	return 0;
}

