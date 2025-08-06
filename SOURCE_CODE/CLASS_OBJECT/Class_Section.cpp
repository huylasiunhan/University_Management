#include "Class_Section.h"

// Constructor không đối số
ClassSection::ClassSection()
    : _id(""), _courseId(""), _teacherId(""), _scoreId(""), 
      _scheduleIndex({0, 0}), _studentIds({}) {}

// Constructor có đối số
ClassSection::ClassSection(const string& id, const string& courseId,
                           const string& teacherId, const string& scoreId,
                           const pair<int,int>& scheduleIndex,
                           const vector<string>& studentIds)
    : _id(id), _courseId(courseId), _teacherId(teacherId), 
      _scoreId(scoreId), _scheduleIndex(scheduleIndex), 
      _studentIds(studentIds) {}

// Getter
string ClassSection::getId() const { return _id; }
string ClassSection::getCourseId() const { return _courseId; }
string ClassSection::getTeacherId() const { return _teacherId; }
string ClassSection::getScoreId() const { return _scoreId; }
pair<int,int> ClassSection::getScheduleIndex() const { return _scheduleIndex; }
vector<string> ClassSection::getStudentIds() const { return _studentIds; }

// Setter
void ClassSection::setId(const string& id) { _id = id; }
void ClassSection::setCourseId(const string& courseId) { _courseId = courseId; }
void ClassSection::setTeacherId(const string& teacherId) { _teacherId = teacherId; }
void ClassSection::setScoreId(const string& scoreId) { _scoreId = scoreId; }
void ClassSection::setScheduleIndex(const pair<int,int>& scheduleIndex) { _scheduleIndex = scheduleIndex; }
void ClassSection::setStudentIds(const vector<string>& studentIds) { _studentIds = studentIds; }

// Destructor
ClassSection::~ClassSection() {}
