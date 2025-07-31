#include "Course_Parser.h"
#include "String_Utils.h"
#include <sstream>
#include <vector>

Course CourseParser::parseFromCSV(const string& csvLine) {
    stringstream ss(csvLine);
    string majorId, id, name, classSectionStr;

    getline(ss, majorId, ',');
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, classSectionStr);

    vector<string> classSections = split(classSectionStr, ';');

    return Course(majorId, id, name, classSections);
}
