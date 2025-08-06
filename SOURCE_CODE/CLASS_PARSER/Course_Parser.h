#pragma once
#include <string>
#include "Course.h"
using namespace std;

class CourseParser {
public:
    // Parse từ CSV -> Course
    static Course parseFromCSV(const string& csvLine);
    static vector<Course> parseFromFile(const vector<string>& csvFile);
};
