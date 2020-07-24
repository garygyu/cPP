/*
Use of copy-and-swap idiom <=> assignment operator
Class must have a workable copy-constructor and a workable destructor 
A way of implementing the assignment operator in terms of a swap function
A move-constructor changes the ownership of some resource one object manages to another object
The old object's ownership is set to nullptr
OR, in other words:
The goal of move-construction is to take the resources from another instance of the class, 
leaving it in a state guaranteed to be assignable and destructible.
std::move 
is a way of saying, "ok, honest to God I know I have an lvalue, but I want it to be an rvalue." std::move does not, in and of itself, move anything; it just turns an lvalue into an rvalue, so that you can invoke the move constructor.
*/
#include <iostream>
#include <algorithm>
template<typename T>
class unique_ptr
{
	T* ptr;
public:
	explicit unique_ptr(T* p = nullptr) : ptr(p)
	{
		std::cout << "unique_ptr constructor called \n";
		if(ptr != nullptr) ptr->count++;
	};
	unique_ptr(const unique_ptr& p)
	{
		std::cout << "unique_ptr copy constructor called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		ptr->count++;
	}
	unique_ptr(unique_ptr&& p)
	{
		std::cout << "unique_ptr move constructor called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		p.ptr = nullptr;
	}
	unique_ptr& operator =(const unique_ptr& p)
	{
		std::cout << "unique_ptr assignment operator called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		ptr->count++;
		return *this;
	}
	unique_ptr& operator= (unique_ptr&& p)
	{
		std::cout << "unique_ptr move assignment operator called \n";
		if(ptr != nullptr) ptr->count--;
		ptr = p.ptr;
		p.ptr = nullptr;
		return *this;
	}
	virtual ~unique_ptr() {if(ptr->count == 1) delete ptr;}
//	T* operator->() const {return ptr;}
//	T& operator*() const {return *ptr;}
};
