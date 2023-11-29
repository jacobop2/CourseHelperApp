//
//  grade_calculator.hpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/15/23.
//

#ifndef grade_calculator_hpp
#define grade_calculator_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

typedef std::vector < double > GradeList;
typedef std::vector < GradeList > GradeListBlock;

double roundToTwoDecimal( double value );
double calculateGrade( const GradeListBlock & glbGrades, const std::vector< double > vGradeBreakdown );

#ifdef __cplusplus
}
#endif




#endif /* grade_calculator_hpp */
