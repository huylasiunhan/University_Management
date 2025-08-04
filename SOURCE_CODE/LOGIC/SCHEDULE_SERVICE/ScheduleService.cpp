#include "ScheduleService.h"
using namespace std;

ScheduleService::ScheduleService(shared_ptr<Time> time)
    : time_(std::move(time)) {}

expected<void, string> ScheduleService::addClass(const string& day, const string& session, const string& className) {
    try {
        time_->mark(day, session, className);
        return {};
    } catch (const exception& e) {
        return unexpected(e.what());
    }
}

expected<void, string> ScheduleService::removeClass(const string& day, const string& session) {
    try {
        time_->unmark(day, session);
        return {};
    } catch (const exception& e) {
        return unexpected(e.what());
    }
}

expected<string, string> ScheduleService::getClassAt(const string& day, const string& session) const {
    try {
        Day d = Time::stringToDay(day);
        Session s = Time::stringToSession(session);
        string result = time_->getClassAt(d, s);
        return result;
    } catch (const exception& e) {
        return unexpected(e.what());
    }
}

void ScheduleService::printSchedule() const {
    time_->print();
}
