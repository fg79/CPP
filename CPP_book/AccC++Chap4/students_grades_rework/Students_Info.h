#ifndef GUARD_Student_Info
#define GUARD_Student_Info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double final_grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif /*GUARD_Student_Info*/