#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdio>
#include "stdio.h"
#include <cstring>

#include "schedule.h"
#include "utils.h"
#include <algorithm>

bool isTimeOverlap( CourseSection * a, & CourseSection * b )
{
    if ( a->getEndTime() + 10 >= b->getStarTime() || a->getStartTime() -10 >= b->getEndTmie() )
    {
        return true;
    }

    return false;
}

bool isDayOverlap( CourseSection a, CourseSection b )
{
    for ( const std::string currSectionDayA : a->getSectionDays )
    {
        for ( const std::string currSectionDayB : b->getSectionDays )
        {
            if ( currSectionDayA == currSectionDayB )
                return true;

        }
    } 

    return false;
}

// Returns std pair so we can have an int error code
/* ERROR CODE LIST
0 - NO ERROR

*******ERRORS WITH NO SOLUTION
1 - NON EXISTENT COURSE

*******ERRORS THAT REQUIRE OVERRIDE
100 - TOO MANY CREDIT HOURS: could be solved with an override


*/

std::pair< std::vector< CourseSection >, int >  assignSchedule( std::vector< std::string > courseList )
{

    std::vector< CourseSection > schedule;
    int sumCreditHours = 0;

    for ( const Course & c : courseList )
    {
        if ( !doesExist( c ) ) // NEED TO IMPLEMENT
        {
            return std::makepair( schedule, 1 );
        }

        sumCreditHours += c->getCreditHours();

        if ( sumCreditHours > 18 )
        {
            return std::makepair( schedule, 100 );
        }

    }

    std::sort ( courseList.begin(), courseList.end(), [](const Course& a, const Course& b ) {
        return a.length > b.length;
    } );

    // CURRENT TIME KEPT IN MINUTES FOR SIMPLE MATH

    for ( const Course & currCourse : courseList )
    {
        bool bAssigned = false;

        for ( const CourseSection & currSection : currCourse )
        {
            
            // Can we get data on if a section is full? Assume no / not needed
            //if ( currSection->isFull ...)

            int conflictCount;

            for ( const CourseSection & assignedSection : schedule )
            {
                if ( isTimeOverlap( &currSection, &assignedSection ) && isDayOverlap( &currSection, &assignedSection ) )
                {
                    conflictCount++;

                    if ( is)
                    continue;
                }


            }

        }

    }

    /*
        Schedule Filling Algo:
        1: Get vector of Adjlist with class to insert in timeslot
        2: Check if sched vector is size one; if so, it only has timeslot, and insert is guaranteed
        3: if not size one, loop through beginning with 1
            read each present course, find corresponding course vector in adjlist, check if curr course conflicts
        4: if there is no conflict, insert and move on
        5: if there is a conflict, move to the next row of sched, repeat process
        6: if no fit is found, clear schedule and retry with second course in the first timeslot
        7: if loop through all courses and still no solution is found, return cleared sched
        8: if there is a solution found, return sched
    
    */

}
