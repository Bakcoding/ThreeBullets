#include "ScoreManager.h"

// ���Ӿ� ����ÿ��� ���� �����ϱ� ���� ���� ������ ���� ����
int ScoreManager::totalScore(0);

ScoreManager::ScoreManager() {}

// ���� ����
void ScoreManager::setTotalScore(int _score)
{
	totalScore = _score;
}

// ���� ��ȯ
int ScoreManager::getTotalScore()
{
	return totalScore;
}

// ���� ȹ��
void ScoreManager::addTotalScore(int _score)
{
	totalScore += _score;
}