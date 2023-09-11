#pragma once

#include <string>
#include <vector>

class CourseSection
{
    public:

        int getStartTime();
        int getEndTime();
        int getCreditHours();

        std::vector< std::string > getSectionDays();

    private:

        std::string szSectionCode;
        std::string szSectionType;
        int iStartTime;
        int iEndTime
        std::vector< std::string > vSectionDays;

        int iSections;
        int iCreditHours;

}

class Course 
{
    public:
    private:

        int iLength;
        std::vector< CourseSection > vCourseSections;

}