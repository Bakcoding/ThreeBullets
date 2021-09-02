#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"
#include "BackgroundLayer.h"
#include "GameoverScene.h"
#include "ScoreManager.h"
USING_NS_CC;

class GameScene : public Scene
{
public:
	enum EType {kDraw, kWin, kLose, kError};

private:
	PlayerLayer* pPlayer;
	EnemyLayer* pEnemy;
	BulletLayer* pBullet;
	Vector<BulletSprite*> bulletList;
	Vector<EnemySprite*> enemyList;
	Rect bulletBox;
	Rect enemyBox;
	BackgroundLayer* pBGLayer;
	int life;
	int point;
	int score;
	int enemyPoint;
	bool isGameover;

public:
	GameScene();
	CREATE_FUNC(GameScene);
	virtual bool init() override;
	void update(float _dt);
	void collisionProcess();
	void matchResult(int _val, int _eCount, int _bCount);
	int compareType(EnemySprite* _enemy, BulletSprite* _bullet);
	void setLabelValue();
	void addScore(int _score);
	void loseLife();
	void enemyProcess();
	void gameOver();
};
#endif