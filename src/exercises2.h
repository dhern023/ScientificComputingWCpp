#pragma once
#include <cassert>
#include <cmath>
#include <vector>

double inequality_2_1(double x, double y)
{
	if ((x >= y) || (0.5 > x)) { return 4.0; }
	else
	{
		//x < y or 5.0 < y
		return 2.0;
	}
}

void inequlity_2_2(int j, double p, double q, double y, std::vector<bool> vBool)
{
	assert(vBool.size() == 3);
	bool bool1 = (p >= q) || (j != 10);
	bool bool2 = (y >= q) && (j == 20);
	double x;

	if (vBool[0] && bool1) { std::cout << 5 << std::endl; }
	if (vBool[1])
	{
		if ((y >= q) || j == 20) { std::cout << 5 << std::endl; }
		else { x = p; }
	}

	if (vBool[2])
	{
		if (p > q) { std::cout << 0 << std::endl; }
		else if ((q >= p) && (j == 10)) { std::cout << 1 << std::endl; }
		else { std::cout << 2 << std::endl; }
	}
}

void newton_raphson_example_2_6(double seed)
{
	auto f = [](double x) { return std::exp(x) + std::pow(x, 3) - 5; };
	auto f_prime = [](double x) { return std::exp(x) + 3 * x * x; };

	double epsilon = 10e-6;
	std::vector<double> results(2,seed);
	do
	{
		results[0] = results[1];
		results[1] = results[0] - f(results[0]) / f_prime(results[0]);
		std::cout << results[0] << ", " << results[1] << std::endl;
	} while (std::abs(results[1] - results[0]) > epsilon);

	std::cout << results[1] << std::endl;
}

void newton_method_wont_converge(double seed) 
{
	auto f = [](double x) { return -0.74 + 0.765 * x + 1.1 * x * x - 3.55 * std::pow(x, 3); };
	auto f_prime = [](double x) { return 0.765 + 2.2 * x - 3.55 * 3 * std::pow(x, 2); };

	double epsilon = 10e-6;
	std::vector<double> results(2, seed);
	do
	{
		results[0] = results[1];
		results[1] = results[0] - f(results[0]) / f_prime(results[0]);
		std::cout << results[0] << ", " << results[1] << std::endl;
	} while (std::abs(results[1] - results[0]) > epsilon);

	std::cout << results[1] << std::endl;
}