#pragma once
#include <string>
#include <vector>
using namespace std;

class Course {
private:
    string _majorId;
    string _id;
    string _name;
    vector<string> _classSectionIds;

public:
    // Constructor không đối số
    Course();

    // Constructor có đối số
    Course(const string& majorId, const string& id, 
           const string& name, const vector<string>& classSectionIds);

    // Getter
    string getMajorId() const;
    string getId() const;
    string getName() const;
    vector<string> getClassSectionIds() const;

    // Setter
    void setMajorId(const string& majorId);
    void setId(const string& id);
    void setName(const string& name);
    void setClassSectionIds(const vector<string>& classSectionIds);

    // Destructor
    ~Course();
};
