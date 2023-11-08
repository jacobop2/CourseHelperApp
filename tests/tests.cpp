#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/course_schedule.h"
#include "../include/grade_calculator.h"
#include "../include/course.h"
#include "../include/utils.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define EPSILON 0.01

TEST_CASE ( "Empty CourseList Test" )
{
    std::cout << "\n" << "Beginning Empty CourseList Test" << std::endl;

    CourseList courseList;
    Schedule schedule;
    ScheduleGroup scheduleGroup;

    generateSchedules( courseList, 0, schedule, scheduleGroup );

    REQUIRE( scheduleGroup.empty() );

    std::cout << "Empty CourseList Test Finished" << std::endl;
}


/*
    This test initializes 3 courses: ECE310, CS225, and PHYS400
    It assigns each of these courses 1 section each, A1, A2, and A3 respectively
    There are no conflicts, so there is only one correct schedule, with every section placed
*/
TEST_CASE ( "Simple CourseList Test" )
{
    std::cout << "\n" << "Beginning Simple CourseList Test" << std::endl;

    std::string name = "ECE310";
    CourseList courseList;
    Course course1;
    course1.setCourseName( name );

    std::vector< std::string > days;
    days.push_back("M");
    days.push_back("W");
    days.push_back("F");

    CourseSection * section1a = new CourseSection( "A1", "Lec", 0, 50, days, "F", 3, course1 );
    course1.push_back( *section1a );

    Course course2;
    name = "CS225";
    course2.setCourseName( name );

    days.clear();
    days.push_back("Tu");
    days.push_back("Th");

    CourseSection * section2a = new CourseSection( "A2", "Dis", 60, 160, days, "F", 4, course2 );
    course2.push_back( *section2a );

    Course course3;
    name = "PHYS400";
    course3.setCourseName( name );

    days.clear();
    days.push_back("M");
    days.push_back("F");

    CourseSection * section3a = new CourseSection( "A3", "Lab", 160, 210, days, "F", 3, course3 );
    course3.push_back( *section3a );

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

/*
    This test initializes 1 course: ECE310
    It assigns this course 3 sections
    There are no conflicts, so there are 3 correct schedules, one for each section
    NOTE: THIS MAY CHANGE IF A CREDIT HOUR MINIMUM IS ADDED
*/
TEST_CASE ( "Simple CourseList Test 2" )
{
    std::cout << "\n" << "Beginning Simple CourseList Test 2" << std::endl;

    std::string name = "ECE310";
    CourseList courseList;
    Course course1;
    course1.setCourseName( name );

    std::vector< std::string > days;
    days.push_back("M");
    days.push_back("W");
    days.push_back("F");

    CourseSection * section1a = new CourseSection( "A1", "Lec", 0, 50, days, "F", 3, course1 );
    course1.push_back( *section1a );

    CourseSection * section3a = new CourseSection( "A3", "Lab", 160, 210, days, "F", 3, course1 );
    course1.push_back( *section3a );

    days.clear();
    days.push_back("Tu");
    days.push_back("Th");

    CourseSection * section2a = new CourseSection( "A2", "Dis", 60, 160, days, "F", 4, course1 );
    course1.push_back( *section2a );

    Schedule schedule;
    ScheduleGroup scheduleGroup;

    courseList.push_back( course1 );

    generateSchedules( courseList, 0, schedule, scheduleGroup );

    REQUIRE( scheduleGroup.getNumSchedules() == 3 );

    scheduleGroup.print();

    std::cout << "Simple CourseList Test 2 Finished" << std::endl;
}

/*
    This test initializes 3 courses: ECE310, CS225, and PHYS400
    It assigns the following sections
        ECE310: 1A (0-50) M/W/F, 1B (160-210) M/W/F
        CS225: 2A (60-160) Tu/Th, 2B (60-160) M/W
        PHYS400: 3A (160-210) M/F
    There are conflicts between the following sections
        1B and 2B, 
        2B and 3A, 
        1B and 3A
    Therefore, there is only one valid section, consisting of 1A, 2A, and 3A
*/
TEST_CASE ( "CourseList Test 1" )
{
    std::cout << "\n" << "Beginning CourseList Test 1" << std::endl;

    std::string name = "ECE310";
    CourseList courseList;
    Course course1;
    course1.setCourseName( name );

    CourseSection * section1a = new CourseSection( "1A", "Lec", 0, 50, { "M", "W", "F" }, "F", 3, course1 );
    course1.push_back( *section1a );

    CourseSection * section1b = new CourseSection( "1B", "Lec", 160, 210, { "M", "W", "F" }, "F", 3, course1 );
    course1.push_back( *section1b );

    Course course2;
    name = "CS225";
    course2.setCourseName( name );

    CourseSection * section2a = new CourseSection( "2A", "Dis", 60, 160, { "Th", "Tu" }, "F", 4, course2 );
    course2.push_back( *section2a );

    CourseSection * section2b = new CourseSection( "2B", "Dis", 60, 160, { "M", "W" }, "F", 4, course2 );
    course2.push_back( *section2b );

    Course course3;
    name = "PHYS400";
    course3.setCourseName( name );

    CourseSection * section3a = new CourseSection( "3A", "Lab", 160, 210, { "M", "F" }, "F", 3, course3 );
    course3.push_back( *section3a );

    Schedule schedule;
    ScheduleGroup scheduleGroup;

    courseList.push_back( course1 );
    courseList.push_back( course2 );
    courseList.push_back( course3 );

    generateSchedules( courseList, 0, schedule, scheduleGroup );

    REQUIRE( scheduleGroup.getNumSchedules() == 1 );
    
    scheduleGroup.print();

    std::cout << "CourseList Test 1 Finished" << std::endl;
}

TEST_CASE ( "Empty GradeListBlock Test" )
{
    std::cout << "\n" << "Beginning Empty GradeListBlock Test" << std::endl;

    GradeListBlock glb;
    glb.clear();

    std::vector< double > gradeBreakdown;
    gradeBreakdown.clear();

    REQUIRE( -1 == calculateGrade( glb, gradeBreakdown ) );

    std::cout << "Empty GradeListBlock Test Finished" << std::endl;
}

TEST_CASE ( "Simple GradeListBlock Test" )
{
    std::cout << "\n" << "Beginning Simple GradeListBlock Test" << std::endl;

    GradeListBlock glb;

    std::vector< double > gradeBreakdown = { 0.25, 0.75 };

    std::vector< double > glHW = { 92.0, 90.0, 50.0 };
    std::vector< double > glExams = { 88.0 };

    glb.push_back( glHW );
    glb.push_back( glExams );

    double dExpected = 85.33;
    double dResult = calculateGrade( glb, gradeBreakdown );

    REQUIRE( std::abs( dExpected - dResult ) < EPSILON );

    std::cout << "Simple GradeListBlock Test Finished" << std::endl;
}

TEST_CASE ( "Incorrect GradeBreakdown Test" )
{
    std::cout << "\n" << "Beginning Incorrect GradeBreakdown Test" << std::endl;

    GradeListBlock glb;

    std::vector< double > gradeBreakdown = { 0.20, 0.75 };

    std::vector< double > glHW = { 92.0, 90.0, 50.0 };
    std::vector< double > glExams = { 88.0 };

    glb.push_back( glHW );
    glb.push_back( glExams );

    double dResult = calculateGrade( glb, gradeBreakdown );

    REQUIRE( -2 == dResult );

    std::cout << "Incorrect GradeBreakdown Test Finished" << std::endl;
}