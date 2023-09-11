#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <set>

bool isTimeOverlap( CourseSection a, CourseSection b );

bool isDayOverlap( CourseSection a, CourseSection b );

std::vector< CourseSection > assignSchedule( std::vector< std::string > courseList );