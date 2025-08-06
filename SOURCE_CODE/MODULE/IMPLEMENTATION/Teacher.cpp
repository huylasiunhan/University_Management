#include "FileManaging.h"
#include "Teacher.h"


Teacher::Teacher() = default;

Teacher::Teacher(const std::string& id, const std::string& name, const std::string& email)
    : Person(id, name, email) {}

std::vector<std::shared_ptr<ClassSection>>& Teacher::getTeachingClasses() {
    return teachingClasses;
}

void Teacher::setTeachingClasses(const std::vector<std::shared_ptr<ClassSection>>& classes) {
    teachingClasses = classes;
}

void Teacher::addClass(const std::shared_ptr<ClassSection>& cls) {
    teachingClasses.push_back(cls);
}


Teacher* teacherParser::parseFromLine(const std::string& line) {
    std::stringstream ss(line);
    std::string id, name, email;

    std::getline(ss, id, ',');
    std::getline(ss, name, ',');
    std::getline(ss, email, ',');

    return new Teacher(id, name, email);
}

std::vector<Teacher*> teacherParser::parseFromFile(const std::string& filename) {
    FileManager fm;
    std::vector<std::string> lines = fm.fileReader(filename);
    std::vector<Teacher*> teachers;
    for (const auto& line : lines) {
        Teacher* t = parseFromLine(line);
        if (t) teachers.push_back(t);
    }
    return teachers;
}
