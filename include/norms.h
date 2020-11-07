#pragma once
double inner_product(const std::vector<double>& v1, const std::vector<double>& v2)
{
	assert(v1.size() == v2.size());
	double result = v1[0] * v2[0];
	for (size_t i = 1; i < v1.size(); i++)
	{
		result += v1[i] * v2[i];
	}
	return result;
}

double two_norm(std::vector<double> v1, std::vector<double> v2)
{
	assert(v1.size() == v2.size());
	double inner_product_result = inner_product(v1, v2);
	assert(inner_product_result >= 0);
	return std::sqrt(inner_product_result);
}

