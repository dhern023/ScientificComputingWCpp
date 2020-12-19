#include "../include/matrices.h"

void matrices::LU_decomposition(std::vector<std::vector<double>> A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U)
{
	/*
	Performs the LU decomposition of a matrix with pivoting, to create
	LU = PA, where P is the permutation matrix.

	L, U are passed in as reference variables.

	(C) Plamen Koev of SJSU
	*/

	/*
	If all matrices are square, then by translation,
	confirming equality on all pairs of one side
	implies all matrices are the same size.
	*/

	//check all the matrices are square
	assert(A.size() == A[1].size());
	assert(L.size() == L[1].size());
	assert(U.size() == U[1].size());
	//check all matrices are the same size
	assert(A.size() == L.size() && A.size() == U.size());

	//initialize the permutation vector, a cyclic group of order A.size().
	std::vector<double> p;
	for (size_t i = 0; i < A.size(); i++) { p.push_back(i); }

	double max = 0.0;
	double candidate = 0.0;
	size_t index = 0;
	std::vector<double> temp_row_vector;
	double temp_value = 0.0;

	for (size_t j = 0; j < A.size(); j++)
	{
		//find the largest entry below A[j][j]
		max = std::fabs(A[j][j]);
		index = j;
		for (size_t i = j + 1; i < A.size(); i++)
		{
			candidate = std::fabs(A[i][j]);
			if (candidate > max)
			{
				max = candidate;
				index = i;
			}
		}

		//swap row index and row j
		temp_row_vector = A[index];
		A[index] = A[j];
		A[j] = temp_row_vector;
		U[j] = temp_row_vector;

		//swap indices in the premutation cycle
		temp_value = p[index];
		p[index] = p[j];
		p[j] = temp_value;

		//Gaussian Elimination
		for (size_t i = j + 1; i < A.size(); i++)
		{
			A[i][j] = A[i][j] / A[j][j];
			L[i][j] = A[i][j]; //Store values in L
			for (size_t k = j+1; k < A.size(); k++)
			{
				A[i][k] = A[i][k] - A[i][j] * A[j][k];
			}
		}
		L[j][j] = 1; //Assign 1 along diagonal
		//U is upper triangular
		for (size_t i = 0; i < j; i++) { U[j][i] = 0; }
	}
}

double matrices::determinant(std::vector<std::vector<double>> A)
{
	/*
	Decomposes A = LU
	Since determinant is linear wrt products,
	det(upper or lower triangular M) = prod(diag(M)),
	diag(L) = 1, then
	det(A) = det(L)*det(U) = det(U) = prod(diag(U)).
	*/

	//Factor A = LU
	std::vector<std::vector<double>> L(A.size(), std::vector<double>(A.size()));
	std::vector<std::vector<double>> U(A.size(), std::vector<double>(A.size()));
	matrices::LU_decomposition(A, L, U);

	//Calculate det(U) = prod(diag(U))
	double result = 1.0;
	for (size_t i = 0; i < U.size(); i++)
	{
		result *= U[i][i];
	}

	return result;
}