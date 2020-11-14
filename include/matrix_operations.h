#pragma once
#include "vector_operations.h"
#include <cassert>
#include <vector>

namespace matrix_operations
{
	// Inplace operations
	std::vector<std::vector<double>> matrix_transpose(std::vector<std::vector<double>> A);

	// Group operations
	std::vector<std::vector<double>> scale_matrix(const std::vector<std::vector<double>>& A, const double a);
	std::vector<std::vector<double>> matrix_addition(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);
	std::vector<std::vector<double>> matrix_subtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);
	std::vector<std::vector<double>> matrix_multiplication(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>> B);
	
	// Inverses
	std::vector<std::vector<double>> matrix_invert_2x2(std::vector<std::vector<double>> A);

	// Additional operations
	std::vector<double> vector_matrix_product(std::vector<double> v, std::vector<std::vector<double>> A);
	std::vector<double> matrix_vector_product(std::vector<std::vector<double>> A, std::vector<double> v);
}
