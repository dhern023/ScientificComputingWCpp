#pragma once
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

struct Chapter5Elements 
{
	std::vector<double> v1 = {
		12.0, 5.0, 2020.0
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
//Exercise 4.5
