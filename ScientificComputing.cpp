// Scientific Computing.cpp : Defines the entry point for the application.

#include "ScientificComputing.h"
#include "include/chapter1.h"
#include "include/chapter2.h"

int main()
{
	chapter1_couts(); //Runs into unresolved external even though it has a body in chapter1.cpp
	chapter1_couts; //Compiles but doesn't do anything as expected
	//chapter2_couts();
	return 0;
}
