#ifndef SCORE_SERVICE_H
#define SCORE_SERVICE_H

#include "IScoreService.h"
#include "../../MODULE/HEADER/Score.h"
#include <vector>
#include <string>
#include <memory>
#include <expected>

class ScoreService : public IScoreService {
private:
    std::vector<Score> scores;

public:
    std::expected<void, std::string> loadFromFile(const std::string& filePath) override;
    std::expected<std::vector<Score>, std::string> getScoresBySection(const std::string& sectionID) const override;
    std::expected<std::vector<Score>, std::string> getAllScores() const override;
    std::expected<Score, std::string> getScoreByStudentAndSection(const std::string& studentID, const std::string& sectionID) const override;
    std::expected<std::vector<Score>, std::string> rankStudentsByTotalScore(const std::string& sectionID) const override;
};

#endif // SCORE_SERVICE_H
