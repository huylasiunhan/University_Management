#ifndef MAJOR_H
#define MAJOR_H

#include <string>
#include <vector>
#include <memory>
#include "Course.h"
using namespace std;
class Major {
private:
    string name;
    vector<shared_ptr<Course>> courses;

public:
    Major(const string& name, const vector<shared_ptr<Course>>& courses);
    string getName() const;
    vector<shared_ptr<Course>> getCourses() const;
    void setName(const string& name);
    void setCourses(const vector<shared_ptr<Course>>& courses);

    void addCourse(const shared_ptr<Course>& course);
    void removeCourse(const string& courseId);
    bool isGraduate();
    float graduateScore();



    // Destructor
    ~Major() {
        // Destructor logic if needed
    }   
    // Friend class for parsing
    friend class ParserMajor;
};

class ParserMajor {
public:
    static shared_ptr<Major> parseFromString(const string& line, const vector<shared_ptr<Course>>& allCourses);
    static vector<shared_ptr<Major>> parseFromFile(const string& filename, const vector<shared_ptr<Course>>& allCourses);
}

#endif // MAJOR_H