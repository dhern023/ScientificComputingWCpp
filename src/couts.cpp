#include "couts.h"

void couts::cout_vector(std::vector<double> v)
{
	std::cout << "{";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ",";
	}
	std::cout << "}" << std::endl;
}

void couts::cout_matrix(std::vector<std::vector<double>> A)
{
	std::cout << "{";
	for (size_t i = 0; i < A.size(); i++)
	{
		std::cout << "{";
		for (size_t j = 0; j < A[0].size(); j++)
		{
			std::cout << A[i][j] << ",";
		}

		if (i == A.size() - 1)
		{
			std::cout << "}" << std::endl;
		}
		else
		{
			std::cout << "}, " << std::endl;
		}
	}
}