#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_
#include "cocos2d.h"

USING_NS_CC;



class ScoreManager
{
private:
	static int score;

public:
	ScoreManager();
	static void setScore(int _n);
	static int getScore();
	static void addScore(int _n);

};





#endif
