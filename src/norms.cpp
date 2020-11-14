#include "norms.h"

double norms::two_norm(std::vector<double> v1, std::vector<double> v2)
{
	assert(v1.size() == v2.size());
	double inner_product_result = vector_operations::inner_product(v1, v2);
	assert(inner_product_result >= 0);
	return std::sqrt(inner_product_result);
}