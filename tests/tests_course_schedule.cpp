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