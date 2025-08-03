#pragma once
#include <memory>
#include <string>
#include <optional>
#include <vector>
#include "Class_Section.h"
using namespace std;

class IClassSectionService {
public:
    virtual ~IClassSectionService() = default;

    virtual bool addClassSection(const ClassSection& classSection) = 0;
    virtual bool removeClassSection(const string& classSectionId) = 0;
    virtual bool updateClassSection(const ClassSection& classSection) = 0; // Thêm phương thức chỉnh sửa
    virtual optional<ClassSection> getClassSectionById(const string& classSectionId) const = 0;
    virtual optional<vector<string>> getStudentIdsInClassSection(const string& classSectionId) const = 0; // Xem học sinh trong lớp
    virtual optional<string> getTeacherIdInClassSection(const string& classSectionId) const = 0; // Xem giáo viên trong lớp
};