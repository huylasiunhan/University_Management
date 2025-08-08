#pragma once
#include <memory>
#include <optional>
#include <string>
#include "Student.h"
#include "MajorRequirement.h"
#include "Course.h"

class IMajorService {
public:
    virtual std::optional<std::string> getGraduationEligibility(const Student& studentId) const = 0;
    virtual std::vector<Course> getRemainingCourses(const Student& studentId) const = 0;
    virtual double calculateGPA(const Student& studentId) const = 0;
    virtual int getTotalCredits(const Student& studentId) const = 0;
    virtual std::string classifyDegree(double gpa) const = 0;

    virtual std::vector<Course> getRequiredCourses(const Major& majorId) const = 0;
    virtual std::vector<Course> getElectiveCourses(const Major& majorId) const = 0;

    virtual const Major& getMajorInfo(const Major& majorId) const = 0;
    virtual std::vector<Student> getStudentsInMajor(const Major& majorId) const = 0;

    virtual void assignStudentToMajor(const Student& studentId, const Major& majorId) = 0;
    virtual void removeStudentFromMajor(const Student& studentId) = 0;

    virtual void updateMajorInfo(const Major& majorId, const Major& updated) = 0;
    virtual void addNewMajor(const Major& newMajor) = 0;
    virtual void deleteMajor(const Major& majorId) = 0;

    virtual ~IMajorService() = default;
};