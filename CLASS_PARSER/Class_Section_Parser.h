#pragma once
#include <string>
#include "Class_Section.h"
using namespace std;

class ClassSectionParser {
public:
    // Parse từ CSV -> ClassSection
    static ClassSection parseFromCSV(const string& csvLine);
};
