#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Score.h"
#include "ClassSection.h"
#include "Major.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

class Student : public Person {
private:
    std::shared_ptr<Major> major;
    std::vector<std::shared_ptr<Score>> scores;
    std::vector<std::shared_ptr<ClassSection>> enrolledClasses;

public:
    Student();
    Student(const std::string& id, const std::string& name, const std::string& email, std::shared_ptr<Major> major);

    std::shared_ptr<Major> getMajor() const;
    void setMajor(std::shared_ptr<Major> major);

    const std::vector<std::shared_ptr<Score>>& getScores() const;
    void setScores(const std::vector<std::shared_ptr<Score>>& newScores);


    const std::vector<std::shared_ptr<ClassSection>>& getEnrolledClasses() const;
    void setEnrolledClasses(const std::vector<std::shared_ptr<ClassSection>>& newClasses);
};

class studentParser {
public:
    // Phương thức phân tích cú pháp từ dòng CSV
    static Student* parseFromLine(const std::string& line, const std::vector<Major*>& majors);
    // Phương thức phân tích cú pháp từ file CSV
    static std::vector<Student*> parseFromFile(const std::string& filename, const std::vector<Major*>& majors);
};

#endif
