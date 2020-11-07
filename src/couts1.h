#pragma once
#include "exercises1.h"
#include <vector>
#include "../include/couts.h"
#include "../include/norms.h"
#include "../include/vector_operations.h"
#include "../include/matrix_operations.h"

std::vector<std::string> chapter1_prompts = {
	"Multiplying two numbers",
	"Inner product of two vectors",
	"Two norm of two vectors",
	"Matrix addition",
	"Matrix transpose",
	"Matrix multiplication",
	"Vector average",
	"2x2 inverse"
};

std::vector<std::vector<double>> multiply_pairs = {
	{0,1}, {1,0}, {2, 1}, {1, 2}, {14, 14}, {90, 12}, {100, 100}
};

std::vector<std::vector<double>> vector_examples = {
	{-1, 0, 1, 0, 2}, {34, 58, 57, 32, 43}
};

std::vector<std::vector<double>> A = {
	{1,2,3}, {4,5,6}, {7,8,9}
};

void chapter1_couts()
{
	std::cout << chapter1_prompts[0] << std::endl;
	for (size_t i = 0; i < multiply_pairs.size(); i++)
	{
		std::cout << multiply_two_numbers(multiply_pairs[i][0], multiply_pairs[i][1]) << std::endl;
	}
	std::cout << chapter1_prompts[1] << std::endl;
	std::cout << inner_product(vector_examples[0], vector_examples[1]) << std::endl;

	std::cout << chapter1_prompts[2] << std::endl;
	std::cout << two_norm(vector_examples[0], vector_examples[1]) << std::endl;

	std::cout << chapter1_prompts[3] << std::endl;
	std::vector<std::vector<double>> A_A = matrix_addition(A, A);
	cout_matrix(A_A);

	std::cout << chapter1_prompts[4] << std::endl;
	std::vector<std::vector<double>> A_T = matrix_transpose(A);
	cout_matrix(A_T);

	std::cout << chapter1_prompts[5] << std::endl;
	std::vector<std::vector<double>> B = matrix_multiplication(A, A);
	cout_matrix(B);

	std::cout << chapter1_prompts[6] << std::endl;
	std::cout << vector_avg(vector_examples[1]) << std::endl;
}