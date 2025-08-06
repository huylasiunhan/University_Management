#include "Course.h"
#include "FileManaging.h"
#include "stringUtils.h"
#include <utility>
#include <vector>
#include <string>
using namespace std;

#include <sstream>

Course::Course() : _majorId(""), _id(""), _name(""), _classSectionIds({}) {}

Course::Course(const string& majorId, const string& id, 
               const string& name, const vector<string>& classSectionIds)
    : _majorId(majorId), _id(id), _name(name), _classSectionIds(classSectionIds) {}

string Course::getMajorId() const { return _majorId; }
string Course::getId() const { return _id; }
string Course::getName() const { return _name; }
vector<string> Course::getClassSectionIds() const { return _classSectionIds; }

void Course::setMajorId(const string& majorId) { _majorId = majorId; }
void Course::setId(const string& id) { _id = id; }
void Course::setName(const string& name) { _name = name; }
void Course::setClassSectionIds(const vector<string>& classSectionIds) {
    _classSectionIds = classSectionIds;
}

Course::~Course() {}



Course CourseParser::parseFromLine(const string& line) {
    stringstream ss(line);
    string majorId, id, name, classSectionStr;

    getline(ss, majorId, ',');
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, classSectionStr);

    vector<string> classSections = split(classSectionStr, ';');

    return Course(majorId, id, name, classSections);
}


vector<Course> ParserCourse::parseFromFile(const string& filename) {
    FileManager fm;
    vector<string> lines = fm.fileReader(filename);
    vector<Course> courses;

    for (const auto& line : lines) {
        Course course = parseFromLine(line);
        courses.push_back(course);
    }

    return courses;
}       
