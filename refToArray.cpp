/*
Regerence to array
*/


#include <iostream>
#include <vector>
#include <algorithm>

template<class T, std::size_t N>
constexpr void swap_local(T (&a)[N], T (&b)[N]) noexcept(noexcept(std::swap(*a, *b)))
{
	// array name, 'a' & 'b', is a pointer to first element
	// *a, *b retruns the value of the first element

	T* aPtr = a;
	T* bPtr = b;
	
	for(auto i : a)
	{
//		T temp = *aPtr;
//		*aPtr++ = *bPtr;
//		*bPtr++ = temp;
		std::swap(*aPtr++, *bPtr++);
	}
}

template<class T>
constexpr  void swap_local(T& a, T& b) noexcept
{
	T temp = a;
	a = b;
	b = temp;
	//std::swap(a,b);
}


int main(int argc, char* argv[])
{
	int A[] = {1, 2, 3};
	int B[] = {7, 8, 9};

	for(auto i : A)
	{
		for(auto j : B)
		{
			std::cout << i << "\t" << j << std::endl;
		}
	}

//	std::cout << "****" << std::endl;

	swap_local(A, B);
//	std::swap(A, B);

	for(auto i : A)
	{
		for(auto j : B)
		{
			std::cout << i << "\t" << j << std::endl;
		}
	}

	std::vector<int> vi1{11, 12, 13};
	std::vector<int> vi2{17, 18, 19};
	
	swap_local(vi1, vi2);
	std::vector<int>::const_iterator it;
	it = vi1.begin();
	for(; it != vi1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	it = vi2.begin();
	for(; it != vi2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	
	
    return 0;
}

