#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "ClassSection.h"
#include <vector>
#include <fstream>
#include <sstream>


class ParserTeacher; // Forward declaration

class Teacher : public Person {
private:
    std::vector<ClassSection*> teachingClasses;

public:
    Teacher() = default;
    Teacher(const std::string& id, const std::string& name, const std::string& email);

    std::vector<ClassSection*>& getTeachingClasses();
    void addClass(ClassSection* cls);

    friend class ParserTeacher;
};

class ParserTeacher {
public:
    static Teacher* parseFromLine(const std::string& line);
    static std::vector<Teacher*> parseFromFile(const std::string& filename);
};

#endif
