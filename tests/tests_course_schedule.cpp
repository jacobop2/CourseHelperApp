#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/course_schedule.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

TEST_CASE( "Empty CourseList Test" )
{
    std::cout << "Beginning Empty CourseList Test" << std::endl;

    CourseList courseList;
    Schedule schedule;
    ScheduleGroup scheduleGroup;

    generateSchedules( courseList, 0, schedule, scheduleGroup );

    REQUIRE( scheduleGroup.empty() );

    std::cout << "Empty CourseList Test Finished" << std::endl;
}

TEST_CASE( "Simple CourseList Test" )
{
    std::cout << "Beginning Simple CourseList Test" << std::endl;

    CourseList courseList;
    Course course1;

    std::vector< std::string > days;
    days.push_back("M");
    days.push_back("W");
    days.push_back("F");

    CourseSection * section1a = new CourseSection( "A1", "Lec", 0, 50, days, "F", 3, course1 );
    course1.push_back( *section1a );

    Course course2;

    days.clear();
    days.push_back("Tu");
    days.push_back("Th");

    CourseSection * section2a = new CourseSection( "A2", "Dis", 60, 160, days, "F", 4, course2 );
    course1.push_back( *section2a );

    Course course3;

    days.clear();
    days.push_back("M");
    days.push_back("F");

    CourseSection * section3a = new CourseSection( "A3", "Lab", 160, 210, days, "F", 3, course3 );
    course1.push_back( *section3a );

    Schedule schedule;
    ScheduleGroup scheduleGroup;

    courseList.push_back( course1 );
    courseList.push_back( course2 );
    courseList.push_back( course3 );

    generateSchedules( courseList, 0, schedule, scheduleGroup );

    REQUIRE( scheduleGroup.getNumSchedules() == 1 );

    scheduleGroup.print();

    std::cout << "Simple CourseList Test Finished" << std::endl;
}