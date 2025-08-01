#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Score.h"
#include "ClassSection.h"
#include "Major.h"
#include <vector>
#include <fstream>
#include <sstream>



class Parser; // Forward declaration

class Student : public Person {
private:
    Major* major;
    std::vector<Score*> scores;
    std::vector<ClassSection*> enrolledClasses; 

public:
    Student();
    Student(const std::string& id, const std::string& name, const std::string& email, Major* major);

    // Getters & Setters
    Major* getMajor() const;
    void setMajor(Major* m);
    std::vector<Score*>& getScores();
    std::vector<ClassSection*>& getEnrolledClasses();

    friend class ParserStudent;
};

class ParserStudent {
public:
    static Student* parseFromLine(const std::string& line, const std::vector<Major*>& majors);
    static std::vector<Student*> parseFromFile(const std::string& filename, const std::vector<Major*>& majors);
};

#endif
