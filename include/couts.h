#pragma once
#include <vector>

void cout_vector(std::vector<double> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void cout_matrix(std::vector<std::vector<double>> A)
{
	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = 0; j < A[0].size(); j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
}