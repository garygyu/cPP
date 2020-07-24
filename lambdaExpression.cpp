/*
Practise use of lambda expression
*/


#include <iostream>
#include <vector>
#include <algorithm>

namespace ns
{
	struct f
	{//fuction object only has one operator()
		void operator()(int x)
		{
			std::cout << x << "\n";
		}
	};
}

void func(std::vector<int>& v)
{
	ns::f f;
	std::for_each(v.begin(), v.end(), f);
}


void func2(std::vector<int>& v)
{
	std::for_each(v.begin(), v.end(), [](auto x){std::cout << x << "\n";});
}

int main(int argc, char* argv[])
{
	std::vector<int> v = {1, 2, 3};

	for(auto i = 0; i < 3; i++)
	{
		ns::f()(v[i]);//f() creates an f object; function object(v[i])
	}
	std::cout << "***" << "\n";

	func(v);
	std::cout << "***" << "\n";

	func2(v);
	// "func2" uses lambda expression to repalce what is in "func" and "struct f"

    return 0;
}

