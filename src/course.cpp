#include "../include/course.h"

int CourseSection::getStartTime() const
{
    return iStartTime;
}

int CourseSection::getEndTime() const
{
    return iEndTime;
}

int CourseSection::getCreditHours() const
{
    return iCreditHours;
}

std::vector< std::string > CourseSection::getSectionDays() const
{
    return vSectionDays;
}

std::vector< CourseSection > Course::getCourseSections() const
{
    return vCourseSections;
}