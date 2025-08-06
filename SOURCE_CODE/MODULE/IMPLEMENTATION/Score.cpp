#include "Score.h"
#include "Student.h"
#include "ClassSection.h"
#include "FileManaging.h"
#include <sstream>

// Constructor gán sinh viên và lớp học phần tương ứng
Score::Score(Student* student, ClassSection* section)
    : studentID(student), sectionID(section) {}

// Getters
Student* Score::getStudent() const {
    return studentID;
}

ClassSection* Score::getSection() const {
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

// Hàm tính tổng điểm theo trọng số quy định (có thể tuỳ chỉnh nếu cần)
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


std::vector<Score> scoreParser::parse(const string& fileInput) {
    FileManager fm;
    vector<string> lines = fm.fileReader(fileInput);
    
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

        // Tạo Score với nullptr (sẽ ánh xạ sau)
        Score score(nullptr, nullptr);

        // Gán các giá trị
        score.setMidterm(midterm);
        score.setFinalExam(finalExam);
        // Bạn có thể gọi computeTotal() ở đây nếu cần
        score.computeTotal();

        scores.push_back(score);
    }

    return scores;
}