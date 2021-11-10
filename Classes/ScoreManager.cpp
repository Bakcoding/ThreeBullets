#include "ScoreManager.h"

// 게임씬 종료시에도 점수 유지하기 위해 전역 변수로 점수 관리
int ScoreManager::totalScore(0);

ScoreManager::ScoreManager() {}

// 점수 저장
void ScoreManager::setTotalScore(int _score)
{
	totalScore = _score;
}

// 점수 반환
int ScoreManager::getTotalScore()
{
	return totalScore;
}

// 점수 획득
void ScoreManager::addTotalScore(int _score)
{
	totalScore += _score;
}