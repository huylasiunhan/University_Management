#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include "IRegistrationService.h"
#include "Student.h"
#include "ClassSection.h"

class RegistrationService : public IRegistrationService {
private:
    // Lưu danh sách các lớp đã đăng ký của mỗi sinh viên
    std::unordered_map<std::string, std::vector<std::shared_ptr<ClassSection>>> registrations;

public:
    ~RegistrationService() override = default;

    bool registerClass(std::shared_ptr<Student> student,
                       std::shared_ptr<ClassSection> section) override;

    bool unregisterClass(std::shared_ptr<Student> student,
                         const std::string& sectionID) override;

    std::vector<std::shared_ptr<ClassSection>> getEnrolledClasses(
        const std::shared_ptr<Student>& student) const override;

    bool canRegister(const std::shared_ptr<Student>& student,
                     const std::shared_ptr<ClassSection>& section) const override;

    size_t countRegistered(const std::shared_ptr<Student>& student) const override;

    void clearRegistrations(const std::shared_ptr<Student>& student) override;
};
