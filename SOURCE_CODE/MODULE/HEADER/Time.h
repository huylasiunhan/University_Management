#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>
#include <optional>
#include <expected>
#include <array>

// Enum đại diện cho các thứ trong tuần
enum class Day {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

// Enum đại diện cho buổi học
enum class Session {
    Morning,
    Afternoon
};

class Time {
private:
    // Mảng lưu tên lớp học tại từng thời điểm: [buổi][ngày]
    std::array<std::array<std::string, 6>, 2> schedule{};

public:
    // Constructor cần thiết cho việc khởi tạo lịch học
    Time(pair<int, int> scheduleIndex, const std::string& className);

    // Đánh dấu (đăng ký lớp học) tại một ngày + buổi
    void mark(const std::string& dayStr, const std::string& sessionStr, const std::string& className);

    // Bỏ đánh dấu (xóa lớp học) tại một ngày + buổi
    void unmark(const std::string& dayStr, const std::string& sessionStr);

    // Trả về true nếu tại thời điểm đó có lớp học
    bool isMarked(Day day, Session session) const;

    // Lấy tên lớp học tại một ngày + buổi (nếu có)
    std::string getClassAt(Day day, Session session) const;

    // In toàn bộ thời khóa biểu ra console
    void print() const;

    // ==========================
    // Các hàm static hỗ trợ xử lý chuỗi → enum (và ngược lại)
    // ==========================

    // Chuyển chuỗi → Day enum (throw exception nếu lỗi)
    static Day stringToDay(const std::string& dayStr);

    // Chuyển chuỗi → Session enum (throw exception nếu lỗi)
    static Session stringToSession(const std::string& sessionStr);

    // Chuyển chuỗi → Day enum (trả về optional)
    static std::optional<Day> tryStringToDay(const std::string& dayStr);

    // Chuyển chuỗi → Session enum (trả về optional)
    static std::optional<Session> tryStringToSession(const std::string& sessionStr);

    // Chuyển enum → chỉ số trong mảng
    static int dayToIndex(Day day);
    static int sessionToIndex(Session session);
};

#endif
