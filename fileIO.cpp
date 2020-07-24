/*
decltype and auto in C++14 
show type of auto by typeid().name()
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	std::ifstream in_stream;
	std::ifstream fileExist("input.txt");
	if(fileExist) in_stream.open("input.txt");
	else
	{
		std::cerr << "file not exist, exit\n";
		exit(1);
	}
	std::string str, name;
	int varNumber;
	while(std::getline(in_stream, str))
	{
		std::getline(in_stream, str);
		std::getline(in_stream, str);
		varNumber = std::atoi(str.c_str());
		cout << "varNumber = " << varNumber << "\n";

		std::getline(in_stream, str);
		std::getline(in_stream, name);
		cout << "name = " << name << "\n";
	}
	in_stream.close();

	std::ofstream out_stream;
	out_stream.open("output.txt", std::ofstream::out);
	out_stream << "output data\n";
	out_stream << "name \n";
	out_stream << name << "\n";
	out_stream << "number \n" ;
	out_stream << varNumber << "\n";
	out_stream.close();
	
	cout << "***************************\n";
	in_stream.open("output.txt");

	while(std::getline(in_stream, str))
	{
		std::getline(in_stream, str);
		std::getline(in_stream, name);
		cout << "name = " << name << "\n";

		std::getline(in_stream, str);
		std::getline(in_stream, str);
		varNumber = std::atoi(str.c_str());
		cout << "varNumber = " << varNumber << "\n";
	}
	in_stream.close();
	
    return 0;
}

