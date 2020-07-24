/*
Use of std::move()
template <class T>
constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept;

change an lvale reference to an rvalue reference
after 'std::move(a)' is executed, compiler regards 'a' is disposable
therefore 'a' CAN Not be used after that point
*/
#include <iostream>
template <typename T>
class A
{
public:
	// Constructors
	A() {};

	explicit constexpr A(T t) noexcept : member(t) {
		std::cout << "One-argument ctor invoked" << std::endl;
	};

	// Copy constructor
	A(const A& arg) : member(arg.member) {
		std::cout << "Copy ctor invoked" << std::endl;
	}; // since 'const A&' is a lvalue reference, 'arg' can be passed by rvalue argument

	// Copy assignment
	A& operator = (const A& arg)
	{
		std::cout << "Copy assignment invoked" << std::endl;
		member = arg.member;
		return *this;
	}

	// Move constructor
	A(A&& arg) {
		std::cout << "Move ctor invoked" << std::endl;
		std::swap(member, arg.member);
	};

	// Move assignment
	A& operator =(A&& arg)
	{
		std::cout << "Move assignment invoked" << std::endl;
		std::swap(member, arg.member);
		return *this;
	}

	T& getValue(){return member;}

private:
	T member;
};

int main()
{
	int v = 10;
	A<int> a(v);
	// Copy ctor
	A<int> a2(a);
	// Copy assigment
	A<int> a3;
	a3 = a2;
	//Move assignment, note a2 output
	A<int> a4;
	a4 = (std::move(a2));
	//Move ctor, note a3 output
	//A<int> a5(std::move(a2)); // unpredicted result since 'a2' is treated as rvalue, and not known
	A<int> a5(std::move(a3));
	return 0;
}




