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

#include <iostream>		// cerr
#include <stdexcept>	// out_of_range
#include "Matrix.h"     // Matrix
#include "TestMatrix.h"	// Test Functions

int main(int argc, char** argv)
{
	try {
		RunTests(argc, argv);
	}

	catch (std::out_of_range& e) {
		std::cerr << std::endl <<  e.what() << std::endl;
		return -1;
	}

	return 0;
}
