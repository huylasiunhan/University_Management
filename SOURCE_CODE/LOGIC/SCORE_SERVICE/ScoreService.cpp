#include "ScoreService.h"
#include <algorithm>
#include <iostream>
#include "../../MODULE/HEADER/Student.h"
#include "../../MODULE/HEADER/ClassSection.h"


using namespace std;

std::expected<void, string> ScoreService::loadFromFile(const string& filePath) {
    try {
        ScoreParser parser;
        scores = parser.parse(filePath);
        return {};
    } catch (const exception& e) {
        return unexpected(e.what());
    }
}

std::expected<vector<Score>, string> ScoreService::getScoresBySection(const string& sectionID) const {
    vector<Score> result;

    for (const auto& score : scores) {
        if (score.getSection() && score.getSection()->getClassID() == sectionID) {
            result.push_back(score);
        }
    }

    if (result.empty())
        return unexpected("No scores found for section ID: " + sectionID);

    return result;
}

std::expected<vector<Score>, string> ScoreService::getAllScores() const {
    return scores;
}

std::expected<Score, string> ScoreService::getScoreByStudentAndSection(const string& studentID, const string& sectionID) const {
    for (const auto& score : scores) {
        if (score.getStudent() && score.getSection() &&
            score.getStudent()->getID() == studentID &&
            score.getSection()->getClassID() == sectionID) {
            return score;
        }
    }

    return unexpected("No score found for student ID: " + studentID + " in section: " + sectionID);
}

std::expected<vector<Score>, string> ScoreService::rankStudentsByTotalScore(const string& sectionID) const {
    auto resultExp = getScoresBySection(sectionID);
    if (!resultExp)
        return unexpected(resultExp.error());

    auto result = resultExp.value();

    std::sort(result.begin(), result.end(), [](const Score& a, const Score& b) {
        return a.getTotal() > b.getTotal();
    });

    return result;
}
