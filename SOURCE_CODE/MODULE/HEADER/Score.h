#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Forward declarations để tránh include vòng
class Student;
class ClassSection;

/**
 * @brief Lớp Score lưu thông tin điểm số của một sinh viên trong một lớp cụ thể.
 */
class Score {
private:
    std::shared_ptr<Student> studentID;       // shared_ptr đến sinh viên
    std::shared_ptr<ClassSection> sectionID;  // shared_ptr đến lớp học phần
    std::string scoreID;

    float midterm = 0.0f;     // Điểm giữa kỳ
    float finalExam = 0.0f;   // Điểm cuối kỳ
    float other = 0.0f;       // Điểm khác (bonus, chuyên cần, lab, ...)
    float total = 0.0f;       // Tổng điểm

public:
    // Constructor
    Score(std::shared_ptr<Student> student, std::shared_ptr<ClassSection> section);

    // Getters
    std::shared_ptr<Student> getStudent() const;
    std::shared_ptr<ClassSection> getSection() const;

    float getMidterm() const;
    float getFinalExam() const;
    float getOther() const;
    float getTotal() const;

    // Setters
    void setMidterm(float m);
    void setFinalExam(float f);
    void setOther(float o);

    // Tính toán điểm tổng kết dựa trên trọng số
    void computeTotal();

    // In điểm ra màn hình
    void print() const;
};

/**
 * @brief Lớp ScoreParser để phân tích file điểm.
 */
class ScoreParser {
public:
    static std::vector<Score> parse(const std::string& file);
};

#endif // SCORE_H
