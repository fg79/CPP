// source file for Student_info-related functions

#include "Students_Info.h"
#include <algorithm>

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s)
{
	// read and store the student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.finale;

	read_hw(is, s.homework);
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

vector<Student_info> extract(vector<Student_info>& students, 
							 bool analysis(const Student_info&))
{
	vector<Student_info>::iterator iter = 
		stable_partition(students.begin(), students.end(), analysis);	
	vector<Student_info> extracted(iter,students.end());
	students.erase(iter,students.end());	

	return extracted;
}
