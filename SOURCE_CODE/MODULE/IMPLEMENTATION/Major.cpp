#include "Major.h"
#include "Course.h"

Major::Major(const std::string& name, float graduateScore)
    : name(name), graduateScore(graduateScore) {}

const std::string& Major::getName() const {
    return name;
}

void Major::setName(const std::string& newName) {
    name = newName;
}

float Major::getGraduateScore() const {
    return graduateScore;
}

void Major::setGraduateScore(float score) {
    graduateScore = score;
}

const std::vector<std::shared_ptr<Course>>& Major::getCourses() const {
    return courses;
}

void Major::setCourses(const std::vector<std::shared_ptr<Course>>& newCourses) {
    courses = newCourses;
}

void Major::addCourse(const std::shared_ptr<Course>& course) {
    courses.push_back(course);
}

void Major::removeCourse(const std::string& courseID) {
    courses.erase(std::remove_if(courses.begin(), courses.end(),
        [&courseID](const std::shared_ptr<Course>& course) {
            return course->getCourseID() == courseID;
        }),
        courses.end());
}

bool Major::isGraduate(float studentScore) const {
    return studentScore >= graduateScore;
}
