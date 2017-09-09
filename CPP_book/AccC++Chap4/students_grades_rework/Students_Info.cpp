// source file for Student_info-related functions

#include "Students_Info.h"
#include "grade.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s)
{
	std::vector<double> homework;
	double midterm,finale;

	// read and store the student's name and midterm and final exam grades
	is >> s.name >> midterm >> finale;

	read_hw(is, homework);
	
	if (is) {
		s.final_grade = grade(midterm, finale, homework);
	}

	return is;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();		
	}

	return in;
}
