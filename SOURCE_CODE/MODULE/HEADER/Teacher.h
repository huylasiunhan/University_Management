#ifndef TEACHER_H
#define TEACHER_H
#pragma once
#include "Person.h"
#include "ClassSection.h"
#include <memory>
#include <vector>
#include <vector>

class Teacher : public Person {
private:
    std::vector<std::shared_ptr<ClassSection>> teachingClasses;

public:
    Teacher();
    Teacher(const std::string& id, const std::string& name, const std::string& email);

    std::vector<std::shared_ptr<ClassSection>>& getTeachingClasses();
    void setTeachingClasses(const std::vector<std::shared_ptr<ClassSection>>& classes);
    void addClass(const std::shared_ptr<ClassSection>& cls);
};


class teacherParser {
public:
    static Teacher* parseFromLine(const std::string& line);
    static std::vector<Teacher*> parseFromFile(const std::string& filename);
};

#endif
