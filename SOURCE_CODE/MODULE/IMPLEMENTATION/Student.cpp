#include "FileManaging.h"
#include "Student.h"

Student::Student() : major(nullptr) {}

Student::Student(const std::string& id, const std::string& name, const std::string& email, Major* major)
    : Person(id, name, email), major(major) {}

Major* Student::getMajor() const { return major; }
void Student::setMajor(Major* m) { major = m; }

std::vector<Score*>& Student::getScores() { return scores; }
std::vector<ClassSection*>& Student::getEnrolledClasses() { return enrolledClasses; }

Student* ParserStudent::parseFromLine(const std::string& line, const std::vector<Major*>& majors) {
    std::stringstream ss(line);
    std::string id, name, email, majorName;

    std::getline(ss, id, ',');
    std::getline(ss, name, ',');
    std::getline(ss, email, ',');
    std::getline(ss, majorName, ',');

    Major* foundMajor = nullptr;
    for (auto* m : majors) {
        if (m->getName() == majorName) {
            foundMajor = m;
            break;
        }
    }

    return new Student(id, name, email, foundMajor);
}

std::vector<Student*> ParserStudent::parseFromFile(const std::string& filename, const std::vector<Major*>& majors) {
    FileManager fm;
    std::vector<std::string> lines = fm.fileReader(filename);
    std::vector<Student*> students;
    for (const auto& line : lines) {
        Student* s = parseFromLine(line, majors);
        if (s) students.push_back(s);
    }
    return students;
}
