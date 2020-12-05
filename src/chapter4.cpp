#include "../include/chapter4.h"

struct Chapter4Elements chapter4_elements;

void practice_precision_arithmetic()
{
	int i = 5;
	int* p_j = &i; //pointer is a variable that stores a memory address
	std::cout << "*p_j * 5 = " << *p_j * 5 << std::endl; //*p_j stores i's contents

	int* p_k;
	p_k = new int; //allocate a location in memory
	*p_k = i; //store the contents of the variable i in this location
	*p_j = 0.0;

	std::cout << "i = " << i << std::endl;
	std::cout << "*p_k = " << *p_k << std::endl;
	std::cout << "*p_j = " << *p_j << std::endl;


	//free memory
	delete p_k;
}

void swap_values_via_pointers(int x1, int x2)
{
	//std::swap(x1, x2); //saves us the trouble

	int* p_x1 = &x1;
	int* p_x2 = &x2;
	//std::iter_swap(p_x1, p_x2);

	std::cout << *p_x1 << " " << *p_x2 << std::endl;

	int* p_temp;
	p_temp = new int;

	*p_temp = *p_x1;
	*p_x1 = *p_x2;
	*p_x2 = *p_temp;

	std::cout << *p_x1 << " " << *p_x2 << std::endl;

	//free memory
	delete p_temp;
}

//Exercise 4.3
void test_proper_array_deallocation(int x)
{
	for (size_t j = 0; j < 1e6; j++)
	{
		//allocates memory dynamically to two vectors of size 3
		double* v1;
		double* v2;
		v1 = new double[x];
		v2 = new double[x];

		//assigns values to each of the entries
		for (size_t i = 0; i < x; i++)
		{
			v1[i] = (double)(i);
			v2[i] = 2 * v1[i];
		}

		//inner product
		double result = 0;
		for (size_t i = 0; i < x; i++)
		{
			result += v1[i] * v2[i];
		}
		//std::cout << result << std::endl; //Printing to console takes forever

		//free memory
		delete[] v1;
		delete[] v2;
	}
}

void vectors_deallocate_demonstration(int x)
{
	for (size_t j = 0; j < 1e6; j++)
	{
		//allocates memory dynamically to two vectors of size 3
		std::vector<double> v1;
		std::vector<double> v2;

		//assigns values to each of the entries
		for (size_t i = 0; i < x; i++)
		{
			v1.push_back((double)i);
			v2.push_back(2 * v1[i]);
		}

		//inner product
		double result = 0;
		for (size_t i = 0; i < x; i++)
		{
			result += v1[i] * v2[i];
		}
		//std::cout << result << std::endl; //Printing to console takes forever

		//free memory
	}
}

//Exercise 4.4
void test_proper_matrix_deallocation(int rows, int cols)
{
	for (size_t i = 0; i < 1e6; i++)
	{
		//allocates memory for three 2 × 2 matrices
		double** A;
		double** B;
		double** C; //C = A + B

		A = new double* [rows];
		B = new double* [rows];
		C = new double* [rows];

		for (size_t i = 0; i < rows; i++)
		{
			A[i] = new double[cols];
			B[i] = new double[cols];
			C[i] = new double[cols];
		}

		//assign values and calculate C
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				A[i][j] = (double)1;
				B[i][j] = (double)2;
				C[i][j] = A[i][j] + B[i][j];
			}
		}

		//free memory
		for (size_t i = 0; i < rows; i++) { delete[] A[i]; }
		delete[] A;

		for (size_t i = 0; i < rows; i++) { delete[] B[i]; }
		delete[] B;

		for (size_t i = 0; i < rows; i++) { delete[] C[i]; }
		delete[] C;
	}
}

void matrix_deallocate_demonstration(int rows, int cols)
{
	for (size_t i = 0; i < 1e6; i++)
	{
		//allocates memory for three 2 × 2 matrices
		std::vector<std::vector<double>> A(rows);
		std::vector<std::vector<double>> B(rows);
		std::vector<std::vector<double>> C(rows);

		//assign values and calculate C
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				A[i].push_back((double)1);
				B[i].push_back((double)1);
				C[i].push_back(A[i][j] + B[i][j]); //Should this in own for-loop?
			}
		}
		//free memory
	}
}

//Exercise 4.5
/*
The weak_ptr smart pointer does not contribute to the use count.
It can be used in situations when one needs to access existing variables.
Its expired attribute can be used to check if its resource has been deleted.
Its lock attribute can be used to get to the non-deleted resource.
*/
void weak_pointer_practice()
{
	std::shared_ptr<double> p_x(new double);
	std::cout << "p_x use count: " << p_x.use_count() << "\n";
	*p_x = 5;

	//Initialize a weak_ptr to the value p_x.
	std::weak_ptr<double> p_w = p_x;
	std::cout << "p_x use count: " << p_x.use_count() << "\n";
	//p_x's original value (i.e., the value 5) via this weak smart pointer...
	std::cout << "p_w resource existed: " << p_w.expired() << "\n";
	//...before the p_x is reset.
	std::cout << "p_w stored resource : " << p_w.lock() << "\n";
	p_x.reset();
	std::cout << "p_x use count: " << p_x.use_count() << "\n";
	//...after the p_x is reset.
	std::cout << "p_w resource existed: " << p_w.expired() << "\n";
}

void chapter4_couts()
{
	//Exercise 4.1
	std::cout << chapter4_elements.prompts[0] << std::endl;
	practice_precision_arithmetic();

	//Exercise 4.2
	std::cout << chapter4_elements.prompts[1] << std::endl;
	for (size_t i = 0; i < chapter4_elements.int_pairs.size(); i++)
	{
		swap_values_via_pointers(
			chapter4_elements.int_pairs[i][0],
			chapter4_elements.int_pairs[i][1]
		);
	}

	//Exercise 4.3
	std::cout << chapter4_elements.prompts[2] << std::endl;
	test_proper_array_deallocation(chapter4_elements.ints[1]);
	std::cout << chapter4_elements.prompts[3] << std::endl;
	vectors_deallocate_demonstration(chapter4_elements.ints[2]);

	//Exercise 4.4
	std::cout << chapter4_elements.prompts[4] << std::endl;
	test_proper_matrix_deallocation(
		chapter4_elements.int_pairs[2][0],
		chapter4_elements.int_pairs[2][1]
	);
	std::cout << chapter4_elements.prompts[5] << std::endl;
	matrix_deallocate_demonstration(
		chapter4_elements.int_pairs[1][0],
		chapter4_elements.int_pairs[1][1]
	);

	//Exercise 4.5
	weak_pointer_practice();
}