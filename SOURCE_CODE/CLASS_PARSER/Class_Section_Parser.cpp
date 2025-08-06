#include "Class_Section_Parser.h"
#include "String_Utils.h"
#include <sstream>
#include <vector>

static pair<int,int> parseScheduleIndex(const string& scheduleStr) {
    stringstream ss(scheduleStr);
    string rowStr, colStr;
    getline(ss, rowStr, ',');
    getline(ss, colStr, ',');
    return {stoi(rowStr), stoi(colStr)};
}

ClassSection ClassSectionParser::parseFromLine(const string& csvLine) {
    stringstream ss(csvLine);
    string id, courseId, teacherId, scoreId, scheduleStr, studentsStr;

    getline(ss, id, ',');
    getline(ss, courseId, ',');
    getline(ss, teacherId, ',');
    getline(ss, scoreId, ',');
    getline(ss, scheduleStr, ',');
    getline(ss, studentsStr);

    vector<string> students = split(studentsStr, ';');
    pair<int,int> schedule = parseScheduleIndex(scheduleStr);

    return ClassSection(id, courseId, teacherId, scoreId, schedule, students);
}
vector<ClassSection> ClassSectionParser::parseFromFile(const vector<string>& csvFile) {
    vector<ClassSection> classSections;
    for (const auto& line : csvFile) {
        classSections.push_back(parseFromLine(line));
    }
    return classSections;
}
