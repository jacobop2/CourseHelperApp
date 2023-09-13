#pragma once

#include <string>
#include <vector>

#include "course.h"

typedef std::vector < Course > CourseList;

class Schedule
{
    public:
        std::vector< CourseSection > getCourseSections() const;
        int getSumCreditHours() const;

        void push_back( const CourseSection & cs );
        void pop_back();

    private:
        std::vector< CourseSection > vCourseSections;

};

class ScheduleGroup
{
    public:
        void push_back( Schedule & s );
        bool empty();

    private:
        std::vector< Schedule > vSchedules;

};

bool isTimeOverlap( const CourseSection & a, const CourseSection & b );
bool isDayOverlap( const CourseSection & a, const CourseSection & b );
bool isConflict( const CourseSection & a, const CourseSection & b );

void generateSchedules( const CourseList courseList, unsigned int index, Schedule & currSchedule, ScheduleGroup & scheduleGroup );