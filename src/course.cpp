#include "course.h"

int CourseSection::getStartTime()
{
    return iStartTime;
}

int CourseSection::getEndTime()
{
    return iEndTime;
}

int CourseSection::getCreditHours()
{
    return iCreditHours;
}

std::vector< std::string > CourseSection::getSectionDays()
{
    return vSectionDays;
}