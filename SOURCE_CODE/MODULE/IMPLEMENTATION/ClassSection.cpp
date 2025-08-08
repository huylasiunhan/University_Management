#include "ClassSection.h"
#include "Course.h"
#include "Teacher.h"
#include "Student.h"
#include "Score.h"
#include "Time.h"
#include "FileManaging.h"
#include "ParserCourse.h"
#include "ParserTeacher.h"
#include "ParserStudent.h"
#include "ScoreParser.h"
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <memory>


using namespace std;   
ClassSection::ClassSection() : _classID(""), _course(nullptr), _teacher(nullptr), _score(nullptr) {}

ClassSection::ClassSection(const string& classID, shared_ptr<Course> course, shared_ptr<Teacher> teacher,
                           const vector<shared_ptr<Student>>& students, shared_ptr<Score> score, const Time& schedule)
    : _classID(classID), _course(course), _teacher(teacher), _students(students), _score(score), _Schedule(schedule) {}

string ClassSection::getClassID() const {
    return _classID;
}

shared_ptr<Course> ClassSection::getCourse() const {
    return _course;
}

shared_ptr<Teacher> ClassSection::getTeacher() const {
    return _teacher;
}

vector<shared_ptr<Student>> ClassSection::getStudents() const {
    return _students;
}

shared_ptr<Score> ClassSection::getScore() const {
    return _score;
}

Time ClassSection::getSchedule() const {
    return _Schedule;
}

void ClassSection::setClassID(const string& classID) {
    _classID = classID;
}

void ClassSection::setCourse(shared_ptr<Course> course) {
    _course = course;
}

void ClassSection::setTeacher(shared_ptr<Teacher> teacher) {
    _teacher = teacher;
}

void ClassSection::setStudents(const vector<shared_ptr<Student>>& students) {
    _students = students;
}

void ClassSection::setScore(shared_ptr<Score> score) {
    _score = score;
}

void ClassSection::setSchedule(const Time& schedule) {
    _Schedule = schedule;
}

void ClassSection::addStudent(shared_ptr<Student> student) {
    _students.push_back(student);
}

void ClassSection::removeStudent(shared_ptr<Student> student) {
    auto it = remove_if(_students.begin(), _students.end(),
                        [&](const shared_ptr<Student>& s) { return s->getId() == student->getId(); });
    if (it != _students.end()) {
        _students.erase(it, _students.end());
    }
}


// function to split a string by a delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


shared_ptr<ClassSection> ParserClassSection::parseFromString(const string& line,
                                                            const vector<shared_ptr<Course>>& allCourses,
                                                            const vector<shared_ptr<Teacher>>& allTeachers,
                                                            const vector<shared_ptr<Student>>& allStudents,
                                                            const vector<shared_ptr<Score>>& allScores) {
    stringstream ss(line);
    string classID, courseID, teacherID, scoreID, scheduleIndexStr, studentIDsStr;

    getline(ss, classID, ',');
    getline(ss, courseID, ',');
    getline(ss, teacherID, ',');
    getline(ss, scoreID, ',');
    getline(ss, scheduleIndexStr, ',');
    getline(ss, studentIDsStr);

    // Parse schedule index
    pair<int,int> scheduleIndex;
    stringstream scheduleStream(scheduleIndexStr);
    string temp;
    getline(scheduleStream, temp, '-');
    scheduleIndex.first = stoi(temp);
    getline(scheduleStream, temp);
    scheduleIndex.second = stoi(temp);
    
    // Find Course object by ID
    shared_ptr<Course> course = nullptr;
    for (const auto& c : allCourses) {
        if (c->getId() == courseID) {
            course = c;
            break;
        }
    }
    
    // Find Teacher object by ID
    shared_ptr<Teacher> teacher = nullptr;
    for (const auto& t : allTeachers) {
        if (t->getId() == teacherID) {
            teacher = t;
            break;
        }
    }   
    
    // Find Score object by ID
    shared_ptr<Score> score = nullptr;
    for (const auto& s : allScores) {
        if (s->getId() == scoreID) {
            score = s;
            break;
        }
    }
    // Parse student IDs
    vector<shared_ptr<Student>> students;
    vector<string> studentIDs = split(studentIDsStr, ';');
    for (const auto& studentID : studentIDs) {
        for (const auto& student : allStudents) {
            if (student->getId() == studentID) {
                students.push_back(student);
                break;
            }
        }
    }

    // Create and return a new ClassSection object
    return make_shared<ClassSection>(classID, course, teacher, students, score, Time(scheduleIndex, classID));  

}

vector<shared_ptr<ClassSection>> ParserClassSection::parseFromFile(const string& filename,
                                                                  const vector<shared_ptr<Course>>& allCourses,
                                                                  const vector<shared_ptr<Teacher>>& allTeachers,
                                                                  const vector<shared_ptr<Student>>& allStudents,
                                                                  const vector<shared_ptr<Score>>& allScores) {
    vector<shared_ptr<ClassSection>> classSections;
    vector<string> lines = FileManager::fileReader(filename);
    
    for (const auto& line : lines) {
        shared_ptr<ClassSection> section = parseFromString(line, allCourses, allTeachers, allStudents, allScores);
        if (section) {
            classSections.push_back(section);
        }
    }
    
    return classSections;
}   
  