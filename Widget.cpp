// std::unique_ptr & Pointer to Implementation Idiom (Pimpl)
// complie by 
// g++ *.cpp -std=c++14

#include <string>
#include <vector>
#include "Widget.h"

// forward declaration
//class Gadget;

struct Widget::Impl{
	std::string name;
	std::vector<double> data;
//	Gadget g1, g2, g3;
};

Widget::Widget()
	: pImpl(std::make_unique<Impl>())
{}

Widget::~Widget() = default;

Widget::Widget(Widget&& rhs) noexcept = default;

Widget& Widget::operator=(Widget&& rhs) noexcept = default;

Widget::Widget(const Widget& rhs) : pImpl(nullptr){
	if (rhs.pImpl) pImpl = std::make_unique<Impl>(*rhs.pImpl);
}

Widget& Widget::operator=(const Widget& rhs){
	if(!rhs.pImpl) pImpl.reset();
	else if (!pImpl) pImpl = std::make_unique<Impl>(*rhs.pImpl);
	else *pImpl = *rhs.pImpl;
	
	return *this;
}

int main(){
	Widget w;
	return 0;
}
