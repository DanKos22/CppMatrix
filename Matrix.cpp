/*
	`...
 `..   `..     `..        `..
`..            `..        `..
`..       `... `.....`... `.....
`..            `..        `..
 `..   `..     `..        `..
   `....

Michelle Lynch
*/

#include <iostream>   // cout
#include <string>	  // string
#include <vector>     // vector
#include <iterator>   // iterator, const_iterator
#include "Matrix.h"   // Matrix
#include <stdexcept>  // out_of_range
	
	// Initialise the static data member
	int Matrix::matrixCount = 0;

	// Define the static member getter function
	int Matrix::GetMatrixCount() 
	{ 
		return matrixCount;
	}

	// Default constructor
	Matrix::Matrix() : rows{ 0 }, cols{ 0 }
	{
#if VERBOSE
		std::cout << "Executing Matrix default constructor" << std::endl;
#endif
		matrixCount++;	
	}

	// Constructor, matrix default initialised to zeros
	Matrix::Matrix(int r, int c) : rows{ r }, cols{ c }
	{
#if VERBOSE
		std::cout << "Executing Matrix 2-argument constructor with rows & cols" << std::endl;
#endif
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i)
			i->resize(c);									//pointer, so we use an arrow
		
		matrixCount++;
	}

	/*trix::Matrix(int r, int c, double val) {

#if VERBOSE
		std::cout << "Executing Matrix 3-argument constructor" << std::endl;
#endif
		rows = r;
		cols = c;
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i) {
			i->resize(c, val);
		}
		matrixCount++;

	}*/

	//Copy constructor
	Matrix::Matrix(const Matrix& rhs) : rows {rhs.rows}, cols{rhs.cols}, mat{rhs.mat}
	{
#if VERBOSE
		std::cout << "Executing copy constructor" << std::endl;
#endif
		matrixCount++;
	}
	// Destructor
	Matrix::~Matrix() 
	{
#if VERBOSE
		std::cout << "Executing Matrix destructor" << std::endl;
#endif
		matrixCount--;
	}

	//Copy assignment operator overload
	Matrix& Matrix::operator=(const Matrix& rhs) {		//rhs right-hand side
		//Checking for self-assigment
		if (&rhs == this)
			return *this;	//return LHS

		//Copying the number rows and cols
		rows = rhs.GetRows();
		cols = rhs.GetCols();
		mat.resize(rows);
		//mat.resize(r);
		for (auto r = mat.begin(); r != mat.end(); ++r)
			r->resize(cols);	

		for (auto i = 0; i < rows; ++i)						//++i is more effective, extra copy is not made, ++i is a pre-increment operator. Do pre-increment 
			for (auto j = 0; j < cols; ++j)
				mat[i][j] = rhs.GetElement(i, j);

		return *this;				//return LHS (current object)

		matrixCount++;
	}

	Matrix::Matrix(int r, int c, double val) : rows{ r }, cols{ c } {
#if VERBOSE
		std::cout << "Executing Matrix 3-argument constructor with rows & cols" << std::endl;
#endif
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i)
			i->resize(c, val);									//pointer, so we use an arrow

		matrixCount++;

	}

	//Operator + overload
	Matrix Matrix::operator+(const Matrix& rhs) {
		Matrix result(rows, cols);

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				double temp = mat[i][j] + rhs.GetElement(i, j);
				result.mat[i][j] = temp;
			}
			return result;
		}
	}

	// Get the number of rows of the matrix
	int Matrix::GetRows() const
	{
		return rows;
	}

	// Get the number of columns of the matrix
	int Matrix::GetCols() const 

	//uble Matrix::GetElement(int i, int j) const
	{
		return cols;
	}

	double Matrix::GetElement(int i, int j) const {

		if (i > rows - 1 || j > cols - 1)
			throw std::out_of_range("Index out of range in Get Element()\n");

		return mat[i][j];
	}


	std::ostream& operator<<(std::ostream& output, const Matrix& mx) {

		for (const auto& row : mx.mat) {
			for (const auto& element : row)
				output << element << ' ';
			output << std::endl;
		}
		return output;

	}