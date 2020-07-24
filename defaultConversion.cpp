/*how conversion operator member function works
how one argument ctor converts argument type to class type*/
/*
#include <iostream>
#include <cmath>
using namespace std;
class My_Complex {
	private:
		double real, imag;
	public:
		My_Complex(double re = 0.0, double img = 0.0) : 
		real(re), imag(img) {};

		double mag() { //normal function to get magnitude
			return getMagnitude();
		}
		operator double () { //Conversion operator to get magnitude
			return getMagnitude();}

		//explicit operator int () { //Conversion operator to get magnitude
		//	return getMagnitude();

		//operator int () { //Conversion operator to get magnitude
		//	return int(getMagnitude());
		//}
	private:
		double getMagnitude() { //Find magnitude of complex object
			return sqrt(real * real + imag * imag);
		}
};
int main() {
	My_Complex complex(10.0, 6.0);
	cout << "Magnitude using normal function: " << complex.mag() << endl;
	cout << "Magnitude using conversion operator: " << static_cast<int>(complex) << endl;
	cout << "Magnitude using conversion operator: " << complex << endl;
	return 0;
}*/

#include <iostream>
struct B 
{ 
	int b_;
	B() = default;
	explicit B(int b) noexcept : b_(b) {}; 
    // one argument ctor can be used to convert parameter type to  class Type. 
	//i.e. in this case int -> B or vice verser
};
struct A {
  //operator B(): conversion to B type
  explicit operator B() { return B();} //B() default ctor of B called
};

inline void f(B){std::cout << "sucessfully called\n";}
int main() 
{ 
	//f(A()); // A() default ctor called to create A type object
			// f(B) requires the parameter type to be of B
			// conversion operator inside Class A invoked to convert A to B 
	f(static_cast<B>(A()));	
	auto b = 10;
	//f(b); // illegal! could not convert 'b' from 'int'->'B'
	f(static_cast<B>(b)); // one argument ctor called to convert int->B 
	return 0;
}

