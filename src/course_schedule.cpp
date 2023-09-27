#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>

#include "../include/course_schedule.h"
#include "../include/utils.h"
#include <algorithm>

std::vector< CourseSection > Schedule::getCourseSections() const
{
    return vCourseSections_;
}

int Schedule::getSumCreditHours() const
{
    int sum = 0;
    for( const CourseSection & s : vCourseSections_ )
    {
        sum += s.getCreditHours();
    }

    return sum;
}

void Schedule::push_back( const CourseSection & cs )
{
    vCourseSections_.push_back( cs );
}

void Schedule::pop_back()
{
    vCourseSections_.pop_back();
}

void ScheduleGroup::push_back( Schedule & s )
{
    vSchedules_.push_back( s );
}

bool ScheduleGroup::empty() const
{
    return vSchedules_.empty();
}

int ScheduleGroup::getNumSchedules() const
{
    return vSchedules_.size();
}

void ScheduleGroup::print() const
{
    for( int i = 0; i < vSchedules_.size(); i++ )
    {
        std::cout << "Schedule " << i << ": " << std::endl;

        for( const std::string & weekDay : WEEKDAYS )
        {
            std::cout << weekDay << ": ";

            for( const CourseSection & currSection : vSchedules_[i].getCourseSections() )
            {
                for( const std::string & day : currSection.getSectionDays() )
                {
                    if( day == weekDay )
                    {
                        std::cout << currSection.getCourse().getCourseName() << "/" << 
                        currSection.getSectionCode() << " (" << 
                        std::to_string( currSection.getStartTime() ) << "-" <<
                        std::to_string( currSection.getEndTime() ) << ", ";
                    }

                }
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

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

void generateSchedules( const CourseList & courseList, unsigned int index, Schedule & currSchedule, ScheduleGroup & scheduleGroup )
{
    if( courseList.empty() )
    {
        return;
    }

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
