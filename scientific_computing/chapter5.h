#pragma once
#include <linear_algebra/couts.h>
#include <linear_algebra/norms.h>
#include <linear_algebra/matrices.h>
#include <linear_algebra/vector_spaces.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

struct Chapter5Elements 
{
	std::vector<double> scalar_examples = {
		12.0, 5.0, 2020.0
	};

	std::vector<std::vector<double>> vector_examples = {
		{ 12.0, 5.0, 2020.0 },
		{ 1.0, 1.0, 3.0 }, //b in Ly = b
		{-11, 13.0/3.0, -1.0/5.0}, //y in Ux = y
		{ 1.0, 5.0, 5.0 }, // b in Ax = b
	};

	double mu = 0.0;
	double sigma = 0.0;

	std::vector<std::vector<std::vector<double>>> square_matrix_examples =
	{
		{{1,5,0}, {7,1,2}, {0,0,1}},
		{{-2,0,1}, {1,0,0}, {4,1,0}},
		{{1,3,3}, {12,6,9}, {-1,-3,3}}, // A in Ax = b
	};

	std::vector<std::vector<std::vector<double>>> triangular_matrix_examples =
	{
		{{1,0,0}, {2,1,0}, {3,2,1}}, //L in Ly = b
		{{-3,-1,2}, {0,5.0/3.0,2.0/3.0}, {0,0,1.0/5.0}}, //U in Ux = y
	};


};


//Exercise 5.1
void cout_value_from_address(double& a);
//Exercise 5.2
void change_value_from_address(double& a);
//Exercise 5.3
void swap_via_passed_pointers(double* x1, double* x2);
void swap_via_passed_references(double& r_x1, double& r_x2);
//Exercise 5.4
void calculate_mean_median(std::vector<double> v, double& mean, double& standard_deviation);

void chapter5_couts();