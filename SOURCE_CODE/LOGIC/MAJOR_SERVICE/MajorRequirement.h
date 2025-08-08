#pragma once
#include <string>
#include <vector>

//ON GOING [H + CPP]

class MajorRequirement {
private:
    std::string majorId;
    int totalCreditsRequired;
    std::vector<std::string> mandatoryCourses;
    double minGPA;

public:
    MajorRequirement(const std::string& id, int credits, const std::vector<std::string>& courses, double gpa)
        : majorId(id), totalCreditsRequired(credits), mandatoryCourses(courses), minGPA(gpa) {}

    const std::string& getId() const { return majorId; }
    int getTotalCreditsRequired() const { return totalCreditsRequired; }
    const std::vector<std::string>& getMandatoryCourses() const { return mandatoryCourses; }
    double getMinGPA() const { return minGPA; }
    bool isCourseMandatory(const std::string& courseId) const {
        return std::find(mandatoryCourses.begin(), mandatoryCourses.end(), courseId) != mandatoryCourses.end();
    }
};