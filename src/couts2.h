#pragma once
#include <vector>
#include "../include/couts.h"
#include "exercises2.h"


std::vector<std::string> chapter2_prompts = {
	"If-Then Inequality",
	"If-Then Inequality (2)",
	"v1 - v2",
	"matrix * vector",
	"matrix * vector - vector",
	"difference of scaled matrices",
	"addition of scaled negative matrix (same result)",
	"matrix * matrix",
	"2x2 inverse",
	"Newton's method converges",
	"Newton's method won't converge"
};

struct sBaseArgs
{
	int j;
	double p, q, z;
	std::vector<bool> vBool;
	sBaseArgs(int J, double P, double Q, double Z, std::vector<bool> VBool):
		j(J), p(P), q(Q), z(Z), vBool(VBool) {}
};

std::vector<sBaseArgs> vArgs = {
	sBaseArgs(10, 5.0, 10.0, -11.0, { 1,1,1 }),
	sBaseArgs(20, 5.0, 67.0, 11.0, { 1,0,1 }),
	sBaseArgs(70, 14.0, 92.0, -87.0, { 0,0,1 }),
	sBaseArgs(20, 26.0, 10.0, 87.0, { 0,1,0 }),
	sBaseArgs(50, 55.0, 10.0, -11.0, { 0,0,0 }),
	sBaseArgs(10, 3.0, 10.0, -11.0, { 1,1,1 })
};

std::vector<std::vector<double>> v_examples = {
	{10.0, -1.0}, {10.0, 20.0}, {0.0, 20.0}
};

std::vector<std::vector<double>> v_examples2 = {
	{1,2,3}, {6,5,4}
};

std::vector<std::vector<std::vector<double>>> m_examples = {
	{ {1, 5, 0}, { 7,1,2 }, { 0,0,1 } },
	{ {-2,0,1}, {1,0,0}, {4,1,0} },
	{ {4,10}, {1,1} }
};

void chapter2_couts()
{
	std::cout << chapter2_prompts[0] << std::endl;
	for (size_t i = 0; i < v_examples.size(); i++)
	{
		std::cout << inequality_2_1(v_examples[i][0], v_examples[i][1]) << std::endl;
	}
	
	std::cout << chapter2_prompts[1] << std::endl;
	for (size_t i = 0; i < vArgs.size(); i++)
	{
		inequlity_2_2(vArgs[i].j, vArgs[i].p, vArgs[i].q, vArgs[i].z, vArgs[i].vBool);
	}
	std::cout << chapter2_prompts[2] << std::endl;
	cout_vector(vector_subtraction(v_examples2[0], v_examples2[1]));

	std::cout << chapter2_prompts[3] << std::endl;
	cout_vector(matrix_vector_product(m_examples[0], v_examples2[1]));

	std::cout << chapter2_prompts[4] << std::endl;
	cout_vector(
		vector_subtraction(
			matrix_vector_product(m_examples[0], v_examples2[1]),
			v_examples2[1]
		)
	);

	std::cout << chapter2_prompts[5] << std::endl;
	cout_matrix(
		matrix_subtraction(
			scale_matrix(m_examples[0], 4),
			scale_matrix(m_examples[1], 3)
		)
	);

	std::cout << chapter2_prompts[6] << std::endl;
	cout_matrix(
		matrix_addition(
			scale_matrix(m_examples[0], 4),
			scale_matrix(m_examples[1], -3)
		)
	);

	std::cout << chapter2_prompts[7] << std::endl;
	cout_matrix(
		matrix_multiplication(m_examples[0], m_examples[1])
	);

	std::cout << chapter2_prompts[8] << std::endl;
	cout_matrix(matrix_invert_2x2(m_examples[2]));

	std::cout << chapter2_prompts[9] << std::endl;
	newton_raphson_example_2_6(0);

	/*
	std::cout << chapter2_prompts[10] << std::endl;
	newton_method_wont_converge(5.0 / 9.0); //warning, will not converge
	*/
}