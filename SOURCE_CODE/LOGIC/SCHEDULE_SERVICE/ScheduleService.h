#ifndef SCHEDULE_SERVICE_H
#define SCHEDULE_SERVICE_H

#include "IScheduleService.h"
#include "../../MODULE/HEADER/Time.h"
#include <memory>

class ScheduleService : public IScheduleService {
private:
    std::shared_ptr<Time> time_;

public:
    explicit ScheduleService(std::shared_ptr<Time> time);

    std::expected<void, std::string> addClass(const std::string& day, const std::string& session, const std::string& className) override;
    std::expected<void, std::string> removeClass(const std::string& day, const std::string& session) override;
    std::expected<std::string, std::string> getClassAt(const std::string& day, const std::string& session) const override;
    void printSchedule() const override;
};

#endif
