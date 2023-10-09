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

TEST_CASE( "Empty CourseList Test" )
{
    std::cout << "\n" << "Beginning Empty CourseList Test" << std::endl;

    CourseList courseList;
    Schedule schedule;
    ScheduleGroup scheduleGroup;

    generateSchedules( courseList, 0, schedule, scheduleGroup );

    REQUIRE( scheduleGroup.empty() );

    std::cout << "Empty CourseList Test Finished" << std::endl;
}

TEST_CASE( "Simple CourseList Test" )
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

TEST_CASE ( "Empty GradeListBlock Test")
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