#ifndef ISCHEDULESERVICE_H
#define ISCHEDULESERVICE_H

#include <string>
#include <optional>
#include <expected>  // C++23

class IScheduleService {
public:
    virtual ~IScheduleService() = default;

    // Trả về expected<void, std::string> để báo lỗi nếu có
    virtual std::expected<void, std::string> addClass(const std::string& day, const std::string& session, const std::string& className) = 0;

    virtual std::expected<void, std::string> removeClass(const std::string& day, const std::string& session) = 0;

    // Trả về expected<string, string>: string là tên lớp nếu có, lỗi nếu slot không hợp lệ
    virtual std::expected<std::string, std::string> getClassAt(const std::string& day, const std::string& session) const = 0;

    virtual void printSchedule() const = 0;
};

#endif