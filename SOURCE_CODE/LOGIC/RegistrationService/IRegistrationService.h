#pragma once
#include <memory>
#include <optional>
#include "Student.h"
#include "ClassSection.h"

class IRegistrationService {
public:
    virtual ~IRegistrationService() = default;

    virtual bool registerClass(std::shared_ptr<Student> student,
                               std::shared_ptr<ClassSection> section) = 0;

    virtual bool unregisterClass(std::shared_ptr<Student> student,
                                 const std::string& sectionID) = 0;

    virtual std::vector<std::shared_ptr<ClassSection>> getEnrolledClasses(
        const std::shared_ptr<Student>& student) const = 0;

    virtual bool canRegister(const std::shared_ptr<Student>& student,
                             const std::shared_ptr<ClassSection>& section) const = 0;

    virtual size_t countRegistered(const std::shared_ptr<Student>& student) const = 0;

    virtual void clearRegistrations(const std::shared_ptr<Student>& student) = 0;

    virtual std::vector<RegistrationRecord> getHistory(const std::shared_ptr<Student>& student) const = 0;
};
