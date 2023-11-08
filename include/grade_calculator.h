#pragma once

#include <string>
#include <vector>
#include <iostream>

typedef std::vector < double > GradeList;
typedef std::vector < GradeList > GradeListBlock;

double roundToTwoDecimal( double value );
double calculateGrade( const GradeListBlock & glbGrades, const std::vector< double > vGradeBreakdown );