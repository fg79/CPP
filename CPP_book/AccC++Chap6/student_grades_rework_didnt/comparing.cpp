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

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return median(grades);
}

double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.finale, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), average_grade);

	return median(grades);
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

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

	return median(grades);
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

void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
				   ", median(didnt) = " << analysis(didnt) << endl;	
}

int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> did, didnt, students;
	Student_info record;

	// read the student record and partition them
	//Invariant: students contains all the student records read so far
	//			 maxlen contains the length of the longest name in student
	while(read(cin,record)) {
		// find length of longest name
		students.push_back(record);
	}

	didnt = extract(students, did_all_hw);
	did = students;

	cout << endl << endl;


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
	write_analysis(cout,"median",median_analysis,did,didnt);
	write_analysis(cout,"average",average_analysis,did,didnt);
	write_analysis(cout,"median of homework turned in",optimistic_median_analysis,did,didnt);

	return 0;
}	
