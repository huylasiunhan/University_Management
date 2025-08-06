#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include <memory>
#include "IMajorService.h"
#include "Major.h"
#include "Student.h"
#include "Course.h"

class MajorService : public IMajorService {
private:
    std::unordered_map<std::string, Major> _majors;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Student>>> _studentsByMajor;

public:
    //std::optional<std::string> getGraduationEligibility(const Student& studentId) const override;
    std::vector<Course> getRemainingCourses(const std::shared_ptr<Student>& student) const override;
    double calculateGPA(const std::shared_ptr<Student>& student) const override;
    int getTotalCredits(const std::shared_ptr<Student>& student) const override;
    std::string classifyDegree(double gpa) const override;

    std::vector<Course> getRequiredCourses(const Major& majorId) const override;
    std::vector<Course> getElectiveCourses(const Major& majorId) const override;
    const Major& getMajorInfo(const Major& majorId) const override;
    std::vector<Student> getStudentsInMajor(const Major& majorId) const override;

    void assignStudentToMajor(const Student& studentId, const Major& majorId) override;
    void removeStudentFromMajor(const std::shared_ptr<Student>& student) override;
    void updateMajorInfo(const Major& majorId, const Major& updated) override;
    void addNewMajor(const Major& newMajor) override;
    void deleteMajor(const Major& majorId) override;
};
