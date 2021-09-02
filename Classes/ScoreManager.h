#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_
#include "cocos2d.h"
USING_NS_CC;

class ScoreManager
{
private:
	static int totalScore;
public:
	ScoreManager();
	static void setTotalScore(int _score);
	static int getTotalScore();
	static void addTotalScore(int _score);
};

#endif