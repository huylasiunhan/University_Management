#ifndef CLASS_SECTION_H
#define CLASS_SECTION_H

#include <string>
#include <vector>
#include <utility>
using namespace std;

class ClassSection {
private:
    string _id;
    string _courseId;
    string _teacherId;
    string _scoreId;
    pair<int, int> _scheduleIndex;
    vector<string> _studentIds;

public:
    // Constructor không đối số
    ClassSection();

    // Constructor có đối số
    ClassSection(const string& id, const string& courseId,
                 const string& teacherId, const string& scoreId,
                 const pair<int,int>& scheduleIndex,
                 const vector<string>& studentIds);

    // Getter
    string getId() const;
    string getCourseId() const;
    string getTeacherId() const;
    string getScoreId() const;
    pair<int,int> getScheduleIndex() const;
    vector<string> getStudentIds() const;

    // Setter
    void setId(const string& id);
    void setCourseId(const string& courseId);
    void setTeacherId(const string& teacherId);
    void setScoreId(const string& scoreId);
    void setScheduleIndex(const pair<int,int>& scheduleIndex);
    void setStudentIds(const vector<string>& studentIds);

    // Destructor
    ~ClassSection();
    // Friend class for parsing
    friend class ParserClassSection;
};
class ParserClassSection {
public:
    static ClassSection parseFromLine(const string& line);
    static vector<ClassSection> parseFromFile(const string& filename);
};

#endif 