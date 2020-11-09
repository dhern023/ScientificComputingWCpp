#include "../include/chapter1.h"

struct ChapterOneElements chapter1_elements;

// Exercise 1.2
double multiply_two_numbers(double x1, double x2)
{
	return x1 * x2;
}

void chapter1_couts()
{
	//1.2
	std::cout << chapter1_elements.prompts[0] << std::endl;
	for (size_t i = 0; i < chapter1_elements.multiply_pairs.size(); i++)
	{
		std::cout << multiply_two_numbers(chapter1_elements.multiply_pairs[i][0], chapter1_elements.multiply_pairs[i][1]) << std::endl;
	}
	//1.3
	std::cout << chapter1_elements.prompts[1] << std::endl;
	std::cout << vector_operations::inner_product(chapter1_elements.vector_examples[0], chapter1_elements.vector_examples[1]) << std::endl;

	std::cout << chapter1_elements.prompts[2] << std::endl;
	std::cout << norms::two_norm(chapter1_elements.vector_examples[0], chapter1_elements.vector_examples[1]) << std::endl;

	//1.4
	std::cout << chapter1_elements.prompts[3] << std::endl;
	std::vector<std::vector<double>> A_A = matrix_operations::matrix_addition(chapter1_elements.A, chapter1_elements.A);
	couts::cout_matrix(A_A);

	std::cout << chapter1_elements.prompts[4] << std::endl;
	std::vector<std::vector<double>> A_T = matrix_operations::matrix_transpose(chapter1_elements.A);
	couts::cout_matrix(A_T);

	std::cout << chapter1_elements.prompts[5] << std::endl;
	std::vector<std::vector<double>> B = matrix_operations::matrix_multiplication(chapter1_elements.A, chapter1_elements.A);
	couts::cout_matrix(B);

	//1.6
	std::cout << chapter1_elements.prompts[6] << std::endl;
	std::cout << vector_operations::vector_avg(chapter1_elements.vector_examples[1]) << std::endl;
}