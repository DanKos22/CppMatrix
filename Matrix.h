/*
	`...
 `..   `..     `..        `..
`..            `..        `..
`..       `... `.....`... `.....
`..            `..        `..
 `..   `..     `..        `..
   `....

Dan Koskiranta
*/

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>   // vector
#include <iostream> // ostream

#define VERBOSE 1

	class Matrix {
	public:
		Matrix();								
		Matrix(int, int);	
		Matrix(int, int, double);
		Matrix(const Matrix&);		//Copy constructor
		~Matrix();	
		Matrix& operator=(const Matrix&);			//returns a reference to something that exists already
		Matrix operator+(const Matrix&);
		int GetRows() const;					
		int GetCols() const;
		double GetElement(int, int) const;
		static int GetMatrixCount();	
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
	private:
		int rows;								
		int cols;								
		std::vector<std::vector<double>> mat;   
		static int matrixCount;				    
	};

#endif // MATRIX_H_INCLUDED
