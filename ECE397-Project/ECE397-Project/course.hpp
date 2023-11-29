//
//  course.hpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/24/23.
//

#ifndef course_hpp
#define course_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

class Course;

class CourseSection
{
    public:

        CourseSection( std::string szSectionCode, std::string szSectionType, int iStartTime,
                       int iEndTime, std::vector< std::string > vSectionDays, std::string szPartOfSemester,
                       int iCreditHours, std::string szInstructor, std::string szLocation, std::string szCourseName,
                       Course & course ) :

                        szSectionCode_ ( szSectionCode ),
                        szSectionType_ ( szSectionType ),
                        iStartTime_ ( iStartTime ),
                        iEndTime_ ( iEndTime ),
                        vSectionDays_ ( vSectionDays ),
                        szPartOfSemester_ ( szPartOfSemester ),
                        iCreditHours_ ( iCreditHours ),
                        szInstructor_ ( szInstructor ),
                        szLocation_ ( szLocation ),
                        szCourseName_ ( szCourseName ),
                        course_ ( course ) {}

        int getStartTime() const;
        int getEndTime() const;
        int getCreditHours() const;
        void print() const;

        std::string getSectionCode() const;
        std::string getCourseName() const;

        std::vector< std::string > getSectionDays() const;

        Course & getCourse() const;

    private:

        std::string szSectionCode_;
        std::string szSectionType_;
        int iStartTime_;
        int iEndTime_;
        std::vector< std::string > vSectionDays_;
        std::string szPartOfSemester_;
        int iCreditHours_;

        std::string szInstructor_;
        std::string szLocation_;

        std::string szCourseName_;

        Course & course_;

};

class Course
{
    public:

        Course() : szCourseName_(), vCourseSections_() {}

        Course( std::string szCourseName, std::vector<CourseSection> vCourseSections ) :

                szCourseName_ ( szCourseName ),
                vCourseSections_ ( vCourseSections ){}

        std::vector< CourseSection > getCourseSections() const;
        std::string getCourseName() const;

        void setCourseName( std::string & name );

        void push_back( CourseSection & cs );

        void printCourseSections();

        void clearCourseSections();

    private:

        std::string szCourseName_;
        std::vector< CourseSection > vCourseSections_;

};

#ifdef __cplusplus
}
#endif



#endif /* course_hpp */
