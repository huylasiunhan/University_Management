#include "ClassSection.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Score.h"
#include "Time.h"

#include <algorithm>

ClassSection::ClassSection(const std::string& classID,
                           const std::shared_ptr<Course>& course,
                           const std::shared_ptr<Teacher>& teacher,
                           const std::shared_ptr<Score>& score,
                           const std::shared_ptr<Time>& schedule)
    : classID(classID),
      course(course),
      teacher(teacher),
      score(score),
      schedule(schedule) {}

const std::string& ClassSection::getClassID() const {
    return classID;
}

void ClassSection::setClassID(const std::string& id) {
    classID = id;
}

std::shared_ptr<Course> ClassSection::getCourse() const {
    return course;
}

void ClassSection::setCourse(const std::shared_ptr<Course>& c) {
    course = c;
}

const std::vector<std::shared_ptr<Student>>& ClassSection::getStudentList() const {
    return studentList;
}

std::shared_ptr<Teacher> ClassSection::getTeacher() const {
    return teacher;
}

void ClassSection::setTeacher(const std::shared_ptr<Teacher>& t) {
    teacher = t;
}

std::shared_ptr<Score> ClassSection::getScore() const {
    return score;
}

void ClassSection::setScore(const std::shared_ptr<Score>& s) {
    score = s;
}

std::shared_ptr<Time> ClassSection::getSchedule() const {
    return schedule;
}

void ClassSection::setSchedule(const std::shared_ptr<Time>& t) {
    schedule = t;
}

void ClassSection::addStudent(const std::shared_ptr<Student>& student) {
    studentList.push_back(student);
}

void ClassSection::removeStudent(const std::string& studentID) {
    studentList.erase(
        std::remove_if(studentList.begin(), studentList.end(),
            [&studentID](const std::shared_ptr<Student>& s) {
                return s->getID() == studentID;
            }),
        studentList.end()
    );
}
