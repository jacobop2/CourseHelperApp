#pragma once

#include <string>
#include <vector>

class CourseSection
{
    public:

        int getStartTime() const;
        int getEndTime() const;
        int getCreditHours() const;

        std::vector< std::string > getSectionDays() const;

    private:

        std::string szSectionCode;
        std::string szSectionType;
        int iStartTime;
        int iEndTime;
        std::vector< std::string > vSectionDays;

        int iSections;
        int iCreditHours;

};

class Course 
{
    public:
        std::vector< CourseSection > getCourseSections() const;

    private:

        int iLength;
        std::string szCourseName;
        std::vector< CourseSection > vCourseSections;

};