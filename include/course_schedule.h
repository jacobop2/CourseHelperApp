#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <fstream>

#include "course.h"
#include "utils.h"

#define WEEKDAYS std::vector<std::string>{"M", "T", "W", "R", "F"}

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

        Schedule() : vCourseSections_(), bNeedOverride_(false) {}

        std::vector< CourseSection > getCourseSections() const;
        int getSumCreditHours() const;

        void push_back( const CourseSection & cs );
        void pop_back();

        void setOverride( bool override );
        bool getOverride() const;
        int getNumSections() const;

        void print();
        std::string to_string();

    private:
        std::vector< CourseSection > vCourseSections_;
        bool bNeedOverride_;

};

class ScheduleGroup
{
    public:
        void push_back( Schedule & s );
        bool empty() const;
        void print() const;

        int getNumSchedules() const;

        std::vector<Schedule> & getSchedules();

    private:
        std::vector<Schedule> vSchedules_;

};

// class Break
// {
//     public:

//         std::vector< std::string > getDays() const;
//         int getStartTime() const;
//         int getEndTime() const;

//         void push_back( const std::string & s );
//         void pop_back();

//         bool empty() const;

//     private:
//         std::vector< std::string > vDays_;
//         int iStartTime_;
//         int iEndTime_;

// };

// class BreakGroup
// {
//     public:
//         void push_back( Break & b );
//         bool empty() const;

//         int getNumBreaks() const;

//         std::vector<Break> & getBreaks();

//     private:
//         std::vector<Break> vBreaks_;

// };

bool isTimeOverlap( const CourseSection & a, const CourseSection & b );
bool isDayOverlap( const CourseSection & a, const CourseSection & b );
bool isConflict( const CourseSection & a, const CourseSection & b );

int timeStringtoMinutes( std::string & time );
std::string timeMinutestoString12( int time );
std::string timeMinutestoString24( int time );

std::vector<std::string> daysStringtoVec( std::string & days );

void generateSchedules( const CourseList & courseList, unsigned int index, Schedule & currSchedule, ScheduleGroup & scheduleGroup );

StatusCode scheduler( std::vector<std::string> courseNames, ScheduleGroup & bufScheduleGroup );
