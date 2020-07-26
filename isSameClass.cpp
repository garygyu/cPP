#include <iostream>
#include <typeinfo>

using namespace std;

template<class A, class B>
bool IsSameClass()
{
	//return typeid(A).name() == typeid(B).name() ? true : false;
	return typeid(A) == typeid(B);
}

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

struct A{};

struct B{};

int main()
{
	//if (IsSameClass<A, B>())
	A a; B b;
	if (isA<A>(a)) cout << "same class \n";
	else cout << "not the same calss \n";
}

