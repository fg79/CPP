#ifndef GUARD_grade_h
#define GUARD_grade_H

// grade.h
#include <vector>
#include "Students_Info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool   fgrade(const Student_info& s);


#endif /*GUARD_grade_h*/
