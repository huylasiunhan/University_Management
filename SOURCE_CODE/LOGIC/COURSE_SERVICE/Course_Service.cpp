#include "Course_Service.h"
#include "Course.h"
#include <vector>

using namespace std;
CourseService::CourseService(const vector<Course>& courses) {
    _courses.reserve(courses.size());
    for (const auto& course : courses) {
        _courses.push_back(course);
    }
}
vector<Course> CourseService::getCourses() const {
    return _courses;    
}
bool CourseService::addCourse(const Course& course){
    for (const auto& existingCourse : _courses) {
        if (existingCourse.getId() == course.getId()) {
            return false;
        }
    }
    _courses.push_back(course);
    return true;
}
bool CourseService::removeCourse(const std::string& courseId) {
    for (auto it = _courses.begin(); it != _courses.end(); ++it) {
        if (it->getId() == courseId) {
            _courses.erase(it);
            return true;
        }
    }
    return false;
}
optional<Course> CourseService::getCourseById(const string& courseId) const{
    for (const auto& course : _courses) {
        if (course.getId() == courseId) {
            return course;
        }
    }
    return nullopt;
}
