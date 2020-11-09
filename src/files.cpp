#include "files.h"

//File Writing =========================================================================

void files::vector_write(std::vector<double> v, std::string outname, bool append)
{
	/*
	Outputs in {..} format for easy export into other programs
	Constantly checks if the file write is okay.
	*/
	if (append)
	{
		std::ofstream write_output(outname, std::ios:app);
	}
	else 
	{
		std::ofstream write_output(outname);
	}

	// write numbers as +x.<10 digits>e+00 (width ??)
	write_output.setf(std::ios:scientific);
	write_output.setf(std::ios::showpos);
	write_output.precision(10);
	assert(write_output.is_open());

	write_output << "{";
	assert(write_output.good());
	write_output.flush()
	for (size_t i = 0; i < v.size(); i++)
	{
		write_output << v[i] << ",";
		assert(write_output.good());
		write_output.flush()
	}
	write_output << '}';
	assert(write_output.good());
	write_output.flush()

	write_output.close();
}

void files::matrix_write(std::vector<std::vector<double>> A, std::string outname, bool append)
{
	/*
	Outputs in {{..}, {..}, ...,{..}} format for easy export into other languages
	Constantly checks if the file write is okay.
	*/
	if (append)
	{
		std::ofstream write_output(outname, std::ios:app);
	}
	else
	{
		std::ofstream write_output(outname);
	}

	// write numbers as +x.<10 digits>e+00 (width ??)
	write_output.setf(std::ios:scientific);
	write_output.setf(std::ios::showpos);
	write_output.precision(10);
	assert(write_output.is_open());

	write_output << "{";
	assert(write_output.good());
	write_output.flush()
	for (size_t i = 0; i < A.size(); i++)
	{
		write_output << "{";
		assert(write_output.good());
		write_output.flush()

		for (size_t j = 0; j < A[0].size(); j++)
		{
			write_output << A[i][j] << ",";
			assert(write_output.good());
			write_output.flush()
		}

		if (i == A.size()-1)
		{
			write_output << '}';
			assert(write_output.good());
			write_output.flush()
		}
		else
		{
			write_output << '},';
			assert(write_output.good());
			write_output.flush()
		}
	}
	write_output << "}";
	assert(write_output.good());
	write_output.flush()

	write_output.close();
}