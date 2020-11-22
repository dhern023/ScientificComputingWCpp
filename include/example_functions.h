#pragma
#include <cmath>
#include <vector>

class PolynomialExamples 
{
	public:
		//return one function pointer
		double function_result(size_t g, double x);
		//return many function pointers
		std::vector<double> function_results(double x);

	private:
		std::vector <double(*)(double)> function_vector = {
			[](double x) { return std::pow(x, 2) + 0.25; },
			[](double x) { return std::pow(x, 2); },
			[](double x) { return std::pow(x, 2) - 0.24; },
			[](double x) { return std::pow(x, 2) - 0.75; },
			[](double x) { return 0.4 * x * (1 - x); },
			[](double x) { return x * (1 - x); },
			[](double x) { return 1.6 * x * (1 - x); },
			[](double x) { return 2 * x * (1 - x); },
			[](double x) { return 2.4 * x * (1 - x); },
			[](double x) { return 3.0 * x * (1 - x); },
			[](double x) { return 2.4 * x * (1 - x); },
			[](double x) { return 0.4 * std::sin(x); },
			[](double x) { return std::sin(x); }
		};
};

class NewtonRaphsonExamples {
	public:
		//return one function pointer pair
		std::vector<double(*)(double)> function_pair_result(size_t g);

	private:		
		std::vector<double(*)(double)> pair1 = {
			[](double x) { return std::exp(x) + std::pow(x, 3) - 5; }, //exp(x) + x^3 - 5
			[](double x) { return std::exp(x) + 3 * x * x; } //exp(x) + 3x^2
		};
		
		std::vector <double(*)(double)> pair2 = {
			[](double x) { return -0.74 + 0.765 * x + 1.1 * x * x - 3.55 * std::pow(x, 3); }, //-0.74 + 0.765x + 1.1x^2 - 3.55x^3
			[](double x) { return 0.765 + 2.2 * x - 3.55 * 3 * std::pow(x, 2); } //0.765 + 2.2x - 3(3.55)x^2
		};

		std::vector<std::vector<double(*)(double)>> function_vector_pairs = {
			pair1, pair2
		};
};