#pragma once
#include "IRegistrationService.h"

class RegistrationService : public IRegistrationService {
public:
    bool registerClass(std::shared_ptr<Student> student,
                       std::shared_ptr<ClassSection> section) override;
};
