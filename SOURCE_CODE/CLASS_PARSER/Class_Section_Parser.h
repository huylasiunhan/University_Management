#pragma once
#include <string>
#include "Class_Section.h"
using namespace std;

class ClassSectionParser {
public:
    // Parse từ CSV -> ClassSection
    static ClassSection parseFromLine(const string& csvLine);
    static vector<ClassSection> parseFromFile(const vector<string>& csvFile);
};
