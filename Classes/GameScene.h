#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"
#include "BackgroundSprite.h"
USING_NS_CC;

class GameScene : public Scene
{
public:
	enum EType {kDraw, kWin, kLose, kError};

private:
	PlayerLayer* pPlayer;
	EnemyLayer* pEnemy;
	BulletLayer* pBulletLayer;
	Vector<BulletSprite*> bulletList;
	Vector<EnemySprite*> enemyList;
	Rect bulletBox;
	Rect enemyBox;

public:
	CREATE_FUNC(GameScene);
	virtual bool init() override;
	void update(float _dt);
	void collisionProcess();
	void matchResult(int _val, int _eCount, int _bCount);
	int compareType(EnemySprite* _enemy, BulletSprite* _bullet);
};

#endif