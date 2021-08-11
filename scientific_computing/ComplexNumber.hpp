#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>
#include <cmath>
#include <vector>

class ComplexNumber
{
private:
   double mRealPart;
   double mImaginaryPart;
public:
	ComplexNumber();
	ComplexNumber(double x, double y);
	double CalculateModulus() const;
	double CalculateArgument() const;
	ComplexNumber CalculatePower(double n) const;
	ComplexNumber& operator=(const ComplexNumber& z);
	ComplexNumber operator-() const;
	ComplexNumber operator+(const ComplexNumber& z) const;
	ComplexNumber operator-(const ComplexNumber& z) const;
	friend std::ostream& operator<<(std::ostream& output, 
								   const ComplexNumber& z);
	//Chapter 6 Exercises ==================================
	double GetRealPart() const; //access parts
	double GetImaginaryPart() const;
	friend double RealPart(ComplexNumber& z); //friend to access parts
	friend double ImaginaryPart(ComplexNumber& z);
	ComplexNumber(const ComplexNumber& z); //overwrite copy constructor
	ComplexNumber(double x); //real number as complex a + 0i
	ComplexNumber CalculateConjugate(const ComplexNumber& z); //return conjugate
	void SetToConjugate(ComplexNumber& z); //conjugate in-place
	//std::vector< std::vector< ComplexNumber>> CalculateMatrixExponential(std::vector< std::vector< ComplexNumber>>);
	
};

#endif
//Code from Chapter06.tex line 946 save as ComplexNumber.hpp
