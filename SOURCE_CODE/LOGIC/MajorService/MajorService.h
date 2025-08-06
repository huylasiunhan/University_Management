#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include <memory>
#include "IMajorService.h"
#include "Major.h"
#include "Student.h"
#include "Course.h"

class MajorService : public IMajorService {
private:
    std::unordered_map<std::string, Major> _majors;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Student>>> _studentsByMajor;

public:
    //std::optional<std::string> getGraduationEligibility(const Student& studentId) const override;
    std::vector<Course> getRemainingCourses(const std::shared_ptr<Student>& student) const override;
    // trả về điểm trung bình của sinh viên
    double calculateGPA(const std::shared_ptr<Student>& student) const override;
    // trả về tổng số tín chỉ của sinh viên
    int getTotalCredits(const std::shared_ptr<Student>& student) const override;
    // phân loại học lực dựa trên điểm GPA
    std::string classifyDegree(double gpa) const override;

    // trả về danh sách các môn học bắt buộc và tự chọn của chuyên ngành
    std::vector<Course> getRequiredCourses(const Major& majorId) const override;
    // trả về danh sách các môn tự chọn của chuyên ngành
    std::vector<Course> getElectiveCourses(const Major& majorId) const override;
    // trả về thông tin chuyên ngành
    const Major& getMajorInfo(const Major& majorId) const override;
    // trả về danh sách sinh viên trong chuyên ngành
    std::vector<Student> getStudentsInMajor(const Major& majorId) const override;

    // gán sinh viên vào chuyên ngành
    void assignStudentToMajor(const Student& studentId, const Major& majorId) override;
    // xóa sinh viên khỏi chuyên ngành
    void removeStudentFromMajor(const std::shared_ptr<Student>& student) override;
    // cập nhật thông tin chuyên ngành
    void updateMajorInfo(const Major& majorId, const Major& updated) override;
    // thêm mới chuyên ngành
    void addNewMajor(const Major& newMajor) override;
    // xóa chuyên ngành
    void deleteMajor(const Major& majorId) override;
};
