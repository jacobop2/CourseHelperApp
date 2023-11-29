//
//  grade_calculator.cpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/15/23.
//

#include "grade_calculator.hpp"
//#include "../include/grade_calculator.h"
extern "C" {
double roundToTwoDecimal( double value )
{
    double dRounded = std::round( value * 100.0 ) / 100.0;
    return dRounded;
}

double calculateGrade( const GradeListBlock & glbGrades, const std::vector< double > vGradeBreakdown )
{
    
    if ( glbGrades.empty() || vGradeBreakdown.empty() )
    {
        return -1;
    }
    
    double sum = 0;
    for ( const double & breakdown : vGradeBreakdown )
    {
        sum += breakdown;
    }
    
    if ( 1 != sum )
    {
        return -2;
    }
    
    double dCumulativePercent = 0;
    double dAveragePercent = 0;
    double dTotalGrade = 0;
    
    for( int i = 0; i < glbGrades.size(); i++ )
    {
        GradeList currGradeList = glbGrades[i];
        auto size = currGradeList.size();
        
        for ( const double & currGrade : currGradeList )
        {
            dCumulativePercent += currGrade;
        }
        
        dAveragePercent = dCumulativePercent / size;
        dTotalGrade += dAveragePercent * vGradeBreakdown[i];
        dCumulativePercent = 0;
    }
    
    return dTotalGrade;
    
}
}
