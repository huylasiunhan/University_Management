#ifndef I_SCORE_SERVICE_H
#define I_SCORE_SERVICE_H

#include "../../MODULE/HEADER/Score.h"
#include <vector>
#include <string>
#include <expected>

class IScoreService {
public:
    virtual ~IScoreService() = default;

    virtual std::expected<void, std::string> loadFromFile(const std::string& filePath) = 0;
    virtual std::expected<std::vector<Score>, std::string> getScoresBySection(const std::string& sectionID) const = 0;
    virtual std::expected<std::vector<Score>, std::string> getAllScores() const = 0;
    virtual std::expected<Score, std::string> getScoreByStudentAndSection(const std::string& studentID, const std::string& sectionID) const = 0;
    virtual std::expected<std::vector<Score>, std::string> rankStudentsByTotalScore(const std::string& sectionID) const = 0;
};

#endif // I_SCORE_SERVICE_H
