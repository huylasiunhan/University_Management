#pragma once
#include "IClassSectionService.h"
#include "ClassSection.h"
#include <vector>
#include <optional>
#include <string>

using namespace std;


class ClassSectionService : public IClassSectionService {
private:
    std::vector<ClassSection> _classSections;

public:
    ClassSectionService() = default;
    explicit ClassSectionService(const std::vector<ClassSection>& classSections);

    // Lấy toàn bộ danh sách lớp học phần
    std::vector<ClassSection> getClassSections() const;

    // Triển khai các hàm từ interface
    bool addClassSection(const ClassSection& classSection) override;
    bool removeClassSection(const std::string& classSectionId) override;
    bool updateClassSection(const ClassSection& classSection) override;
    std::optional<ClassSection> getClassSectionById(const std::string& classSectionId) const override;
    std::optional<std::vector<std::string>> getStudentIdsInClassSection(const std::string& classSectionId) const override;
    std::optional<std::string> getTeacherIdInClassSection(const std::string& classSectionId) const override;
};
