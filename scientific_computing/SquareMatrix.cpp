#include "SquareMatrix.h"

// Constructors
SquareMatrix::SquareMatrix()
{
	matrix = {{0.0}};
	size = 1;
}

SquareMatrix::SquareMatrix(size_t size, double value_default)
{
	//construct size x size with default value
	initialize_matrix(value_default);
	size = size;
}

SquareMatrix::SquareMatrix(std::vector< std::vector< double>> A)
{
	//check matrix is square
	assert(A.size() == A[1].size());
	
	matrix = A;
	size = A[0].size();
}

// Operators
//overload assignment operator
//overload unary substraction operator
//overload binary add/substraction

// Methods
double SquareMatrix::CalculateDeterminant(SquareMatrix square_matrix) const
{
	return matrices::determinant(square_matrix.matrix);
}

// SquareMatrix SquareMatrix::CalculateInterse(SquareMatrix square_matrix) const
// {
	// return 
// }

ScaleMatrix(SquareMatrix& square_matrix, double scalar) const;
{
	// Overwrites private matrix variable
	square_matrix.matrix = vector_spaces::scalar_multiplication(square_matrix.matrix, scalar);
}

ScaleMatrix(double scalar, SquareMatrix& square_matrix) const;
{
	// Overwrites private matrix variable
	square_matrix.matrix = vector_spaces::scalar_multiplication(square_matrix.matrix, scalar);
}

SquareMatrix ScaleMatrix(SquareMatrix square_matrix, double scalar) const;
{
	SquareMatrix square_matrix_other;
	square_matrix_other.matrix = vector_spaces::scalar_multiplication(square_matrix.matrix, scalar);
	square_matrix_other.size = square_matrix.size;
	return square_matrix_other;
}

SquareMatrix ScaleMatrix(double scalar, SquareMatrix square_matrix) const;
{
	SquareMatrix square_matrix_other;
	square_matrix_other.matrix = vector_spaces::scalar_multiplication(square_matrix.matrix, scalar);
	square_matrix_other.size = square_matrix.size;
	return square_matrix_other;
}