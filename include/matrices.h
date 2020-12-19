#pragma once
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>

/*
Specific operations that have to do with arrays of size 2D or higher.
E.g., you can't decompose a vector...or can you?
*/

namespace matrices {
	void LU_decomposition(std::vector<std::vector<double>> A, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U);
	double determinant(std::vector<std::vector<double>> A);
}