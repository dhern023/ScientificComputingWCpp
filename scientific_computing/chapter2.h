#pragma once

#include "example_functions.h"

#include <linear_algebra/couts.h>
#include <linear_algebra/vector_spaces.h>
#include <numerical_solvers/single_variable_non_linear_solvers.h>
#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>

struct ChapterTwoElements
{
	std::vector<std::string> prompts = {
		"If-Then Inequality",
		"If-Then Inequality (2)",
		"v1 - v2",
		"matrix * vector",
		"matrix * vector - vector",
		"difference of scaled matrices",
		"addition of scaled negative matrix (same result)",
		"matrix * matrix",
		"2x2 inverse",
		"Newton's method converges",
		"Newton's method won't converge"
	};
	
	//Exercise 2.1
	std::vector<std::vector<double>> v_examples = {
		{10.0, -1.0}, {10.0, 20.0}, {0.0, 20.0}
	};


	//Exercise 2.4
	std::vector<std::vector<double>> v_examples2 = {
		{1,2,3}, {6,5,4}
	};

	//Exercise 2.4 and 2.5
	std::vector<std::vector<std::vector<double>>> m_examples = {
		{ {1, 5, 0}, { 7,1,2 }, { 0,0,1 } },
		{ {-2,0,1}, {1,0,0}, {4,1,0} },
		{ {4,10}, {1,1} }
	};
};

//Exercise 2.2
struct sChapter2BaseArgs
{
	int j;
	double d1, d2, d3;
	std::vector<bool> vBool;
	sChapter2BaseArgs(int J, double D1, double D2, double D3, std::vector<bool> VBool) :
		j(J), d1(D1), d2(D2), d3(D3), vBool(VBool) {}
};

void inequality1(double x, double y);
void inequality2(int j, double p, double q, double y, std::vector<bool> vBool);

void chapter2_couts();