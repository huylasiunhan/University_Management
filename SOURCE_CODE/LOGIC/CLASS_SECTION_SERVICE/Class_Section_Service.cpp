#include "Class_Section_Service.h"

ClassSectionService::ClassSectionService(const std::vector<ClassSection>& classSections) {
    _classSections.reserve(classSections.size());
    for (const auto& section : classSections) {
        _classSections.push_back(section);
    }
}

std::vector<ClassSection> ClassSectionService::getClassSections() const {
    return _classSections;
}

bool ClassSectionService::addClassSection(const ClassSection& classSection) {
    for (const auto& section : _classSections) {
        if (section.getId() == classSection.getId()) {
            return false; // Đã tồn tại
        }
    }
    _classSections.push_back(classSection);
    return true;
}

bool ClassSectionService::removeClassSection(const std::string& classSectionId) {
    for (auto it = _classSections.begin(); it != _classSections.end(); ++it) {
        if (it->getId() == classSectionId) {
            _classSections.erase(it);
            return true;
        }
    }
    return false;
}

bool ClassSectionService::updateClassSection(const ClassSection& classSection) {
    for (auto& section : _classSections) {
        if (section.getId() == classSection.getId()) {
            section = classSection; // Ghi đè dữ liệu mới
            return true;
        }
    }
    return false;
}

std::optional<ClassSection> ClassSectionService::getClassSectionById(const std::string& classSectionId) const {
    for (const auto& section : _classSections) {
        if (section.getId() == classSectionId) {
            return section;
        }
    }
    return std::nullopt;
}

std::optional<std::vector<std::string>> ClassSectionService::getStudentIdsInClassSection(const std::string& classSectionId) const {
    for (const auto& section : _classSections) {
        if (section.getId() == classSectionId) {
            return section.getStudentIds();
        }
    }
    return std::nullopt;
}

std::optional<std::string> ClassSectionService::getTeacherIdsInClassSection(const std::string& classSectionId) const {
    for (const auto& section : _classSections) {
        if (section.getId() == classSectionId) {
            return section.getTeacherId();
        }
    }
    return std::nullopt;
}
