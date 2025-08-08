#include "Major.h"
#include "ParserCourse.h"
#include <iostream>
#include <memory>

Major::Major(const string& name, const vector<shared_ptr<Course>>& courses) : name(name), courses(courses) {}

string Major::getName() const {
    return name;
}

vector<shared_ptr<Course>> Major::getCourses() const {
    return courses;
}

void Major::setName(const string& name) {
    this->name = name;
}

void Major::setCourses(const vector<shared_ptr<Course>>& courses) {
    this->courses = courses;
}

void Major::addCourse(const shared_ptr<Course>& course) {
    courses.push_back(course);
}

void Major::removeCourse(const string& courseId) {
    auto it = remove_if(courses.begin(), courses.end(), [&](const shared_ptr<Course>& course) {
        return course->getId() == courseId;
    });
    if (it != courses.end()) {
        courses.erase(it, courses.end());
    }   
}

bool Major::isGraduate() {
    float graduateScore = 0; 
    return graduateScore >= 2.0; // Assuming 2.0 is the passing score
}

float Major::graduateScore() {
    // Placeholder logic for calculating graduation score
    float totalScore = 0.0;
    for (const auto& course : courses) {
        // Assuming each course has a method to get its score
        totalScore += course->getAverageScore(); // This method should be defined in Course class
    }
    return totalScore / courses.size();
}

// Friend class for parsing
shared_ptr<Major> ParserMajor::parseFromString(const string& line, const vector<shared_ptr<Course>>& allCourses) {
    stringstream ss(line);
    string name;
    getline(ss, name, ',');
    
    vector<shared_ptr<Course>> majorCourses;
    string courseId;
    while (getline(ss, courseId, ';')) {
        for (const auto& course : allCourses) {
            if (course->getId() == courseId) {
                majorCourses.push_back(course);
                break;
            }
        }
    }
    
    return make_shared<Major>(name, majorCourses);
}

vector<shared_ptr<Major>> ParserMajor::parseFromFile(const string& filename, const vector<shared_ptr<Course>>& allCourses) {
    vector<shared_ptr<Major>> majors;
    vector<string> lines = FileManaging::readLinesFromFile(filename);
    
    for (const auto& line : lines) {
        shared_ptr<Major> major = parseFromString(line, allCourses);
        if (major) {
            majors.push_back(major);
        }
    }
    
    return majors;
}
// Destructor
Major::~Major() {
    // Destructor logic if needed
}
