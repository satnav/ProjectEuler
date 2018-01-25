/// Problem 15
/// Given a 20x20 grid, how many paths are there from the top left corner to the
/// bottom right corner only going right and down?

#include <iostream>
#include "AutoTimer.h"

int main(int argc, char** argv)
{
	AutoTimer timer;
	
	// This is a permutations problem
	// There are 20 right directions and 20 down directions that each path will use
	// The goal is to find all permutations of these directions

	// Assume that each right and down direction is unique, then there is a
	// total of 40 directions. We can order these in 40! different ways.

	// However because all right directions are the same and all down directions
	// are the same, we must divide by 20! twice.

	// Thus the final calculation is: 40! / (20! * 20!) = 137846528820
	
	std::cout << "There are 137846528820 different paths." << std::endl;
	
	return 0;
}
