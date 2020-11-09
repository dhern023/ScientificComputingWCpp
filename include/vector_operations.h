#pragma once
#include <cassert>
#include <vector>

namespace vector_operations
{
	//inplace vector operations
	double inner_product(const std::vector<double>& v1, const std::vector<double>& v2);
	double vector_sum(std::vector<double> v); //sum of vector elements
	double vector_avg(std::vector<double> v); //arithmetic mean of vector elements

	// Group operations
	std::vector<double> vector_addition(std::vector<double> v1, std::vector<double> v2); //point-wise vector addition
	std::vector<double> vector_subtraction(std::vector<double> v1, std::vector<double> v2); //point-wise vector subtraction
	std::vector<double> scale_vector(const std::vector<double>& v, const double& a); //point-wise vector scaling
}