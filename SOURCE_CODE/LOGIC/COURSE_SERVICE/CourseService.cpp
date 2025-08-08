#include "CourseService.h"
#include "Course.h"
#include <vector>

CourseService::CourseService(const vector<Course>& courses) {
    _courses.reserve(courses.size());
    for (const auto& course : courses) {
        _courses.push_back(course);
    }
}

vector<Course> CourseService::getCourses() const {
    return _courses;
}

bool CourseService::addCourse(const Course& course) {
    for (const auto& c : _courses) {
        if (c.getId() == course.getId()) {
            return false; // Course already exists
        }
    }
    _courses.push_back(course);
    return true;
}

bool CourseService::removeCourse(const string& courseId) {
    for (auto it = _courses.begin(); it != _courses.end(); ++it) {
        if (it->getId() == courseId) {
            _courses.erase(it);
            return true;
        }
    }
    return false;
}

optional<Course> CourseService::getCourseById(const string& courseId) const {
    for (const auto& course : _courses) {
        if (course.getId() == courseId) {
            return course;
        }
    }
    return nullopt; // Course not found
}

bool CourseService::isCoursePassed(const string& studentId, const string& courseId) const {
    // Implementation for checking if a student has passed a course
    // This is a placeholder; actual implementation would depend on the score system
    return false; // Default to false for now
}

optional<double> CourseService::getCourseAverage(const string& courseId) const {
    // Implementation for calculating the average score of a course
    // This is a placeholder; actual implementation would depend on the score system
    return nullopt; // Default to nullopt for now
}

bool CourseService::updateCourse(const Course& course) {
    for (auto& c : _courses) {
        if (c.getId() == course.getId()) {
            c = course; // Update existing course
            return true;
        }
    }   
    return false; // Course not found
}

vector<Course> CourseService::getCoursesByMajor(const string& majorId) const {
    vector<Course> result;
    for (const auto& course : _courses) {
        for (const auto& major : course.getMajorId()) {
            if (major->getId() == majorId) {
                result.push_back(course);
                break; // No need to check other majors for this course
            }
        }
    }
    return result;
}

vector<Course> CourseService::getCoursesByClassSection(const string& classSectionId) const {
    vector<Course> result;
    for (const auto& course : _courses) {
        for (const auto& section : course.getClassSectionIds()) {
            if (section->getClassID() == classSectionId) {
                result.push_back(course);
                break; // No need to check other sections for this course
            }
        }
    }
    return result;
}       
        