#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <memory>
#include "ClassSection.h"

class Course {
private:
    std::string name;
    std::string courseID;
    std::vector<std::shared_ptr<ClassSection>> classes;

public:
    Course(const std::string& name, const std::string& id);

    // Getter / Setter
    const std::string& getName() const;
    void setName(const std::string& newName);

    const std::string& getCourseID() const;
    void setCourseID(const std::string& newID);

    const std::vector<std::shared_ptr<ClassSection>>& getClasses() const;
    void setClasses(const std::vector<std::shared_ptr<ClassSection>>& newClasses);

    // ClassSection manipulation
    void addClass(const std::shared_ptr<ClassSection>& classSection);
    void removeClass(const std::string& classID);

    // Logic
    float getCourseScore() const; // placeholder logic
    bool isPass(float score) const;
};

#endif // COURSE_H
