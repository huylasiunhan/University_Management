#pragma once
#include "I_Course_Service.h"
#include "Course.h"
#include <vector>
#include <optional>
using namespace std;
class CourseService : public ICourseService {
private:
    vector<Course> _courses;
    

public:
    CourseService() = default;
    explicit CourseService(const vector<Course>& courses);
    vector<Course> getCourses() const;
    bool addCourse(const Course& course) override;
    bool removeCourse(const string& courseId) override;
    optional<Course> getCourseById(const string& courseId) const override;
    // bool isCoursePassed(const string& studentId, const string& courseId) const override;
    // optional<double> getCourseAverage(const string& courseId) const override;
};
