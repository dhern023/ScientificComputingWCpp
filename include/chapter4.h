#pragma once
#include "couts.h"
#include <iostream>
#include <memory>
#include <vector>


struct Chapter4Elements
{
	std::vector<std::string> prompts = {
		"Practice pointer arithmetic",
		"Swap via pointers",
		"Array deallocation",
		"Vector (automatic) deallocation",
		"2D array deallocation",
		"2D vector (automatic) deallocation"
	};

	//Exercises 4.2, 4.4
	std::vector<std::vector<int>> int_pairs = {
		{2, 9}, { 1, 3 }, { 9, 4}, {41, 67}
	};

	//Exercise 4.3
	std::vector<int> ints = {
		3, 6, 4
	};
};

//exercise 4.1
void practice_precision_arithmetic();
//exercise 4.2
void swap_values_via_pointers(int x1, int x2);
//exercise 4.3
void test_proper_array_deallocation(int x);
void vectors_deallocate_demonstration(int x);
//exercise 4.4
void test_proper_matrix_deallocation(int rows = 2, int cols = 2);
void matrix_deallocate_demonstration(int rows = 2, int cols = 2);
//exercise 4.5
void weak_pointer_practice();

void chapter4_couts();