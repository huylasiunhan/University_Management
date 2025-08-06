#include "../HEADER/Time.h"

// Chuyển từ chuỗi ngày ("Monday", "mon",...) sang enum Day
Day Time::stringToDay(const std::string& dayStr) {
    std::string d = dayStr;
    std::transform(d.begin(), d.end(), d.begin(), ::tolower); // đưa về chữ thường

    if (d == "monday" || d == "mon") return Day::Monday;
    if (d == "tuesday" || d == "tue") return Day::Tuesday;
    if (d == "wednesday" || d == "wed") return Day::Wednesday;
    if (d == "thursday" || d == "thu") return Day::Thursday;
    if (d == "friday" || d == "fri") return Day::Friday;
    if (d == "saturday" || d == "sat") return Day::Saturday;

    throw std::invalid_argument("Invalid day: " + dayStr);
}

// Chuyển từ chuỗi buổi ("Morning", "Afternoon") sang enum Session
Session Time::stringToSession(const std::string& sessionStr) {
    std::string s = sessionStr;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower); // đưa về chữ thường

    if (s == "morning") return Session::Morning;
    if (s == "afternoon") return Session::Afternoon;

    throw std::invalid_argument("Invalid session: " + sessionStr);
}

// Chuyển enum Day thành chỉ số để truy cập mảng
int Time::dayToIndex(Day day) {
    return static_cast<int>(day); // Monday = 0, ..., Saturday = 5
}

// Chuyển enum Session thành chỉ số để truy cập mảng
int Time::sessionToIndex(Session session) {
    return static_cast<int>(session); // Morning = 0, Afternoon = 1
}

// Đánh dấu buổi học là có lớp (gán = 1)
void Time::mark(const std::string& dayStr, const std::string& sessionStr) {
    Day day = stringToDay(dayStr);
    Session session = stringToSession(sessionStr);
    schedule[sessionToIndex(session)][dayToIndex(day)] = 1;
}

// Xóa đánh dấu buổi học (gán lại = 0)
void Time::unmark(const std::string& dayStr, const std::string& sessionStr) {
    Day day = stringToDay(dayStr);
    Session session = stringToSession(sessionStr);
    schedule[sessionToIndex(session)][dayToIndex(day)] = 0;
}

// Trả về true nếu đã đánh dấu buổi học (tức là có lớp học tại thời điểm đó)
bool Time::isMarked(Day day, Session session) const {
    return schedule[sessionToIndex(session)][dayToIndex(day)] == 1;
}

// In lịch học dưới dạng bảng
void Time::print() const {
    std::cout << "Schedule:\n";
    for (int row = 0; row < 2; ++row) {
        std::cout << (row == 0 ? "Morning:   " : "Afternoon: ");
        for (int col = 0; col < 6; ++col) {
            std::cout << schedule[row][col] << " ";
        }
        std::cout << "\n";
    }
}