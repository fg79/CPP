// source file for grade-related functions

#include <stdexcept>
#include "grade.h"
#include "median.h"

using std::domain_error;


double grade(double midterm, double finale, double homework)
{
	return 0.2 * midterm + 0.4 * finale + 0.4 * homework;
}

double grade(double midterm, double finale, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");

	return grade(midterm, finale, median(hw));
}

