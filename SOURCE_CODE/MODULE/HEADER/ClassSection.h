#ifndef CLASS_SECTION_H
#define CLASS_SECTION_H

#include <string>
#include <vector>
#include <memory>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"
#include "Score.h"
#include "Time.h"

using namespace std;

class ClassSection {
private:
    string _classID;
    shared_ptr<Course> _course;
    shared_ptr<Teacher> _teacher;
    vector<shared_ptr<Student>> _students;
    shared_ptr<Score> _score;
    Time _Schedule;

public:
    // Default constructor
    ClassSection();

    // Parameterized constructor
    ClassSection(const string& classID, shared_ptr<Course> course, shared_ptr<Teacher> teacher,
                 const vector<shared_ptr<Student>>& students, shared_ptr<Score> score, const Time& schedule);

    // Getters
    string getClassID() const;
    shared_ptr<Course> getCourse() const;
    shared_ptr<Teacher> getTeacher() const;
    vector<shared_ptr<Student>> getStudents() const;
    shared_ptr<Score> getScore() const;
    Time getSchedule() const;

    // Setters
    void setClassID(const string& classID);
    void setCourse(shared_ptr<Course> course);
    void setTeacher(shared_ptr<Teacher> teacher);
    void setStudents(const vector<shared_ptr<Student>>& students);
    void setScore(shared_ptr<Score> score);
    void setSchedule(const Time& schedule);

    // Destructor
    ~ClassSection() {
        // Destructor logic if needed
    }
    // Friend class for parsing
    friend class ParserClassSection;
};
class ParserClassSection {
public:
    static shared_ptr<ClassSection> parseFromString(const string& line,
                                                    const vector<shared_ptr<Course>>& allCourses,
                                                    const vector<shared_ptr<Teacher>>& allTeachers,
                                                    const vector<shared_ptr<Student>>& allStudents,
                                                    const vector<shared_ptr<Score>>& allScores);

    static vector<shared_ptr<ClassSection>> parseFromFile(const string& filename,
                                                          const vector<shared_ptr<Course>>& allCourses,
                                                          const vector<shared_ptr<Teacher>>& allTeachers,
                                                          const vector<shared_ptr<Student>>& allStudents,
                                                          const vector<shared_ptr<Score>>& allScores);
};

#endif 