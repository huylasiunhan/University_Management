#include "MajorService.h"
#include <algorithm>
#include <numeric>

std::vector<Course> MajorService::getRemainingCourses(const std::shared_ptr<Student>& student) const {
    if (!student) return {};

    auto majorPtr = student->getMajor();
    if (!majorPtr) return {};

    const auto& completed = student->getScores(); // std::vector<Score*>
    const auto& requiredCourses = majorPtr->getCourses(); // std::vector<std::shared_ptr<Course>>

    std::vector<Course> remaining;

    for (const auto& coursePtr : requiredCourses) {
        if (!coursePtr) continue;

        const Course& course = *coursePtr;
        bool passed = false;

        for (const auto& scorePtr : completed) {
            if (!scorePtr) continue;

            ClassSection* section = scorePtr->getSection();
            if (!section) continue;

            std::shared_ptr<Course> enrolledCourse = section->getCourse();
            if (!enrolledCourse) continue;

            if (enrolledCourse->getCourseID() == course.getCourseID() &&
                course.isPass(scorePtr->getTotal())) {
                passed = true;
                break;
            }
        }

        if (!passed) {
            remaining.push_back(course); // copy Course object
        }
    }

    return remaining;
}

double MajorService::calculateGPA(const std::shared_ptr<Student>& student) const {
    if (!student) return 0.0;

    const auto& scores = student->getScores(); 
    if (scores.empty()) return 0.0;

    double total = 0.0;
    for (const auto& score : scores) {
        if (score) {
            total += score->getTotal();
        }
    }

    return total / scores.size();
}

//chưa có getCredit method trong Course class
/*
int MajorService::getTotalCredits(const Student& studentId) const {
    const auto& scores = studentId.getScores(); // vector<Score*>
    int total = 0;

    for (const auto& scorePtr : scores) {
        if (!scorePtr) continue;

        ClassSection* section = scorePtr->getSection();
        if (!section) continue;

        auto coursePtr = section->getCourse();
        if (!coursePtr) continue;

        if (coursePtr->isPass(scorePtr->getTotal())) {
            total += coursePtr->getCredit();
        }
    }

    return total;
}
*/

std::string MajorService::classifyDegree(double gpa) const {
    if (gpa >= 9.0) return "Excellent";
    if (gpa >= 8.0) return "Good";
    if (gpa >= 6.5) return "Average";
    return "Weak";
}

//xóa getRequiredCourses tạm thời 
/*
std::vector<Course> MajorService::getRequiredCourses(const Major& majorId) const {
    // Giả sử các course đầu danh sách là bắt buộc (tuỳ logic cụ thể)
    std::vector<Course> result;
    for (const auto& course : majorId.getCourses()) {
        if (course.isRequired()) result.push_back(course); // giả sử isRequired() có
    }
    return result;
}
*/

//xóa getElectiveCourses tạm thời
/*
std::vector<Course> MajorService::getElectiveCourses(const Major& majorId) const {
    std::vector<Course> result;
    for (const auto& course : majorId.getCourses()) {
        if (!course.isRequired()) result.push_back(course);
    }
    return result;
}
*/


const Major& MajorService::getMajorInfo(const Major& majorId) const {
    return _majors.at(majorId.getName());
}

std::vector<Student> MajorService::getStudentsInMajor(const Major& majorId) const {
    std::vector<Student> result;
    auto it = _studentsByMajor.find(majorId.getName());
    if (it != _studentsByMajor.end()) {
        for (const auto& sptr : it->second) {
            result.push_back(*sptr);
        }
    }
    return result;
}

/*
void MajorService::assignStudentToMajor(const std::shared_ptr<Student>& student, const std::shared_ptr<Major>& major) {
    // Gán chuyên ngành cho sinh viên
    student->setMajor(major);

    // Thêm sinh viên vào danh sách của chuyên ngành đó
    _studentsByMajor[major->getName()].push_back(student);
}
*/

void MajorService::removeStudentFromMajor(const std::shared_ptr<Student>& student) {
    auto majorPtr = student->getMajor();
    if (!majorPtr) return;

    std::string majorName = majorPtr->getName();

    // Gỡ khỏi danh sách theo major
    auto& list = _studentsByMajor[majorName];
    list.erase(std::remove_if(list.begin(), list.end(),
        [&](const std::shared_ptr<Student>& s) {
            return s->getName() == student->getName();
        }), list.end());

    // Gán nullptr
    student->setMajor(nullptr);
}


void MajorService::updateMajorInfo(const Major& majorId, const Major& updated) {
    _majors[majorId.getName()] = updated;
}

void MajorService::addNewMajor(const Major& newMajor) {
    _majors[newMajor.getName()] = newMajor;
}

void MajorService::deleteMajor(const Major& majorId) {
    _majors.erase(majorId.getName());
    _studentsByMajor.erase(majorId.getName());
}
