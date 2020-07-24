/*
Use of copy-and-swap idiom <=> assignment operator
Class must have a workable copy-constructor and a workable destructor 
A way of implementing the assignment operator in terms of a swap function
A move-constructor changes the ownership of some resource one object manages to another object
The old object's ownership is set to nullptr
OR, in other words:
The goal of move-construction is to take the resources from another instance of the class, 
leaving it in a state guaranteed to be assignable and destructible.
//std::move 
is a way of saying, "ok, honest to God I know I have an lvalue, but I want it to be an rvalue." std::move does not, in and of itself, move anything; it just turns an lvalue into an rvalue, so that you can invoke the move constructor.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class dumb_array
{
private:
	std::size_t mSize;
	int* mArray; // int array of size "mSize", just like char* is a character array
public:
	// constructor
	dumb_array(std::size_t size = 0) : 
		mSize(size),
		mArray(mSize ? new int[mSize] : nullptr)
	{};

	// copy constructor
	dumb_array (const dumb_array& other) :
	mSize(other.mSize)
	{
		if(mSize)
		{
			this->mArray = new int[mSize];
			// copy elements from other.myArray to this->mArray
			// std::copy(InputArray first, InputArray last, destinationArray)
			std::copy(other.mArray, other.mArray + mSize, this->mArray);
		}
		else
		{
			this->mArray = nullptr;
		}
	}
	
	// copy asignment
	dumb_array& operator=(const dumb_array& other)
	{
		mSize = other.mSize;
		//mArray(mSize ? new int[mSize] : nullptr)
		if(mSize)
		{
			this->mArray = new int[mSize];
			std::copy(other.mArray, other.mArray + mSize, this->mArray);
		}
		else
		{
			this->mArray = nullptr;
		}
		return *this;	
	}

	// move constructor
	dumb_array (dumb_array&& other) noexcept 
	{
		// && an rvalue reference, & is an lvalue reference
		swap(*this, other);
		
	}

	// assignment operator
	dumb_array& operator=(dumb_array other)
	{
		swap(*this, other);
		return *this;

		// the parameter "other" is taken by-value
		// which invokes copy-constructor
		// "other" is a local copy of the argument in the caller

		// *this will swap data with "other"
		// destructor will be invoked upon leaving the function boday
		// as a result of which, "other" object will de destroied
	}

	// destructor
	virtual ~dumb_array()
	{
		delete [] mArray;
	}

	friend void swap(dumb_array& first, dumb_array& second)
	{
		// by swapping the member data of two objects
		// the two objetcs are effectively swapped
		std::swap(first.mSize, second.mSize);
		std::swap(first.mArray, second.mArray);
	}
};

/*
decltype and auto in C++14 show type of auto by typeid().name()
template function with its parameter accepting rvalue & lvalue 
usig universal reference, &&
*/
using namespace std;

template<typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c, Index i)
{
	return std::forward<Container>(c)[i];
}

template<class T>
decltype(auto) makeAvector()
{
	vector<T> v = {1, 2, 3};
	return v;
}

int main(int argc, char* argv[])
{
	vector<int> v = makeAvector<int>();
	for(auto i = 0; i < v.size(); i++)
	{
		cout << authAndAccess(v, i) << endl;
	}

	const int  theAnswer = 42;
	auto x = theAnswer;  //decltype(x) => int
	auto y = &theAnswer; //decltype(y) => const int* (PKi)

	cout << typeid(x).name() << "\n";
	cout << typeid(y).name() << "\n";

    return 0;
}

class SimpleCat
{
public:
    SimpleCat(int age) : itsAge(age) {};

	SimpleCat(const SimpleCat& ) = default;
	SimpleCat& operator=(const SimpleCat&) = default;

	SimpleCat(SimpleCat&&) = default;
	SimpleCat& operator=(SimpleCat&&) = default;

    ~SimpleCat() = default;
	//virtual ~SimpleCat() = default; // this is wrong

    int GetAge() const { return itsAge; }
private:
    int itsAge;
};
  
decltype(auto) makeAcat() // return rvalue
//SimpleCat makeAcat()
{
    SimpleCat Frisky(30);
	// compiler knows when to use move/copy assignment
	// std::move(Frisky); explicitly force compiler to use move assignment
    return Frisky;
}

// accepting lvalue & rvalue reference only when templated
template<class T>
void printOut(T&& aCat)
{
	// std::forward<T> must be used to deal with rvalue reference
	// it does nothing with lvalue reference
	auto age = std::forward<T>(aCat).GetAge();
	std::cout << "aCat is " << age << " years old!\n";
}
  
int main()
{
	SimpleCat aCat(5); // aCat lvalue
	printOut(aCat);
	// change "aCat" to a rvalue when "printOut" function NOT templated
	//printOut(std::move(aCat)); 
	printOut(makeAcat());
    return 0;
}

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

