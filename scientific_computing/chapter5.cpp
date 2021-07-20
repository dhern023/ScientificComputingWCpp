#include "chapter5.h"

Chapter5Elements chapter5_elements;

//Exercise 4.1
void cout_value_from_address(double& r_x)
{
	std::cout << "x = " << r_x << std::endl;
}

//Exercise 4.2
void change_value_from_address(double& r_x)
{
	r_x += 5;
	std::cout << r_x << std::endl;
}

//Exercise 4.3
void swap_via_passed_pointers(double* x1, double* x2)
{
	//Allocate memory
	double p_temp = *x1;

	//Make changes are visible
	*x1 = *x2;
	std::cout << "*p_x1 = " << *x1 << std::endl;
	*x2 = p_temp;
	std::cout << "*p_x2 = " << *x2 << std::endl;
}

void swap_via_passed_references(double& r_x1, double& r_x2)
{
	double r_temp = 0.0;

	//Make the changes visible
	r_temp = r_x1;
	std::cout << "r_x1 = " << r_x1 << std::endl;
	r_x1 = r_x2;
	std::cout << "r_x1 = " << r_x1 << std::endl;
	r_x2 = r_temp;
}

//Exercise 4.4
void calculate_mean_median(std::vector<double> v, double& mean, double& standard_deviation)
{
	assert(v.size() > 1);

	//Calculate mean
	double v_sum = 0;
	for (size_t i = 0; i < v.size(); i++) { v_sum += v[i]; }
	mean = v_sum / v.size();

	//Calculate standard deviation
	double numerator = 0;
	double denominator = v.size() - 1;
	for (size_t i = 0; i < v.size(); i++)
	{
		numerator += std::pow((v[i] - mean), 2);
	}
	standard_deviation = std::sqrt(numerator / denominator);
}

//Exercise 5.5 - 5.10 incorporated in namespaces.

void chapter5_couts()
{
	//Exercise 4.1
	cout_value_from_address(chapter5_elements.scalar_examples[0]);

	//Exercise 4.2
	double dummy_value = 10.0;
	std::cout << "Dummy value = " << dummy_value << std::endl;
	change_value_from_address(dummy_value);

	//Exercise 4.3
	double dummy_value2 = 20.0;
	double dummy_value3 = 30.0;
	std::cout << "Dummy value 2 = " << dummy_value2 << std::endl;
	std::cout << "Dummy value 3 = " << dummy_value3 << std::endl;
	swap_via_passed_pointers(&dummy_value2, &dummy_value3);

	//Exercise 4.4
	calculate_mean_median(chapter5_elements.vector_examples[0], chapter5_elements.mu, chapter5_elements.sigma);
	std::cout << "Mean = " << chapter5_elements.mu << std::endl;
	std::cout << "Standard deviation = " << chapter5_elements.sigma << std::endl;

	//Exercise 5.5
	couts::cout_matrix(
		vector_spaces::multiplication(
			chapter5_elements.square_matrix_examples[0],
			chapter5_elements.square_matrix_examples[1])
	);

	//Exercise 5.6 (parts 1-4)
	couts::cout_vector(
		vector_spaces::multiplication(
			chapter5_elements.vector_examples[1],
			chapter5_elements.square_matrix_examples[0])
	);
	couts::cout_vector(
	vector_spaces::multiplication(
		chapter5_elements.square_matrix_examples[0],
		chapter5_elements.vector_examples[1])
	);
	couts::cout_matrix(
	vector_spaces::scalar_multiplication(
		chapter5_elements.scalar_examples[0],
		chapter5_elements.square_matrix_examples[1])
	);
	couts::cout_matrix(
	vector_spaces::scalar_multiplication(
		chapter5_elements.square_matrix_examples[1],
		chapter5_elements.scalar_examples[2])
	);

	//Exercise 5.7
	std::cout << "p-norm for 2 = " << norms::p_norm(chapter5_elements.vector_examples[0], 2) << std::endl;

	//Exercise 5.8
	std::cout << "Determinant = " << matrices::determinant(chapter5_elements.square_matrix_examples[2]) << std::endl;

	//Lower triangular solver
	std::vector<double> y(chapter5_elements.vector_examples[1].size());
	matrices::lower_triangular_solver(
		chapter5_elements.triangular_matrix_examples[0],
		chapter5_elements.vector_examples[1],
		y
	);
	couts::cout_vector(y);

	//Upper triangular solver
	std::vector<double> x(chapter5_elements.vector_examples[2].size());
	matrices::upper_triangular_solver(
		chapter5_elements.triangular_matrix_examples[1],
		chapter5_elements.vector_examples[2],
		x
	);
	couts::cout_vector(x);

	//Exercise 5.9 & 5.10
	std::vector<double> solution_vector(chapter5_elements.square_matrix_examples[2].size());
	matrices::linear_system_solver(
		chapter5_elements.square_matrix_examples[2],
		chapter5_elements.vector_examples[3],
		solution_vector);
	couts::cout_vector(solution_vector);
};