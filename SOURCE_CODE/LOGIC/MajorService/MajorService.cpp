#include "MajorService.h"

//ON GOING
std::optional<std::string> MajorService::checkGraduationStatus(const std::shared_ptr<Student>& student) {
    if (!student->hasCompletedRequiredCourses()) return std::nullopt;
    double gpa = student->calculateGPA();
    if (gpa >= 3.6) return "Giỏi";
    else if (gpa >= 3.0) return "Khá";
    else return "Trung bình";
}