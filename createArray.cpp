#include <iostream>
#include <vector>
#include <array>
using namespace std;
/*
template <class T, int rows, int cols>
class Matrix
{
private:
	std::vector<std::vector<T>> matrix;
	
public:
	Matrix();
	// vector.at() check bounds, operator[] does not
	std::vector<T>& operator[](int i) {return matrix.at(i);}
	//const std::vector<T>& operator[](int i) const {return matrix[i];}
};

template<class T, int rows, int cols>
Matrix<T, rows, cols>::Matrix()
{
	matrix = 
	std::vector<std::vector<T>>(rows, std::vector<T>(cols));

	for(auto& i : matrix)
	{
		for(auto& j : i) 
		{
			j = static_cast<T>(0);
		}
	}
}*/
/*
template <class T, int rows, int cols>
class Matrix
{
private:
	std::vector<T>* matrix;
	
public:
	Matrix();
	~Matrix(){delete [] matrix;}
	std::vector<T>& operator[](int i) {return matrix[i];}
};

template<class T, int rows, int cols>
Matrix<T, rows, cols>::Matrix()
{
	matrix = new std::vector<T>[rows];
	for(auto i=0; i<rows; i++)
	{
		for(auto j=0; j<cols; j++)
		{
			matrix[i].push_back(0);
		} 
	}
}
*/

template <class T, int rows, int cols>
class Matrix
{
private:
	std::array<std::vector<T>, rows> matrix;
	
public:
	Matrix();
	std::vector<T>& operator[](int i) {return matrix.at(i);}
};

template<class T, int rows, int cols>
Matrix<T, rows, cols>::Matrix()
{
	for(auto i=0; i<rows; i++)
	{
		for(auto j=0; j<cols; j++)
		{
			matrix[i].push_back(0);
		} 
	}
}

int main()
{
	const int rows = 4;
	const int cols = 4;

	Matrix<int, rows, cols> matrix;
	
	/*for(auto i=0; i <rows; i++)
	{	
		for(auto j=0; j<cols; j++)
		{
			cout << "input data\n";
			cin >> matrix[i][j];
		}
	}*/
	
	cout << "\n";
	for(auto i=0; i <rows; i++)
	{	
		for(auto j=0; j<cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}

	/*
	for(auto& i : matrix)
	{
		for(auto& j : i)
		{
			//cout << "input data\n";
			//cin >> j;
			j = 0;
		}
	}

	for(const auto& i : matrix)
	{
		for(const auto& j : i)
		{
			cout << j << "\t";
		}
		cout << "\n";	
	}*/

	return 0;
}
