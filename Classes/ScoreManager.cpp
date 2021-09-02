#include "ScoreManager.h"

int ScoreManager::totalScore(0);

ScoreManager::ScoreManager() {}

void ScoreManager::setTotalScore(int _score)
{
	totalScore = _score;
}

int ScoreManager::getTotalScore()
{
	return totalScore;
}

void ScoreManager::addTotalScore(int _score)
{
	totalScore += _score;
}