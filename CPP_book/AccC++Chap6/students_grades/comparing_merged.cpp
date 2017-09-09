#include <algorithm>
#include <numeric>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "median.h"
#include "grade.h"
#include "Students_Info.h"


using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::ostream;


double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.finale, 0);
	}
}


double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.finale, average(s.homework));
}


double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if(nonzero.empty())
		return grade(s.midterm, s.finale, 0);
	else
		return grade(s.midterm, s.finale, median(nonzero));
}



bool did_all_hw(const Student_info& s)
{
#if 0
	vector<double>::const_iterator iter;
	
	cout << s.name << " midterm = " << s.midterm << " finale = " << s.finale << " homework = ";

	for (iter = s.homework.begin(); iter != s.homework.end(); ++iter) 
	{
		cout << *iter << " ";
	}	

	cout << endl; 
#endif

	return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}


double merged_analysis(const vector<Student_info>& students,
    				   double analysis_function(const Student_info&))
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), analysis_function);

	return median(grades);
}


void write_analysis(ostream& out, const string& name,
					double analysis(const Student_info&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << merged_analysis(did, analysis) <<
				   ", median(didnt) = " << merged_analysis(didnt, analysis) << endl;	
}


int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> did, didnt;

	// read the student record and partition them
	Student_info student;
	while(read(cin,student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	// verify that the analyses will show us something
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;		
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;		
	}
	
	// do the analyses
	write_analysis(cout,"median",grade_aux,did,didnt);
	write_analysis(cout,"average",average_grade,did,didnt);
	write_analysis(cout,"median of homework turned in",optimistic_median,did,didnt);

	return 0;
}	
