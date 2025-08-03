#pragma once
#include "IMajorService.h"
#include <unordered_map>

class MajorService : public IMajorService {
    std::unordered_map<std::string, MajorRequirement> majorMap;

public:
    MajorService(); // load majorMap từ file/json/mock

    std::optional<std::string> checkGraduationStatus(std::shared_ptr<Student> student) override;
    std::vector<std::string> getRemainingCourses(std::shared_ptr<Student> student) override;
    double calculateGPA(std::shared_ptr<Student> student) override;
    int totalCredits(std::shared_ptr<Student> student) override;
    std::string classifyDegree(double gpa) override;
    const MajorRequirement& getRequirements(const std::string& majorId) const override;
};