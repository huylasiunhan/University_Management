#include "Time.h"
#include <algorithm>
#include <utility>

using namespace std;

// Constructor to initialize the schedule with a class name at a specific index
Time::Time(pair<int, int> scheduleIndex, const std::string& className) {
    // Initialize the schedule with empty strings
    for (auto& session : schedule) {
        session.fill("");
    }
    // Mark the class at the specified index
    if (scheduleIndex.first >= 0 && scheduleIndex.first < 2 &&
        scheduleIndex.second >= 0 && scheduleIndex.second < 6) {
        schedule[scheduleIndex.first][scheduleIndex.second] = className;
    } else {
        throw std::out_of_range("Invalid schedule index");
    }
}
void Time::mark(const std::string& dayStr, const std::string& sessionStr, const std::string& className) {
    Day day = stringToDay(dayStr);
    Session session = stringToSession(sessionStr);
    schedule[sessionToIndex(session)][dayToIndex(day)] = className;
}

void Time::unmark(const std::string& dayStr, const std::string& sessionStr) {
    Day day = stringToDay(dayStr);
    Session session = stringToSession(sessionStr);
    schedule[sessionToIndex(session)][dayToIndex(day)] = "";
}

bool Time::isMarked(Day day, Session session) const {
    return !schedule[sessionToIndex(session)][dayToIndex(day)].empty();
}

std::string Time::getClassAt(Day day, Session session) const {
    return schedule[sessionToIndex(session)][dayToIndex(day)];
}

void Time::print() const {
    const std::string days[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const std::string sessions[] = {"Morning", "Afternoon"};

    std::cout << "Schedule:\n\t";
    for (const auto& day : days) {
        std::cout << day << "\t";
    }
    std::cout << "\n";

    for (int i = 0; i < 2; ++i) {
        std::cout << sessions[i] << ":\t";
        for (int j = 0; j < 6; ++j) {
            const std::string& className = schedule[i][j];
            std::cout << (className.empty() ? "-" : className) << "\t";
        }
        std::cout << "\n";
    }
}

// ============ SAFE STRING PARSING (optional-based) =============

std::optional<Day> Time::tryStringToDay(const std::string& dayStr) {
    std::string day = dayStr;
    std::transform(day.begin(), day.end(), day.begin(), ::tolower);
    if (day == "monday" || day == "mon") return Day::Monday;
    if (day == "tuesday" || day == "tue") return Day::Tuesday;
    if (day == "wednesday" || day == "wed") return Day::Wednesday;
    if (day == "thursday" || day == "thu") return Day::Thursday;
    if (day == "friday" || day == "fri") return Day::Friday;
    if (day == "saturday" || day == "sat") return Day::Saturday;
    return std::nullopt;
}

std::optional<Session> Time::tryStringToSession(const std::string& sessionStr) {
    std::string session = sessionStr;
    std::transform(session.begin(), session.end(), session.begin(), ::tolower);
    if (session == "morning") return Session::Morning;
    if (session == "afternoon") return Session::Afternoon;
    return std::nullopt;
}

// ============ THROW-BASED STRING PARSING (for older API) =============

Day Time::stringToDay(const std::string& dayStr) {
    auto result = tryStringToDay(dayStr);
    if (!result) throw std::invalid_argument("Invalid day: " + dayStr);
    return *result;
}

Session Time::stringToSession(const std::string& sessionStr) {
    auto result = tryStringToSession(sessionStr);
    if (!result) throw std::invalid_argument("Invalid session: " + sessionStr);
    return *result;
}


// ============ MAPPING ENUM TO INDEX =============

int Time::dayToIndex(Day day) {
    return static_cast<int>(day);
}

int Time::sessionToIndex(Session session) {
    return static_cast<int>(session);
}
