#ifndef MAJOR_H
#define MAJOR_H

#include <string>
#include <vector>
#include <memory>
#include "Course.h"

class Major {
private:
    std::string name;
    std::vector<std::shared_ptr<Course>> courses;
    float graduateScore;

public:
    Major(const std::string& name, float graduateScore);

    // Getter / Setter
    const std::string& getName() const;
    void setName(const std::string& newName);

    float getGraduateScore() const;
    void setGraduateScore(float score);

    const std::vector<std::shared_ptr<Course>>& getCourses() const;
    void setCourses(const std::vector<std::shared_ptr<Course>>& newCourses);

    // Course manipulation
    void addCourse(const std::shared_ptr<Course>& course);
    void removeCourse(const std::string& courseID);

    // Graduation check
    bool isGraduate(float studentScore) const;
};

#endif // MAJOR_H
