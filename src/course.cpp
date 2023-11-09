#include "../include/course.h"

int CourseSection::getStartTime() const
{
    return iStartTime_;
}

int CourseSection::getEndTime() const
{
    return iEndTime_;
}

int CourseSection::getCreditHours() const
{
    return iCreditHours_;
}

std::string CourseSection::getSectionCode() const
{   
    return szSectionCode_;
}

std::vector< std::string > CourseSection::getSectionDays() const
{
    return vSectionDays_;
}

Course & CourseSection::getCourse() const
{
    return course_;
}

void CourseSection::print() const
{
    std::cout << "Printing Course Section: \n";
    std::cout << szSectionCode_ << " " << szSectionType_ << " " << szInstructor_ << " " << course_.getCourseName() << std::endl;
    std::cout << "Print Complete" << std::endl;
}


std::vector< CourseSection > Course::getCourseSections() const
{
    return vCourseSections_;
}

std::string Course::getCourseName() const
{
    return szCourseName_;
}

void Course::push_back( CourseSection & cs )
{
    vCourseSections_.push_back( cs );
}

void Course::setCourseName( std::string & name ) 
{
    szCourseName_ = name;
}