#ifndef CLASS_SECTION_H
#define CLASS_SECTION_H


#pragma once
#include <string>
#include <vector>
#include <utility> // pair
using namespace std;

#ifndef CLASSSECTION_H
#define CLASSSECTION_H

#include <string>
#include <vector>
#include <memory>
#include "Course.h"
#include "Teacher.h"    
#include "Student.h"
#include "Score.h"
#include "Time.h"

class ClassSection {
private:
    std::string classID;
    std::shared_ptr<Course> course;
    std::vector<std::shared_ptr<Student>> studentList;
    std::shared_ptr<Teacher> teacher;
    std::shared_ptr<Score> score;
    std::shared_ptr<Time> schedule;

public:
    ClassSection(const std::string& classID,
                 const std::shared_ptr<Course>& course,
                 const std::shared_ptr<Teacher>& teacher,
                 const std::shared_ptr<Score>& score,
                 const std::shared_ptr<Time>& schedule);

    // Getter / Setter
    const std::string& getClassID() const;
    void setClassID(const std::string& id);

    std::shared_ptr<Course> getCourse() const;
    void setCourse(const std::shared_ptr<Course>& course);

    const std::vector<std::shared_ptr<Student>>& getStudentList() const;

    std::shared_ptr<Teacher> getTeacher() const;
    void setTeacher(const std::shared_ptr<Teacher>& teacher);

    std::shared_ptr<Score> getScore() const;
    void setScore(const std::shared_ptr<Score>& score);

    std::shared_ptr<Time> getSchedule() const;
    void setSchedule(const std::shared_ptr<Time>& schedule);

    // Method from UML
    void addStudent(const std::shared_ptr<Student>& student);
    void removeStudent(const std::string& studentID);
};

#endif // CLASSSECTION_H


class ClassSectionParser {
public:
    // Parse từ CSV -> ClassSection
    static ClassSection parseFromLine(const string& csvLine);
    static vector<ClassSection> parseFromFile(const vector<string>& csvFile);
};


#endif
