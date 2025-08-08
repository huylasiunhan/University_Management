#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
using namespace std;

class Course {
private:
    vector<shared_ptr<Major>> _majorId; 
    string _id;
    string _name;
    vector<shared_ptr<ClassSection>> _classSectionIds;

public:
    // Default constructor
    Course();

    // Parameterized constructor
    Course(const string& id, const string& name, const vector<shared_ptr<Major>>& majorId,
           const vector<shared_ptr<ClassSection>>& classSectionIds);

    // Getters
    string getId() const;
    string getName() const;
    vector<shared_ptr<Major>> getMajorId() const;
    vector<shared_ptr<ClassSection>> getClassSectionIds() const;

    // Setters
    void setId(const string& id);
    void setName(const string& name);
    void setMajorId(const vector<shared_ptr<Major>>& majorId);
    void setClassSectionIds(const vector<shared_ptr<ClassSection>>& classSectionIds);

    // Destructor
    ~Course() {
        // Destructor logic if needed
    }
    friend class ParserCourse;
};
class ParserCourse {
public:
    static shared_ptr<Course> parseFromString(const string& line,
                                              const vector<shared_ptr<Major>>& allMajors,
                                              const vector<shared_ptr<ClassSection>>& allClassSections);
    static vector<shared_ptr<Course>> parseFromFile(const string& filename,
                                                    const vector<shared_ptr<Major>>& allMajors,
                                                    const vector<shared_ptr<ClassSection>>& allClassSections);
};

#endif
