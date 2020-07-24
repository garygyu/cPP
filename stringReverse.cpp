#include <iostream>
#include "string.h" //for C-string
#include <string> // string class
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	std::string str = "Hello, World!";
	std::cout << "str= " << str << "\n";
	
	for(std::string::const_iterator it=
		str.begin(); it != str.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << "\n";
	
	//std::string revStr(str.rbegin(), str.rend());
	std::string revStr;
	//std::copy(str.rbegin(), str.rend(), std::back_inserter(revStr));
	//std::reverse_iterator<std::string::iterator> rit;
	for(std::string::reverse_iterator rit=
		str.rbegin(); rit != str.rend(); ++rit)
	{
		revStr.push_back(*rit);
		//revStr+=*rit;
	}
	std::cout << "revStr= " << revStr << "\n";

	return 0;
}
