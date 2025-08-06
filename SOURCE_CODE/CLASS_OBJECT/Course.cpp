#include "Course.h"

// Constructor không đối số
Course::Course() : _majorId(""), _id(""), _name(""), _classSectionIds({}) {}

// Constructor có đối số
Course::Course(const string& majorId, const string& id, 
               const string& name, const vector<string>& classSectionIds)
    : _majorId(majorId), _id(id), _name(name), _classSectionIds(classSectionIds) {}

// Getter
string Course::getMajorId() const { return _majorId; }
string Course::getId() const { return _id; }
string Course::getName() const { return _name; }
vector<string> Course::getClassSectionIds() const { return _classSectionIds; }

// Setter
void Course::setMajorId(const string& majorId) { _majorId = majorId; }
void Course::setId(const string& id) { _id = id; }
void Course::setName(const string& name) { _name = name; }
void Course::setClassSectionIds(const vector<string>& classSectionIds) { _classSectionIds = classSectionIds; }

// Destructor
Course::~Course() {}
