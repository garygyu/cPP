#include <iostream>
#include <vector>
using namespace std;

// must be passed by reference to change the arrays in caller
template<class T, std::size_t N>
void swap_local (T (&a)[N], T (&b)[N])
{
	T* aPtr = a;
	T* bPtr = b;
	for (auto i : a)
		std::swap(*aPtr++, *bPtr++);

}

// again must be passed by reference
// T can be e.g. std::vector<int>
template<class T>
void swap_local(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main ()
{
	/*int a[] = {1, 2, 3};
	int b[] = {7, 8, 9};

	int* ptr = a;
	for(auto i : a)
		cout << *ptr++ << " ";
	cout << "\n";

	ptr = b;
	for(auto i : b)
		cout << *ptr++ << " ";
	cout << "\n";

	swap_local(a, b);
	cout << "after swap\n";
	ptr = a;
	for(auto i : a)
		cout << *ptr++ << " ";
	cout << "\n";

	ptr = b;
	for(auto i : b)
		cout << *ptr++ << " ";
	cout << "\n";*/

	std::vector<int> a{1, 2, 3};
	std::vector<int> b{7, 8, 9};

	std::vector<int>::const_iterator it = a.begin();
	for(; it != a.end(); it++)
		cout << *it << " ";
	cout << "\n";

	for(auto i : b)
		cout << i << " ";
	cout << "\n";

	swap_local(a, b);

	for(it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << "\n";

	for(auto i : b)
		cout << i << " ";
	cout << "\n";

	return 0;
}

