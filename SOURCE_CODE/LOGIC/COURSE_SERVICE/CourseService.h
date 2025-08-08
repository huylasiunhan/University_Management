#pragma once
#include "ICourseService.h"
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

    // Lấy toàn bộ danh sách khóa học
    vector<Course> getCourses() const override;

    // Triển khai các hàm từ interface
    bool addCourse(const Course& course) override;
    bool removeCourse(const string& courseId) override;
    optional<Course> getCourseById(const string& courseId) const override;
    bool isCoursePassed(const string& studentId, const string& courseId) const override;
    optional<double> getCourseAverage(const string& courseId) const override;
    bool updateCourse(const Course& course) override; // Method to update course details
    vector<Course> getCoursesByMajor(const string& majorId) const override; // Get courses by major ID
    vector<Course> getCoursesByClassSection(const string& classSectionId) const override; // Get courses by class section ID
};