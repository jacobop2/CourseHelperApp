//
//  TestCPP.hpp
//  ECE397-Project
//
//  Created by Meredith Naylor on 11/15/23.
//

#ifndef TestCpp_hpp
#define TestCpp_hpp
//#include "string"
//#include <stdio.h>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <map>
#include "course.hpp"
#include "course_schedule.hpp"


#ifdef __cplusplus
// extern "C" {
#endif

typedef std::vector < double > GradeList;
typedef std::vector < GradeList > GradeListBlock;
struct ClassInfo {
    std::string description;
    std::string gpa;
    std::string creditHours;
    std::string courseName;
    std::string gen;
    std::string pre;
    ClassInfo(const std::string& d, const std::string& v, const std::string& ch, const std::string& cn, const std::string& g, const std::string& p) : description(d), gpa(v), creditHours(ch), courseName(cn), gen(g), pre(p){}
};


//initalization of cppFunc this is a test function for the cpp background
double cppFunc();
//std::vector<double> getVector();

//static TestClass* _pClass = NULL;
static std::map<std::string, ClassInfo> *courseMap = NULL;
static GradeListBlock* _pGradeListBlock = NULL;
static std::vector < double > * _pGradeBreakdown = NULL;
static std::vector < double > * _pTempGradeList = NULL;
static std::vector < std::string > *_pTempCourseList = NULL;

//for schedule generator
static int *_schedule_idx = 0;
static std::vector < Schedule > * _schedules = NULL;
static std::string *_schedule = NULL;


static std::string * _fpath = NULL;
void CppInit(const char* fpath);
void AddCategory(double dWeight);
void AddGradeToCategory(double dGrade);
void CompleteCategory();
double GetGrade();
const char* getName(const char* courseName);
const char* getCreditHours(const char* courseName);
const char* getAvgGPA(const char* courseName);
const char* getPre(const char* courseName);
const char* getGen(const char* courseName);
const char* getDescription(const char* courseName);
void AddCourse(const char* course);
const char* getSchedules();
const char* getScheduleNext();
const char* getScheduleBack();
void clearScheduleInfo();

#ifdef __cplusplus
// }
#endif


#endif /* TestCpp_hpp */
