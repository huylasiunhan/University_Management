#include "ClassSection.h"
#include "FileManaging.h"
#include "StringUtils.h"
#include <sstream>
#include <utility>
#include <vector>
#include <string>

using namespace std;   

ClassSection::ClassSection() : _id(""), _courseId(""), _teacherId(""), _scoreId(""), _scheduleIndex({0, 0}), _studentIds({}) {}

ClassSection::ClassSection(const string& id, const string& courseId,
                           const string& teacherId, const string& scoreId,
                           const pair<int,int>& scheduleIndex,
                           const vector<string>& studentIds)
    : _id(id), _courseId(courseId), _teacherId(teacherId), _scoreId(scoreId),
      _scheduleIndex(scheduleIndex), _studentIds(studentIds) {}

string ClassSection::getId() const { return _id; }
string ClassSection::getCourseId() const { return _courseId; }
string ClassSection::getTeacherId() const { return _teacherId; }
string ClassSection::getScoreId() const { return _scoreId; }
pair<int,int> ClassSection::getScheduleIndex() const { return _scheduleIndex; }
vector<string> ClassSection::getStudentIds() const { return _studentIds; }

void ClassSection::setId(const string& id) { _id = id; }
void ClassSection::setCourseId(const string& courseId) { _courseId = courseId; }
void ClassSection::setTeacherId(const string& teacherId) { _teacherId = teacherId; }
void ClassSection::setScoreId(const string& scoreId) { _scoreId = scoreId; }
void ClassSection::setScheduleIndex(const pair<int,int>& scheduleIndex) {
    _scheduleIndex = scheduleIndex;
}
void ClassSection::setStudentIds(const vector<string>& studentIds) {
    _studentIds = studentIds;
}

ClassSection::~ClassSection() {}        

static pair<int,int> parseScheduleIndex(const string& scheduleStr) {
    stringstream ss(scheduleStr);
    string rowStr, colStr;
    getline(ss, rowStr, ',');
    getline(ss, colStr, ',');
    return {stoi(rowStr), stoi(colStr)};
}

ClassSection ClassSectionParser::parseFromLine(const string& line) {
    stringstream ss(line);
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


vector<ClassSection> ParserClassSection::parseFromFile(const string& filename) {
    FileManager fm;
    vector<string> lines = fm.fileReader(filename);
    vector<ClassSection> classSections;

    for (const auto& line : lines) {
        ClassSection classSection = parseFromLine(line);
        classSections.push_back(classSection);
    }
    return classSections;
}