#include "example_functions.h"

double PolynomialExamples::function_result(size_t g, double x)
{
	return function_vector[g](x);
}

std::vector<double> PolynomialExamples::function_results (double x)
{
	std::vector<double> out(function_vector.size());
	for (size_t g = 0; g < function_vector.size(); g++)
	{
		out[g] = function_vector[g](x);
	}
	return out;
}

std::vector<double(*)(double)> NewtonRaphsonExamples::function_pair_result(size_t g)
{
	return function_vector_pairs[g];
}