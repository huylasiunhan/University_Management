#include "Course.h"
#include "Major.h"
#include "ClassSection.h"
#include "FileManaging.h"
#include "ParserMajor.h"
#include "ParserClassSection.h"
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <iostream> 
using namespace std;


Course::Course() : _id(""), _name("") {}

Course::Course(const string& id, const string& name, const vector<shared_ptr<Major>>& majorId,
               const vector<shared_ptr<ClassSection>>& classSectionIds)
    : _id(id), _name(name), _majorId(majorId), _classSectionIds(classSectionIds) {}
    
string Course::getId() const {
    return _id;
}
string Course::getName() const {
    return _name;
}

vector<shared_ptr<Major>> Course::getMajorId() const {
    return _majorId;
}

vector<shared_ptr<ClassSection>> Course::getClassSectionIds() const {
    return _classSectionIds;
}

void Course::setId(const string& id) {
    _id = id;
}

void Course::setName(const string& name) {
    _name = name;
}

void Course::setMajorId(const vector<shared_ptr<Major>>& majorId) {
    _majorId = majorId;
}

void Course::setClassSectionIds(const vector<shared_ptr<ClassSection>>& classSectionIds) {
    _classSectionIds = classSectionIds;
}

void Course::addClass(shared_ptr<ClassSection> classSection) {
    _classSectionIds.push_back(classSection);
}

void Course::removeClass(const shared_ptr<ClassSection>& classSection) {
    auto it = remove_if(_classSectionIds.begin(), _classSectionIds.end(),
                        [&](const shared_ptr<ClassSection>& cs) { return cs->getClassID() == classSection->getClassID(); });
    if (it != _classSectionIds.end()) {
        _classSectionIds.erase(it, _classSectionIds.end());
    }
}

float Course::getCourseScore(const shared_ptr<Student>& student) const {
    // Placeholder logic for getting course score for a student
    return 0.0; // This should be replaced with actual logic
}

bool Course::isPass(const shared_ptr<Student>& student) const {
    // Placeholder logic for checking if a student has passed the course
    return false; // This should be replaced with actual logic
}

// function to split a string by a delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


shared_ptr<Course> ParserCourse::parseFromString(const string& line,
                                                  const vector<shared_ptr<Major>>& allMajors,
                                                  const vector<shared_ptr<ClassSection>>& allClassSections) {
    stringstream ss(line);
    string majorID, id, name, classSectionID;
    
    getline(ss, majorID, ',');
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, classSectionID);
                                                    
    // Split majorID by comma and find corresponding Major objects
    vector<string> majorToken;
    stringstream majorStream(majorID);
    string token;
    vector<shared_ptr<Major>> majorNames;

    while (getline(majorStream, token, ';')) {
        majorToken.push_back(token);
    }

    // Find Major objects by ID
    for (const auto& tokenID : majorToken) {
        for (const auto& major : allMajors) {
            if (major->getId() == tokenID) {
                majorNames.push_back(major);
                break;
            }
        }
    }

    // Split classSectionID by comma and find corresponding ClassSection objects
    vector<string> classSectionToken;
    stringstream classSectionStream(classSectionID);
    vector<shared_ptr<ClassSection>> classSections;

    while (getline(classSectionStream, token, ';')) {
        classSectionToken.push_back(token);
    }

    // Find ClassSection objects by ID
    for (const auto& tokenID : classSectionToken) {
        for (const auto& section : allClassSections) {
            if (section->getClassID() == tokenID) {
                classSections.push_back(section);
                break;
            }
        }
    }

    // Create and return a new Course object
    if (majorNames.empty() || classSections.empty()) {
        return nullptr; // Handle case where no valid majors or class sections found
    }
    return make_shared<Course>(id, name, majorNames, classSections);
}

vector<shared_ptr<Course>> ParserCourse::parseFromFile(const string& filename,
                                                        const vector<shared_ptr<Major>>& allMajors,
                                                        const vector<shared_ptr<ClassSection>>& allClassSections) {
    vector<shared_ptr<Course>> courses;
    vector<string> lines = FileManaging::readLinesFromFile(filename);
    
    for (const auto& line : lines) {
        shared_ptr<Course> course = parseFromString(line, allMajors, allClassSections);
        if (course) {
            courses.push_back(course);
        }
    }
    
    return courses;
}