#include "vector_operations.h"

// Inplace vector operations
double vector_operations::inner_product(std::vector<double> v1, std::vector<double> v2)
{
	assert(v1.size() == v2.size());
	double result = v1[0] * v2[0];
	for (size_t i = 1; i < v1.size(); i++)
	{
		result += v1[i] * v2[i];
	}
	return result;
}

double vector_operations::vector_sum(std::vector<double> v)
{
	double result = v[0];
	for (size_t i = 1; i < v.size(); i++)
	{
		result += v[i];
	}
	return result;
}

double vector_operations::vector_avg(std::vector<double> v)
{
	assert(v.size() > 0);
	double sum = vector_sum(v);
	return sum / v.size();
}

// Group operations

std::vector<double> vector_operations::vector_addition(std::vector<double> v1, std::vector<double> v2)
{
	assert(v1.size() == v2.size());
	std::vector<double> v(v1.size());

	for (size_t i = 0; i < v1.size(); i++)
	{
		v[i] = v1[i] + v2[i];
	}
	return v;
}

std::vector<double> vector_operations::vector_subtraction(std::vector<double> v1, std::vector<double> v2)
{
	assert(v1.size() == v2.size());
	std::vector<double> v(v1.size());

	for (size_t i = 0; i < v1.size(); i++)
	{
		v[i] = v1[i] - v2[i];
	}
	return v;
}

std::vector<double> vector_operations::scale_vector(std::vector<double> v, double a)
{
	if (a == 0)
	{
		std::vector<double> result(v.size(), 0.0);
		return result;
	}
	else
	{
		std::vector<double> result;
		for (size_t i = 0; i < v.size(); i++)
		{
			result.push_back(v[i] * a);
		}
		return result;
	}
}