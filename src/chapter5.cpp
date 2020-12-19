#include "chapter5.h"

//Exercise 4.1
void cout_value_from_address(double& r_x)
{
	std::cout << "x = " << r_x << std::endl;
}

//Exercise 4.2
void change_value_from_address(double& r_x)
{
	r_x += 5;
}

//Exercise 4.3
void swap_via_passed_pointers(double* x1, double* x2)
{
	//Allocate memory
	double* p_temp = new double;

	//Make changes are visible
	p_temp = x1;
	*x1 = *x2;
	std::cout << "*p_x1 = " << *x1 << std::endl;
	*x2 = *p_temp;
	std::cout << "*p_x2 = " << *x2 << std::endl;

	//free memory
	delete p_temp;
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

//Exercise 5.5 - 5.8 incorporated in namespaces.

//Exercise 5.9

void chapter5_couts() {};