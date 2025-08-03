#pragma once
#include <string>
#include <optional>
#include "Course.h"

using namespace std;
class ICourseService {
public:
    virtual ~ICourseService() = default;

    virtual bool addCourse(const Course& course) = 0;
    virtual bool removeCourse(const string& courseId) = 0;
    virtual optional<Course> getCourseById(const string& courseId) const = 0;
};
