#include "ScoreManager.h"

int ScoreManager::score = 0;

ScoreManager::ScoreManager() {}
void ScoreManager::setScore(int _n)
{
	score = _n;
}

int ScoreManager::getScore()
{
	return score;
}

void ScoreManager::addScore(int _n)
{
	score += _n;
}