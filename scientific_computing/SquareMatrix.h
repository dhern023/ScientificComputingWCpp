#pragma once

#include <linear_algebra/matrices.h>
#include <linear_algebra/vector_spaces.h>

#include <cassert>
#include <iostream>
#include <vector>

class SquareMatrix
{
private:
	std::vector< std::vector< double>> matrix;
	size_t size;
	
	// Methods
	void initialize_matrix(double value_default)
	{
		std::vector< std::vector< double>> matrix(size, std::vector< double>(size, value_default));
	}
	
	
public:

	// Constructors
	SquareMatrix();
	SquareMatrix(size_t size, double value_default); //construct size x size with default value
	SquareMatrix(std::vector< std::vector< double>> A); //Pass in matrix to constructor

	// Operators
	//overload assignment operator
	//overload unary substraction operator```
	//overload binary add/substraction`

	// Methods
	double CalculateDeterminant(SquareMatrix square_matrix) const;
	//SquareMatrix CalculateInterse(SquareMatrix square_matrix) const;
	ScaleMatrix(SquareMatrix& square_matrix, double scalar) const;
	ScaleMatrix(double scalar, SquareMatrix& square_matrix) const;
	SquareMatrix ScaleMatrix(SquareMatrix square_matrix, double scalar) const;
	SquareMatrix ScaleMatrix(double scalar, SquareMatrix square_matrix) const;
};