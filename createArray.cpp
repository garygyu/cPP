#include <iostream>
#include <vector>
#include <array>
using namespace std;

template <class T>
class Matrix
{
private:
	int rows_, cols_;
	std::vector<std::vector<T>> matrix;
	
public:
	Matrix(int, int);
	// vector.at() check bounds, operator[] does not
	std::vector<T>& operator[](int i) {return matrix.at(i);}
	//const std::vector<T>& operator[](int i) const {return matrix[i];}
};

template<class T>
Matrix<T>::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
	matrix = 
	std::vector<std::vector<T>>(rows_, std::vector<T>(cols_));

	for(auto& i : matrix)
	{
		for(auto& j : i) 
		{
			j = static_cast<T>(0);
		}
	}
}
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

/*template <class T, int rows, int cols>
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
}*/

int main()
{
	int rows = 3;
	int cols = 3;

	Matrix<int> matrix(rows, cols);
	
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
