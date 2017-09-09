#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
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
using std::map;

int main()  
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;  /*The length of the longest name*/
	map<char,int> vote;

	//read and store all the students' data
	//Invariant: students contains all the student records read so far
	//			 maxlen contains the length of the longest name in student
	while(read(cin,record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//alphabetize the student records
	sort(students.begin(),students.end(),compare);

	cout << endl << endl;

	//write the names and grades
	for(vector<Student_info>::size_type i = 0; i != students.size(); i++) {

		//write the name, padded on the right to maxlen+1 characters
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);

			if (final_grade > 90)
				vote['A']++;
			else if (final_grade > 80)
				vote['B']++;
			else if (final_grade > 70)
				vote['C']++;
			else if (final_grade > 60)
				vote['D']++;
			else
				vote['F']++;				
		}
		catch (domain_error e) {
			cout << e.what();
		}

		cout << endl;		
	}

	for( map<char,int>::const_iterator it = vote.begin(); it != vote.end(); ++it ) 
	{
		cout << "number of " << it->first << " = " << it->second << endl;
	}

		
	return 0;
}
