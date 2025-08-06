#pragma once
#include <memory>
#include <optional>
#include <string>
#include "Student.h"
#include "Major.h"
#include <vector>
#include "Course.h"

class IMajorService {
public:

    // trả về danh sách các môn học còn lại của sinh viên
    virtual std::vector<Course> getRemainingCourses(const std::shared_ptr<Student>& student) const = 0;

    //trả về điểm trung bình của sinh viên
    virtual double calculateGPA(const std::shared_ptr<Student>& student) const = 0;
    
    //trả về tổng số tín chỉ của sinh viên
    virtual int getTotalCredits(const std::shared_ptr<Student>& student) const = 0;

    // phân loại học lực dựa trên điểm GPA
    virtual std::string classifyDegree(double gpa) const = 0;

    // trả về danh sách các môn học bắt buộc của chuyên ngành
    virtual std::vector<Course> getRequiredCourses(const Major& majorId) const = 0;

    //trả về danh sách các môn tự chọn của chuyên ngành 
    virtual std::vector<Course> getElectiveCourses(const Major& majorId) const = 0;

    //trả về thông tin chuyên ngành
    virtual const Major& getMajorInfo(const Major& majorId) const = 0;

    //trả về danh sách sinh viên trong chuyên ngành
    virtual std::vector<Student> getStudentsInMajor(const Major& majorId) const = 0;

    //gán sinh viên vào chuyên ngành
    virtual void assignStudentToMajor(const Student& studentId, const Major& majorId) = 0;

    //xóa sinh viên khỏi chuyên ngành
    virtual void removeStudentFromMajor(const std::shared_ptr<Student>& student) = 0;

    //cập nhật thông tin chuyên ngành
    virtual void updateMajorInfo(const Major& majorId, const Major& updated) = 0;

    //thêm mới chuyên ngành
    virtual void addNewMajor(const Major& newMajor) = 0;

    //xóa chuyên ngành
    virtual void deleteMajor(const Major& majorId) = 0;

    //destructor
    virtual ~IMajorService() = default;
};