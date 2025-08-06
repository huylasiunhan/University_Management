#include "Course.h"
#include "ClassSection.h"

Course::Course(const std::string& name, const std::string& id)
    : name(name), courseID(id) {}

const std::string& Course::getName() const {
    return name;
}

void Course::setName(const std::string& newName) {
    name = newName;
}

const std::string& Course::getCourseID() const {
    return courseID;
}

void Course::setCourseID(const std::string& newID) {
    courseID = newID;
}

const std::vector<std::shared_ptr<ClassSection>>& Course::getClasses() const {
    return classes;
}

void Course::setClasses(const std::vector<std::shared_ptr<ClassSection>>& newClasses) {
    classes = newClasses;
}

void Course::addClass(const std::shared_ptr<ClassSection>& classSection) {
    classes.push_back(classSection);
}

void Course::removeClass(const std::string& classID) {
    classes.erase(std::remove_if(classes.begin(), classes.end(),
        [&classID](const std::shared_ptr<ClassSection>& section) {
            return section->getClassID() == classID;
        }),
        classes.end());
}

float Course::getCourseScore() const {
    // Giả định: điểm trung bình của tất cả lớp thuộc course này
    float total = 0;
    int count = 0;
    for (const auto& section : classes) {
        total += section->getAverageScore();
        ++count;
    }
    return (count > 0) ? (total / count) : 0.0f;
}

bool Course::isPass(float score) const {
    return score >= 5.0f;
}
