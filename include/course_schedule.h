#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <fstream>

#include "course.h"
#include "utils.h"

#define WEEKDAYS std::vector<std::string>{"M", "Tu", "W", "Th", "F"}

typedef std::vector < Course > CourseList;

enum StatusCode {
    SUCCESS,
    FAILURE,
    INVALID_FILE,
    INVALID_COURSENAME,
    INVALID_TIME
};

class Schedule
{
    public:
        std::vector< CourseSection > getCourseSections() const;
        int getSumCreditHours() const;

        void push_back( const CourseSection & cs );
        void pop_back();

        void print();

    private:
        std::vector< CourseSection > vCourseSections_;

};

class ScheduleGroup
{
    public:
        void push_back( Schedule & s );
        bool empty() const;
        void print() const;

        int getNumSchedules() const;

    private:
        std::vector< Schedule > vSchedules_;

};

bool isTimeOverlap( const CourseSection & a, const CourseSection & b );
bool isDayOverlap( const CourseSection & a, const CourseSection & b );
bool isConflict( const CourseSection & a, const CourseSection & b );

int timeStringtoMinutes( std::string & time );
std::vector<std::string> daysStringtoVec( std::string & days );

void generateSchedules( const CourseList & courseList, unsigned int index, Schedule & currSchedule, ScheduleGroup & scheduleGroup );

StatusCode scheduler( std::vector<std::string> courseNames, ScheduleGroup & bufScheduleGroup );
