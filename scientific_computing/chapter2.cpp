#include "chapter2.h"

struct ChapterTwoElements chapter2_elements;

std::vector <double(*)(double)> convergent_pair = NewtonRaphsonExamples().function_pair_result(0);
std::vector <double(*)(double)> divergent_pair = NewtonRaphsonExamples().function_pair_result(1);

std::vector<sChapter2BaseArgs> vArgs = {
	sChapter2BaseArgs(10, 5.0, 10.0, -11.0, { 1,1,1 }),
	sChapter2BaseArgs(20, 5.0, 67.0, 11.0, { 1,0,1 }),
	sChapter2BaseArgs(70, 14.0, 92.0, -87.0, { 0,0,1 }),
	sChapter2BaseArgs(20, 26.0, 10.0, 87.0, { 0,1,0 }),
	sChapter2BaseArgs(50, 55.0, 10.0, -11.0, { 0,0,0 }),
	sChapter2BaseArgs(10, 3.0, 10.0, -11.0, { 1,1,1 })
};

void inequality1(double x, double y)
{
	if ((x >= y) || (0.5 > x))
	{
		std::cout << 4.0 << std::endl;
	}
	else
	{
		//x < y or 5.0 < y
		std::cout << 2.0 << std::endl;
	}
}

void inequality2(int j, double p, double q, double y, std::vector<bool> vBool)
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

void chapter2_couts()
{
	//Exercise 2.1
	std::cout << chapter2_elements.prompts[0] << std::endl;
	for (size_t i = 0; i < chapter2_elements.v_examples.size(); i++)
	{
		inequality1(chapter2_elements.v_examples[i][0], chapter2_elements.v_examples[i][1]);
	}

	//Exercise 2.2
	std::cout << chapter2_elements.prompts[1] << std::endl;
	for (size_t i = 0; i < vArgs.size(); i++)
	{
		inequality2(vArgs[i].j, vArgs[i].d1, vArgs[i].d2, vArgs[i].d3, vArgs[i].vBool);
	}

	//Exercise 2.4
	std::cout << chapter2_elements.prompts[2] << std::endl;
	couts::cout_vector(
		vector_spaces::subtraction(
			chapter2_elements.v_examples2[0],
			chapter2_elements.v_examples2[1])
	);

	std::cout << chapter2_elements.prompts[3] << std::endl;
	couts::cout_vector(
		vector_spaces::multiplication(
			chapter2_elements.m_examples[0],
			chapter2_elements.v_examples2[1])
	);

	std::cout << chapter2_elements.prompts[4] << std::endl;
	couts::cout_vector(
		vector_spaces::subtraction(
			vector_spaces::multiplication(chapter2_elements.m_examples[0], chapter2_elements.v_examples2[1]),
			chapter2_elements.v_examples2[1]
		)
	);

	std::cout << chapter2_elements.prompts[5] << std::endl;
	couts::cout_matrix(
		vector_spaces::subtraction(
			vector_spaces::scalar_multiplication(chapter2_elements.m_examples[0], 4),
			vector_spaces::scalar_multiplication(chapter2_elements.m_examples[1], 3)
		)
	);

	std::cout << chapter2_elements.prompts[6] << std::endl;
	couts::cout_matrix(
		vector_spaces::addition(
			vector_spaces::scalar_multiplication(chapter2_elements.m_examples[0], 4),
			vector_spaces::scalar_multiplication(chapter2_elements.m_examples[1], -3)
		)
	);

	std::cout << chapter2_elements.prompts[7] << std::endl;
	couts::cout_matrix(
		vector_spaces::multiplication(
			chapter2_elements.m_examples[0],
			chapter2_elements.m_examples[1])
	);

	//Exercise 2.5
	std::cout << chapter2_elements.prompts[8] << std::endl;
	couts::cout_matrix(
		vector_spaces::matrix_invert_2x2(chapter2_elements.m_examples[2])
	);

	//Exercise 2.6
	std::cout << chapter2_elements.prompts[9] << std::endl;
	newton_raphson_method(convergent_pair[0], convergent_pair[1], 0);

	std::cout << chapter2_elements.prompts[10] << std::endl;
	newton_raphson_method(divergent_pair[0], divergent_pair[1], 5.0/9.0);
}