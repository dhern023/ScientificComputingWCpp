#pragma once

#include <linear_algebra/couts.h>
#include <linear_algebra/norms.h>
#include <linear_algebra/vector_spaces.h>
#include <vector>
#include <iostream>

struct ChapterOneElements 
{
	std::vector<std::string> prompts = 
	{
		"Multiplying two numbers",
		"Inner product of two vectors",
		"Two norm of two vectors",
		"Matrix addition",
		"Matrix transpose",
		"Matrix multiplication",
		"Vector average",
		"2x2 inverse"
	};

	std::vector<std::vector<double>> multiply_pairs = 
	{
		{0,1}, {1,0}, {2, 1}, {1, 2}, {14, 14}, {90, 12}, {100, 100}
	};

	std::vector<std::vector<double>> vector_examples = {
		{-1, 0, 1, 0, 2}, {34, 58, 57, 32, 43}
	};

	std::vector<std::vector<double>> A = {
		{1,2,3}, {4,5,6}, {7,8,9}
	};
};

// Exercise 1.2
double multiply_two_numbers(double x1, double x2);

void chapter1_couts();