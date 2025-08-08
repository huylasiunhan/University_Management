#pragma once
#include <string>
#include <optional>
#include "Course.h"

using namespace std;
class ICourseService {
public:
    virtual ~ICourseService() = default;

    virtual bool addCourse(const Course& course) = 0; // Add a new course
    virtual bool removeCourse(const string& courseId) = 0; // Remove a course by ID
    virtual bool isCoursePassed(const string& studentId, const string& courseId) const = 0; // Check if a student has passed a course
    virtual optional<double> getCourseAverage(const string& courseId) const = 0;  // Get the average score for a course
    virtual vector<Course> getCourses() const = 0; // Get all courses
    virtual bool updateCourse(const Course& course) = 0; // Method to update course details
    virtual optional<Course> getCourseById(const string& courseId) const = 0; // Get a course by ID
    virtual vector<Course> getCoursesByMajor(const string& majorId) const = 0; // Get courses by major ID
    virtual vector<Course> getCoursesByClassSection(const string& classSectionId) const = 0; // Get courses by class section ID
    
}
