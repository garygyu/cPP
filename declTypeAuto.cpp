/*
decltype and auto in C++14 show type of auto by typeid().name()
template function with its parameter accepting rvalue & lvalue 
usig universal reference, &&
*/


#include <iostream>
#include <vector>

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

