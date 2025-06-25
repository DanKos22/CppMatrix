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

#include <iostream>       // cout, endl
#include "Matrix.h"		  // Matrix
#include "TestMatrix.h"   // Test functions
#include <stdexcept>      //out_of_range

void RunTests(int argc, char **argv)
{
	//TestDefaultCstr();
	TestOpAssign();
	//TestOpAddition();
}

void TestDefaultCstr()
{
	std::cout << "*****" << " Test default constructor " << " *****" << std::endl;

	Matrix m;
	//std::cout << "Matrix size is " << m.GetRows() << "x" << m.GetCols() << std::endl;
}

void TestOpAssign() {

	Matrix m1(2, 2, 1.1);
	Matrix m2(3, 3, 2.2);

	//Print out Matrix values here!!!
	std::cout << m1;
	std::cout << m2;

	//Get  << to work with MY class!! not just with ints/doubles/bools/etc 
	/*for (int i = 0; i < m1.GetRows(); ++i)
		for (int j = 0; j < m1.GetCols(); ++j)
			std::cout << m1.GetElement(i, j) << " ";
		std::cout << std::endl;*/

	m1 = m2;
	//std::cout << "Hello1";

	std::cout << m1;
	std::cout << m2;

	try {
		m1 = m2;
		//Force a throw
		m1.GetElement(20, 50);
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << m1 << std::endl;
}

void TestNotDefined()
{
	std::cout << "*****" << " Test not defined " << " *****" << std::endl;

}


void TestOpAddition() {
	Matrix m1(2, 2, 1.1);
	Matrix m2(3, 3, 2.2);

	std::cout << m1;
	std::cout << m2;
	std::cout << "Hello";

	std::cout << m1 + m2;
}
