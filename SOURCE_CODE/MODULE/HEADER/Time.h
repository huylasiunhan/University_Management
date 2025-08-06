#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>

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
    // Mảng 2D: schedule[session][day], lưu lịch học
    // 0: không có lớp, 1: có lớp
    int schedule[2][6] = {}; // 2 buổi * 6 ngày (Thứ 2 đến Thứ 7)

public:
    // Đánh dấu 1 buổi học cụ thể là đã có lớp
    void mark(const std::string& dayStr, const std::string& sessionStr);

    // Bỏ đánh dấu buổi học (xóa lớp học tại thời điểm đó)
    void unmark(const std::string& dayStr, const std::string& sessionStr);

    // Kiểm tra xem tại thời điểm đó có lớp không
    bool isMarked(Day day, Session session) const;

    // In toàn bộ thời khóa biểu
    void print() const;

    // Chuyển từ chuỗi → Enum Day
    static Day stringToDay(const std::string& dayStr);

    // Chuyển từ chuỗi → Enum Session
    static Session stringToSession(const std::string& sessionStr);

    // Chuyển Day enum thành chỉ số index trong mảng
    static int dayToIndex(Day day);

    // Chuyển Session enum thành chỉ số index trong mảng
    static int sessionToIndex(Session session);
};

#endif