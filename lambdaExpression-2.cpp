/*
Practise use of lambda expression
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void add(const int x, std::vector<int>& v)
{
	std::transform(v.begin(), v.end(), 
				v.begin(), [x](auto& y) {return (y + x);});

/********************************************************
[] () mutable -> T {}

[]: capturing list, capturing local variables used inside lambda function body
(): parameter list, passed variabls to lambda function body
{}: function boday, where code is executed and returned
-> T: specifying function body return type T 
mutable: allowing inside function boday to mutate the variable values that have been
captured by value

[& x] capture "x" by reference;
[&]   capture all local variables be reference
[x]   capture "x" by value
[=]   capture all local variables by value
[&, x]  capture all varaibles except "x" by reference, "x" is captured by value
[=, &x] capture all variables except "x" by value, "x" is captured by reference

(auto y)  pass parameter "y" by value
(auto& y) pass parameter "y" by reference

********************************************************/

}

void display(std::vector<int>& v)
{
	std::for_each(v.begin(), v.end(), [](auto x) {std::cout << x << "\n";});
}


int main(int argc, char* argv[])
{
	int x = 3;
	std::vector<int> v = {1, 2, 3, 4};
	display(v);
	std::cout << "*\n";
	add(x, v);
	display(v);

	//std::function<bool (int, int)> f =
	//						[](int x, int y) -> bool {return (x > y) ? true : false;};

	
	int n1 = 4;
	int n2 = 3;

	decltype(auto) f = [](const auto& x, const auto& y) {return (x > y) ? true : false;};
	std::cout << n1 << " > " << n2 << " is " << f(n1, n2) << "\n";
	
    return 0;
}

