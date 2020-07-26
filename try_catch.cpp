#include <fstream>
#include <exception>
#include <stdexcept>
#include <iostream>
/*try
{
	// do somethig
}
catch (const std::exception & e)
{
	std::cout << e.what() << "\n";
}
*/
using namespace std;

template<class T>
class Divison
{
private:
	T num, den;	
public:
	class ExceptClass
	{
		public:
		//void show() const;
		void show() const {cout << "divided by zero\n";}
	};

	//Divison(T, T);
	Divison(T a, T b) : num(a), den(b)
	{
		if(den == 0) throw ExceptClass();
	}	
};

//template<class T>
//Divison<T>::Divison(T a, T b)
//{
//	num = a; den = b;
//	if (b == 0) throw ExceptClass();
//}

//template<class T>
//void Divison<T>::ExceptClass::show() const
//{
//	cout << "divided by zero\n";
//};

int main()
{
	try
	{
		int a = 10, b = 0;
		Divison<int> division(a, b);
	}
	//catch (const std::exception& except)
	//{
	//	except.what();
	//}
	catch(const Divison<int>::ExceptClass& except)
	{
		except.show();
		exit(1);
	}

	return 0;
}
