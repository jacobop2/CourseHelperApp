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

void Schedule::setOverride( bool override )
{
    bNeedOverride_ = override;
}

bool Schedule::getOverride() const
{
    return bNeedOverride_;
}

int Schedule::getNumSections() const
{
    return vCourseSections_.size();
}

void Schedule::print()
{
    std::cout << "\n" << "Beginning of Schedule print, override = <" << std::to_string( bNeedOverride_ ) << ">" << "\n" << std::endl;

    for( const CourseSection & s : vCourseSections_ )
    {
        std::cout << s.getSectionCode() << ", " << s.getStartTime() << " - " << s.getEndTime() << std::endl;
    }
    std::cout << "\n" << "End of Schedule print" << "\n" << std::endl;
}

std::string Schedule::to_string()
{
    std::string rv;
    rv = rv + "\n" + "Beginning of Schedule print, override = <" + std::to_string( bNeedOverride_ ) + ">" + "\n";

        for( const std::string & weekDay : WEEKDAYS )
        {
            rv += weekDay + ": ";

            for( const CourseSection & currSection : vCourseSections_ )
            {
                for( const std::string & day : currSection.getSectionDays() )
                {
                    if( day == weekDay )
                    {
                        rv += currSection.getCourseName() + "/" + 
                        currSection.getSectionCode() + " (" +
                        timeMinutestoString12( currSection.getStartTime() ) + "-" +
                        timeMinutestoString12( currSection.getEndTime() ) + "), ";
                        // std::to_string( currSection.getStartTime() ) << "-" <<
                        // std::to_string( currSection.getEndTime() ) << "), ";
                    }

                }
            }

            rv += "\n";
        }

        rv += "NA: ";

        for( const CourseSection & currSection : vCourseSections_ )
        {
            for( const std::string & day : currSection.getSectionDays() )
            {
                if( day == "NA" )
                {
                    rv += currSection.getCourseName() + "/" + 
                    currSection.getSectionCode() + " (" + 
                    timeMinutestoString12( currSection.getStartTime() ) + "-" +
                    timeMinutestoString12( currSection.getEndTime() ) + "), ";
                }

            }
        }

    return rv;
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

std::vector<Schedule> & ScheduleGroup::getSchedules() 
{
    return vSchedules_;
}

std::string timeMinutestoString12( int time )
{
    if ( time == -2 )
        return "ARRANGED";

    // Account for time 0 being 8 am
    time += 60*8;
    int minutes = time % 60;
    
    int hours = time / 60;

    std::string sh = std::to_string( hours % 12 );
    std::string sm = std::to_string( minutes );

    if ( sm == "0" )
        sm = "00";
    
    if ( sh == "0" )
        sh = "12";

    std::string t = sh + ":" + sm + ( hours < 12 ? "AM" : "PM" );
    return t;

}

std::string timeMinutestoString24( int time )
{
    if ( time == -2 )
        return "ARRANGED";

    // Account for time 0 being 8 am
    time += 60*8;
    int minutes = time % 60;
    
    int hours = time / 60;

    std::string sh = std::to_string( hours );
    std::string sm = std::to_string( minutes );

    if ( sm == "0" )
        sm = "00";

    std::string t = sh + ":" + sm;
    return t;

}

void ScheduleGroup::print() const
{
    for( int i = 0; i < vSchedules_.size(); i++ )
    {
        std::cout << "\n" << "Schedule " << i << ": " << std::endl;

        for( const std::string & weekDay : WEEKDAYS )
        {
            std::cout << weekDay << ": ";

            for( const CourseSection & currSection : vSchedules_[i].getCourseSections() )
            {
                for( const std::string & day : currSection.getSectionDays() )
                {
                    if( day == weekDay )
                    {
                        std::cout << currSection.getCourseName() << "/" << 
                        currSection.getSectionCode() << " (" << 
                        timeMinutestoString12( currSection.getStartTime() ) << "-" <<
                        timeMinutestoString12( currSection.getEndTime() ) << "), ";
                        // std::to_string( currSection.getStartTime() ) << "-" <<
                        // std::to_string( currSection.getEndTime() ) << "), ";
                    }

                }
            }

            std::cout << std::endl;
        }
        std::cout << "NA: ";

        for( const CourseSection & currSection : vSchedules_[i].getCourseSections() )
        {
            for( const std::string & day : currSection.getSectionDays() )
            {
                if( day == "NA" )
                {
                    std::cout << currSection.getCourseName() << "/" << 
                    currSection.getSectionCode() << " (" << 
                    timeMinutestoString12( currSection.getStartTime() ) << "-" <<
                    timeMinutestoString12( currSection.getEndTime() ) << "), ";
                }

            }
        }

        std::cout << std::endl;
    }
    return;
}

// std::vector< std::string > Break::getDays() const
// {
//     return vDays_;
// }

// int Break::getStartTime() const
// {
//     return iStartTime_;
// }

// int Break::getEndTime() const
// {
//     return iEndTime_;
// }

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

// void BreakGroup::push_back( Break & b )
// {
//     vBreaks_.push_back( b );
// }

// void BreakGroup::empty()
// {
//     vBreaks_.clear();
// }

// int BreakGroup::getNumBreaks() const
// {
//     return vBreaks_.size();
// }

// std::vector< Break > & BreakGroup::getBreaks()
// {
//     return vBreaks_;
// }

bool isTimeOverlap( const CourseSection & a, const CourseSection & b )
{
    if ( ( b.getStartTime() >= a.getStartTime() && b.getStartTime() <= a.getEndTime() )
      || ( a.getStartTime() >= b.getStartTime() && a.getStartTime() <= b.getEndTime() ) )
    // if ( a.getEndTime() >= b.getStartTime() || a.getStartTime() >= b.getEndTime() )
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

void print( const CourseList & c )
{
    std::cout << "\n" << "Beginning of CourseList print" << std::endl;
    for ( const Course & course : c )
    {
        std::cout << "\n" << course.getCourseName() << std::endl;

        for ( const CourseSection & cs : course.getCourseSections() )
        {
            std::cout << cs.getSectionCode() << ", ";
        } 
    }
    std::cout << "End of CourseList print" << std::endl;
    return;
}

int timeStringtoMinutes( std::string & time )
{
    if ( time.empty() )
    {
        std::cerr << "Time string is empty, aborting conversion" << std::endl;
        return -1;
    }

    if ( "ARRANGED" == time )
    {
        return -2;
    }

    std::string meridiem = time.substr( time.size() - 2 ); // fetches AM or PM
    for( char & c : meridiem ) // convert chars to upper case
    {
        c = std::toupper( c );
    }

    if ( "AM" != meridiem && "PM" != meridiem ) // if meridiem is invalid, return error
    {
        std::cerr << "Invalid time format: " << time << std::endl;
        return -1;
    }

    std::string timeTrimmed = time.substr( 0, time.size() - 2 );

    std::vector<std::string> fields;
    if ( SplitString( timeTrimmed, ':', fields ) == 2 ) // if string successfully split into hours and minutes
    {

        int hours = stoi( fields[0] );
        int minutes = stoi( fields[1] );

        if ( hours < 0 || hours > 12 || minutes < 0 || minutes >= 60) // validating time
        {
            std::cerr << "Invalid time: " << time << std::endl;
            return -1;
        }

        if ( "AM" == meridiem )
        {
            return hours * 60 + minutes - 8*60; //  adjusting for t 0 being 8 am
        }
        else if ( "PM" == meridiem && 12 == hours )
        {
            return 240 + minutes; // adjusting for 12 hour offset
        }
        else if ( "PM" == meridiem )
        {
            return hours * 60 + minutes + 720 - 8*60; // adjusting for 12 hour offset
        }

    }
    else
    {
        std::cerr << std::to_string( fields.size()) << std::endl;
        std::cerr << "Time string " << time << " is not in the format HH:MM(AM/PM), aborting conversion" << std::endl;
        return -1;
    }

    std::cerr << "Unknown Time Conversion Error" << std::endl;
    return -1;
}

std::vector<std::string> daysStringtoVec( std::string & days )
{
    std::vector<std::string> retDays;
    std::vector<std::string> empty;
    if ( days.empty() )
    {
        std::cerr << "Days string is empty, aborting conversion" << std::endl;
        return empty;
    }

    if ( "n.a." == days )
    {
        retDays.push_back("NA");
        return retDays;
    }

    for( size_t i = 0; i < days.size(); i++ )
    {
        char c = days[i];
        c = std::toupper( c );
        if ( c == 'M')
        {
            retDays.push_back("M");
        }
        else if ( c == 'W' )
        {
            retDays.push_back("W");
        }
        else if ( c == 'F' )
        {
            retDays.push_back("F");
        }
        else if ( c == 'T' )
        {
            retDays.push_back("T");
        }
        else if ( c == 'R' )
        {
            retDays.push_back("R");
        }
        else
        {
            std::cerr << "Invalid day string " << days << std::endl;
            return empty;
        }
    }
    return retDays;
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
    // std::cout << "BEGINNING OF GENERATE SCHEDULES, index: " << std::to_string( index ) << std::endl;
    // std::cout << "ScheduleGroup size: " << scheduleGroup.getNumSchedules() << std::endl;
    //currSchedule.print();

    // std::cout << "CourseList index 8: " << courseList[3].getCourseName() << std::endl;

    // print( courseList );

    if( courseList.empty() )
    {
        // std::cout << "Empty loop, CourseList Size: " << std::to_string( courseList.size() ) << std::endl;
        return;
    }

    if( index == courseList.size() )
    {
        // std::cout << "CourseList Size: " << std::to_string( courseList.size() ) << "Index: " << std::to_string( index ) << std::endl;

        // std::cout << "Adding Schedule" << std::endl;

        scheduleGroup.push_back( currSchedule ); // otherwise, add section
        return;
    }

    //std::cout << "Reached end of return checks" << std::endl;
    //std::cout << "Size: " << std::to_string( courseList[index].getCourseSections().size() ) << std::endl;

        // Check if the current course has sections
    // if ( courseList[index].getCourseSections().empty() )
    // {
    //     // If there are no sections, move on to the next course
    //     generateSchedules(courseList, index + 1, currSchedule, scheduleGroup);
    //     return;
    // }

    for( const CourseSection & currSection : courseList[index].getCourseSections() )
    {
        // std::cout << "Inside first for loop" << std::endl;

        bool bIsConflict = false;

        // std::cout << currSection.getSectionCode() << "\n" << std::endl;

        for( const CourseSection & existingSection : currSchedule.getCourseSections() )
        {
            // std::cout << "Inside second for loop" << std::endl;
            // std::cout << "\n" << existingSection.getSectionCode() << std::endl;

            if( isConflict( existingSection, currSection ) )
            {
                // std::cout << "Conflict between: " << existingSection.getSectionCode() << ", " << currSection.getSectionCode() << std::endl;
                // std::cout << existingSection.getStartTime() << " - " << existingSection.getEndTime()  << ", " << currSection.getStartTime() << " - " << currSection.getEndTime() << std::endl;

                // std::cout << "Time overlap: " << std::to_string( isTimeOverlap( existingSection, currSection ) ) << std::endl;
                // std::cout << "Day overlap: " << std::to_string( isDayOverlap( existingSection, currSection ) ) << std::endl;


                bIsConflict = true;
                break;
            }
        }

        //std::cout << "\n" << std::to_string( bIsConflict ) << std::endl;

        if( !bIsConflict )
        {

            //std::cout << "Inside check to add" << std::endl;
            // std::cout << "Section to be added: " << currSection.getSectionCode() << std::endl;

            currSchedule.push_back( currSection );

            // currSchedule.print();
            //std::cout << "This is updated currSchedule before recursive call" << std::endl;

            generateSchedules( courseList, index + 1, currSchedule, scheduleGroup );

            //std::cout << "Returned from recursive" << std::endl;

            currSchedule.pop_back();
        }
    }
}

/*
    Arguments:
        std::vector<std::string> courseNames - vector of course names needed to make the schedule
        ScheduleGroup & bufScheduleGroup - a ScheduleGroup buffer which will be filled out by the helper function

    Returns:
        StatusCode symbolizing error status

    Purpose:
        This function takes in a list of course names and parses the csv. For every match, a new course object is created
        and the necessary sections are added. Once all course objects are finalized, the generate schedules helper is called
        which creates all possible schedules and fills them into the schedulegroup buffer.
*/

StatusCode scheduler( std::vector<std::string> courseNames, ScheduleGroup & bufScheduleGroup )
{
    if ( courseNames.empty() )
    {
        std::cerr << "CourseNames vector cannot be empty" << std::endl;
        return INVALID_COURSENAME;
    }

    CourseList courseList;
    Course course1;
    Course course2;
    Course course3;

    for ( std::string & s : courseNames )
    {
        course1.clearCourseSections();
        course2.clearCourseSections();
        course3.clearCourseSections();

        std::ifstream file("web_scraping\\ece_course_information.csv"); 

        if ( file.is_open() ) 
        { 
            bool bHasMatched = false;
            bool bValidCourseName = false;
            bool bCourseCreated = false;

            std::string line;
            while (std::getline(file, line)) { // while there are still full lines in the file

                std::vector<std::string> fields;
                SplitString(line, ',', fields); // Split lines into vector fields

                if ( s == fields[0] )
                {
                    bValidCourseName = true;
                    if ( !bHasMatched ) // if this is first time matching, make a new course object and add it to list
                    {
                        // std::cout << "Initializing Course" << std::endl;

                        course1.setCourseName( s );
                        course2.setCourseName( s );
                        course3.setCourseName( s );
                        
                        bCourseCreated = true;
                    }

                    // Otherwise, just make new section for the same course
                    if ( bCourseCreated )
                    {
                        int startTime = timeStringtoMinutes( fields[4] );
                        int endTime = timeStringtoMinutes( fields[5] ); 
                        if ( -1 == startTime || -1 == endTime )
                        {
                            return INVALID_TIME;
                        }

                        CourseSection courseSection(
                                                    fields[3],                        // section code
                                                    fields[2],                        // section type
                                                    startTime, // start time
                                                    endTime, // end time
                                                    daysStringtoVec( fields[6] ),     //change to vec, section days
                                                    "full",                           // will need to update when fetch part of semester, part of semester
                                                    std::stoi( fields[9] ),  // credit hours, removed trim
                                                    fields[8],                        // Instructor
                                                    fields[7],                        // Location
                                                    fields[0],                         // parent course name
                                                    course1                            // parent course
                                                    );

                        if ( "Lecture" == fields[2] )
                            course1.push_back( courseSection );
                        if ( "Laboratory" == fields[2] )
                            course2.push_back( courseSection );
                        if ( "Discussion/ Recitation" == fields[2] )
                            course3.push_back( courseSection );
                        // course.printCourseSections();
                    }

                    bHasMatched = true;
                }         
            }

            if ( !bValidCourseName )
            {
                return INVALID_COURSENAME;
            }

            file.close();
        }
        else 
        {
            std::cerr << "Unable to open csv file " << std::endl;
            return INVALID_FILE;
        }

        if ( !course1.getCourseSections().empty() )
            courseList.push_back( course1 );

        if ( !course2.getCourseSections().empty() ) 
            courseList.push_back( course2 );

        if ( !course3.getCourseSections().empty() )
            courseList.push_back( course3 );
    } 

    Schedule schedule;

    // std::cout << "Num Schedules Before: " << bufScheduleGroup.getNumSchedules() << std::endl;

    // print(courseList);

    // courseList[4].printCourseSections();
    // std::cout << std::endl;

    generateSchedules( courseList, 0, schedule, bufScheduleGroup );

    // std::cout << "Num Schedules After: " << bufScheduleGroup.getNumSchedules() << std::endl;

    for ( Schedule & s : bufScheduleGroup.getSchedules() ) // check for hour override
    {
        // s.print();
        int hours = s.getSumCreditHours();

        // std::cout << std::to_string(hours) << std::endl;
        if ( hours < 12 || hours > 18 )
        {
            s.setOverride( true );
            // std::cout << "setting override" << std::endl;
        }
    }

    return SUCCESS;
}
