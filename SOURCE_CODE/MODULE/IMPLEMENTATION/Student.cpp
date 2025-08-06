#include "Student.h"
#include "FileManaging.h"

Student::Student() = default;

Student::Student(const std::string& id, const std::string& name, const std::string& email, std::shared_ptr<Major> major)
    : Person(id, name, email), major(std::move(major)) {}

std::shared_ptr<Major> Student::getMajor() const {
    return major;
}

void Student::setMajor(std::shared_ptr<Major> major) {
    this->major = std::move(major);
}

const std::vector<std::shared_ptr<Score>>& Student::getScores() const {
    return scores;
}

void Student::setScores(const std::vector<std::shared_ptr<Score>>& newScores) {
    scores = newScores;
}

const std::vector<std::shared_ptr<ClassSection>>& Student::getEnrolledClasses() const {
    return enrolledClasses;
}

void Student::setEnrolledClasses(const std::vector<std::shared_ptr<ClassSection>>& newClasses) {
    enrolledClasses = newClasses;
}



std::vector<Student*> studentParser::parseFromFile(const std::string& filename, const std::vector<Major*>& majors) {
    FileManager fm;
    std::vector<std::string> lines = fm.fileReader(filename);
    std::vector<Student*> students;
    for (const auto& line : lines) {
        Student* s = parseFromLine(line, majors);
        if (s) students.push_back(s);
    }
    return students;
}
