#include "matrix_operations.h"

std::vector<std::vector<double>> matrix_operations::matrix_transpose(std::vector<std::vector<double>> A)
{
	std::vector<std::vector<double>> A_T(A[0].size(), std::vector<double>(A.size()));
	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = 0; j < A[0].size(); j++)
		{
			A_T[i][j] = A[j][i];
		}
	}
	return A_T;
}

//Group operations
std::vector<std::vector<double>> matrix_operations::scale_matrix(const std::vector<std::vector<double>>& A, const double a)
{
	std::vector<std::vector<double>> B;
	for (size_t i = 0; i < A.size(); i++)
	{
		B.push_back(scale_vector(A[i], a));
	}
	return B;
}

std::vector<std::vector<double>> matrix_operations::matrix_addition(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B)
{
	assert(A.size() == B.size());
	assert(A[0].size() == B[0].size());

	std::vector<std::vector<double>> C(A.size());

	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = 0; j < A[i].size(); j++)
		{
			C[i].push_back(A[i][j] + B[i][j]);
		}
	}
	return C;
}

std::vector<std::vector<double>> matrix_operations::matrix_subtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B)
{
	assert(A.size() == B.size());
	assert(A[0].size() == B[0].size());

	std::vector<std::vector<double>> C(A.size());

	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = 0; j < A[i].size(); j++)
		{
			C[i].push_back(A[i][j] - B[i][j]);
		}
	}
	return C;
}

std::vector<std::vector<double>> matrix_operations::matrix_multiplication(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>> B)
{
	assert(A[0].size() == B.size());

	std::vector<std::vector<double>> B_T = matrix_transpose(B);

	std::vector<std::vector<double>> C(A.size(), std::vector<double>(B[0].size()));
	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t j = 0; j < B_T.size(); j++)
		{
			C[i][j] = inner_product(A[i], B_T[j]);
		}
	}
	return C;
}

//Inverses

std::vector<std::vector<double>> matrix_operations::matrix_invert_2x2(std::vector<std::vector<double>> A)
{
	assert(A.size() == 2 && A[0].size() == 2); //must be 2x2
	double denominator = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	assert(denominator != 0); //avoid indefinite

	std::vector<std::vector<double>> inverse = A;
	inverse[0][0] = A[1][1];
	inverse[0][1] = -A[0][1];
	inverse[1][1] = A[0][0];
	inverse[1][0] = -A[1][0];
	return scale_matrix(inverse, 1 / denominator);
}

// Additional operations

std::vector<double> matrix_operations::vector_matrix_product(std::vector<double> v, std::vector<std::vector<double>> A)
{
	//v*A in which v is a row vector, results in a row vector.
	assert(v.size() == A[0].size());

	std::vector<double> result;
	for (size_t i = 0; i < A.size(); i++)
	{
		result.push_back(inner_product(v, A[i]));
	}
	return result;
}

std::vector<double> matrix_operations::matrix_vector_product(std::vector<std::vector<double>> A, std::vector<double> v)
{
	//A*v in which v is a column vector, should result in a column vector. Sigh...
	assert(A[0].size() == v.size());

	std::vector<double> result;
	for (size_t i = 0; i < A.size(); i++)
	{
		result.push_back(inner_product(v, A[i]));
	}
	return result;
}