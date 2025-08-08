#pragma once
#include <memory>
#include <optional>
#include "Student.h"
#include "ClassSection.h"

class IRegistrationService {
public:
    virtual bool registerClass(std::shared_ptr<Student> student,
                               std::shared_ptr<ClassSection> section) = 0;

    virtual bool unregisterClass(std::shared_ptr<Person> person,
                                 const std::string& classID) = 0;

    virtual std::vector<std::shared_ptr<ClassSection>> getEnrolledClasses(
        const std::shared_ptr<Person>& person) const = 0; //ON GOING [CHECK]

    virtual bool canRegister(const std::shared_ptr<Person>& person,
                             const std::shared_ptr<ClassSection>& section) const = 0;

    virtual size_t countRegistered(const std::shared_ptr<Person>& person) const = 0;

    virtual void clearRegistrations(const std::shared_ptr<Person>& person) = 0;

    std::vector<RegistrationRecord> getHistory(const std::shared_ptr<Person>& person) const; //ON GOING [QUESTIONING]   

    virtual ~IRegistrationService() = default;
};