#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>

#include "course_schedule.h"
#include "utils.h"
#include <algorithm>

std::vector< CourseSection > Schedule::getCourseSections() const
{
    return vCourseSections;
}

int Schedule::getSumCreditHours() const
{
    int sum = 0;
    for( const CourseSection & s : vCourseSections )
    {
        sum += s.getCreditHours();
    }

    return sum;
}

void Schedule::push_back( const CourseSection & cs )
{
    vCourseSections.push_back( cs );
}

void Schedule::pop_back()
{
    vCourseSections.pop_back();
}

void ScheduleGroup::push_back( Schedule & s )
{
    vSchedules.push_back( s );
}

bool ScheduleGroup::empty()
{
    return vSchedules.empty();
}

bool isTimeOverlap( const CourseSection & a, const CourseSection & b )
{
    if ( a.getEndTime() + 10 >= b.getStartTime() || a.getStartTime() -10 >= b.getEndTime() )
    {
        return true;
    }

    return false;
}

bool isDayOverlap( const CourseSection & a, const CourseSection & b )
{
    for ( const std::string & currSectionDayA : a.getSectionDays() )
    {
        for ( const std::string & currSectionDayB : b.getSectionDays() )
        {
            if ( currSectionDayA == currSectionDayB )
                return true;

        }
    } 

    return false;
}

bool isConflict( const CourseSection & a, const CourseSection & b )
{
    return isTimeOverlap( a, b ) && isDayOverlap( a, b );
}

// Returns std pair so we can have an int error code
/* ERROR CODE LIST
0 - NO ERROR

*******ERRORS WITH NO SOLUTION
1 - NON EXISTENT COURSE

*******ERRORS THAT REQUIRE OVERRIDE
100 - TOO MANY CREDIT HOURS: could be solved with an override maybe a flag?

    Recursive algo for generating schedules:
    Base Case: maintain an index, every time a course is added the index is incremented
    If index = size of courselist, we have added every course and are done

    Recursive Case:
    1) Based on the current index, loop through all sections of the given course
    2) Loop through all of the sections that are currently assigned in the schedule
    If there is a time conflict, mark and break
    Otherwise, section can be assigned

    If there is no time conflict and no credit hour overload:
    1) assign the course
    2) recursively call with new index to assign next course
    3) if function returns, no solution was found, so pop back and move to next loop iteration
    Otherwise, skip to next loop iteration

*/

void generateSchedules( const CourseList courseList, unsigned int index, Schedule & currSchedule, ScheduleGroup & scheduleGroup )
{
    if( index == courseList.size() )
    {
        scheduleGroup.push_back( currSchedule );
        return;
    }

    for( const CourseSection & currSection : courseList[index].getCourseSections() )
    {
        bool bIsConflict = false;

        for( const CourseSection & existingSection : currSchedule.getCourseSections() )
        {
            if( isConflict( existingSection, currSection ) )
            {
                bIsConflict = true;
                break;
            }
        }

        if( !bIsConflict && currSchedule.getSumCreditHours() + currSection.getCreditHours() <= 18 )
        {

            currSchedule.push_back( currSection );

            generateSchedules( courseList, index + 1, currSchedule, scheduleGroup );

            currSchedule.pop_back();
        }
    }
}
