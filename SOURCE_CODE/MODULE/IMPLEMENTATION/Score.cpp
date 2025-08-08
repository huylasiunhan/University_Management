#include "../HEADER/Score.h"
#include "../HEADER/Student.h"
#include "../HEADER/ClassSection.h"
#include "../../DATA/DATA_ACCESSING/FileManaging.h"
#include <sstream>
#include <iostream>
#include <memory>

// Constructor gán sinh viên và lớp học phần tương ứng
Score::Score(std::shared_ptr<Student> student, std::shared_ptr<ClassSection> section)
    : studentID(std::move(student)), sectionID(std::move(section)) {}

// Getters
std::shared_ptr<Student> Score::getStudent() const {
    return studentID;
}

std::shared_ptr<ClassSection> Score::getSection() const {
    return sectionID;
}

float Score::getMidterm() const {
    return midterm;
}

float Score::getFinalExam() const {
    return finalExam;
}

float Score::getOther() const {
    return other;
}

float Score::getTotal() const {
    return total;
}

// Setters
void Score::setMidterm(float m) {
    midterm = m;
    computeTotal();  // Tự động tính lại điểm tổng
}

void Score::setFinalExam(float f) {
    finalExam = f;
    computeTotal();
}

void Score::setOther(float o) {
    other = o;
    computeTotal();
}

// Hàm tính tổng điểm theo trọng số quy định
void Score::computeTotal() {
    total = 0.3f * midterm + 0.5f * finalExam + 0.2f * other;
}

// In ra thông tin điểm của sinh viên
void Score::print() const {
    std::cout << "Midterm: " << midterm
              << ", Final: " << finalExam
              << ", Other: " << other
              << ", Total: " << total << std::endl;
}

// ---------------------------- ScoreParser ----------------------------

std::vector<Score> ScoreParser::parse(const std::string& fileInput) {
    FileManager fm;
    std::vector<std::string> lines = fm.fileReader(fileInput);
    
    std::vector<Score> scores;

    for (const std::string& line : lines) {
        std::stringstream ss(line);
        std::string token;

        std::string scoreID;
        std::string studentIDStr;
        std::string sectionIDStr;
        float midterm = 0.0f;
        float finalExam = 0.0f;

        // Tách các thành phần từ chuỗi
        std::getline(ss, scoreID, ',');
        std::getline(ss, studentIDStr, ',');
        std::getline(ss, sectionIDStr, ',');
        std::getline(ss, token, ',');
        midterm = std::stof(token);
        std::getline(ss, token, ',');
        finalExam = std::stof(token);

        // TODO: Map studentIDStr và sectionIDStr thành đối tượng thực tế nếu cần
        std::shared_ptr<Student> student = nullptr;
        std::shared_ptr<ClassSection> section = nullptr;

        Score score(student, section);
        score.setMidterm(midterm);
        score.setFinalExam(finalExam);
        score.computeTotal();

        scores.push_back(score);
    }

    return scores;
}
