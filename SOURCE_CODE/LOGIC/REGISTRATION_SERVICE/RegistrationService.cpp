#include "RegistrationService.h"

bool RegistrationService::registerClass(std::shared_ptr<Student> student,
                                        std::shared_ptr<ClassSection> section) {
    if (section->isFull()) return false;
    student->enroll(section);
    section->addStudent(student);
    return true;
}