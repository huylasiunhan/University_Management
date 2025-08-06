#include "RegistrationService.h"

// Đăng ký lớp nếu có thể
bool RegistrationService::registerClass(std::shared_ptr<Student> student,
                                        std::shared_ptr<ClassSection> section) {
    if (!canRegister(student, section)) return false;

    registrations[student->getID()].push_back(section);
    section->addStudent(student); // Thêm sinh viên vào lớp

    auto currentClasses = student->getEnrolledClasses(); 
    currentClasses.push_back(section);                   // tạo bản sao, thêm lớp mới
    student->setEnrolledClasses(currentClasses);         // cập nhật lại toàn bộ danh sách
    return true;
}

// Huỷ đăng ký lớp học theo ID
bool RegistrationService::unregisterClass(std::shared_ptr<Student> student,
                                          const std::string& sectionID) {
    auto& enrolled = registrations[student->getID()]; // Lấy danh sách lớp đã đăng ký

    // Xoá khỏi danh sách lớp trong registrations
    auto it = std::remove_if(enrolled.begin(), enrolled.end(),
        [&](const std::shared_ptr<ClassSection>& sec) {
            return sec->getClassID() == sectionID;
        });

    if (it == enrolled.end()) return false;

    enrolled.erase(it, enrolled.end());

    // Cập nhật lại danh sách lớp trong Student 
    auto currentClasses = student->getEnrolledClasses();
    auto it2 = std::remove_if(currentClasses.begin(), currentClasses.end(),
        [&](const std::shared_ptr<ClassSection>& sec) {
            return sec->getClassID() == sectionID;
        });
    currentClasses.erase(it2, currentClasses.end());
    student->setEnrolledClasses(currentClasses);

    return true;
}


// Lấy danh sách lớp đã đăng ký
//Cần kiểm tra lại vì student đã có getEnrolledClasses() trong Student.h
std::vector<std::shared_ptr<ClassSection>> RegistrationService::getEnrolledClasses(
    const std::shared_ptr<Student>& student) const {
    auto it = registrations.find(student->getID());
    if (it != registrations.end()) return it->second;
    return {};
}

// Kiểm tra có thể đăng ký không (giới hạn số lớp)
//Chưa có max capacity nên chỉ kiểm tra trùng lớp và số lượng lớp đã đăng ký
bool RegistrationService::canRegister(const std::shared_ptr<Student>& student,
                                      const std::shared_ptr<ClassSection>& section) const {
    const size_t MAX_CLASSES = 8; // Tùy logic hệ thống
    auto enrolled = student->getEnrolledClasses();

    // Kiểm tra trùng
    for (const auto& cls : enrolled) {
        if (cls->getClassID() == section->getClassID()) return false; //trùng lớp
    }

    return enrolled.size() < MAX_CLASSES;
}

// Đếm số lớp đã đăng ký
size_t RegistrationService::countRegistered(const std::shared_ptr<Student>& student) const {
    return student->getEnrolledClasses().size();
}

// Xoá toàn bộ lớp đã đăng ký
void RegistrationService::clearRegistrations(const std::shared_ptr<Student>& student) {
    registrations.erase(student->getID());
    student->setEnrolledClasses({});
}
