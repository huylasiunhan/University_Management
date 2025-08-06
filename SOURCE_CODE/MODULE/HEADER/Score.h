#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <string>

// Forward declarations để tránh circular include
class Student;
class ClassSection;

/**
 * @brief Lớp Score lưu thông tin điểm số của một sinh viên trong một lớp cụ thể.
 */
    class Score {
    private:
        Student* studentID;           // Con trỏ đến sinh viên
        ClassSection* sectionID;      // Con trỏ đến lớp học phần
        std::string scoreID;

        float midterm = 0.0f;       // Điểm giữa kỳ
        float finalExam = 0.0f;     // Điểm cuối kỳ
        float other = 0.0f;         // Điểm khác (bonus, chuyên cần, lab, ...)
        float total = 0.0f;         // Tổng điểm

    public:
        // Constructor
        Score(Student* student, ClassSection* section);

        // Getters
        Student* getStudent() const;
        ClassSection* getSection() const;

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


class scoreParser {
public:
    static std::vector<Score> parse(const std::string& file);
};

#endif