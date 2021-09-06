#ifndef _ENEMY_LAYER_H_
#define _ENEMY_LAYER_H_
#include "cocos2d.h"
#include "EnemySprite.h"
USING_NS_CC;

class EnemyLayer : public Layer
{
private:
	float moveSpeed;
	Vec2 moveDir;
	EnemySprite* pEnemySprite;
	Size visibleSize;
	EnemySprite::EType enemyType;

	Vector<EnemySprite*> enemyList;

	Vec2 refLane;
	Vec2 laneInterval;
public:
	EnemyLayer();
	CREATE_FUNC(EnemyLayer);
	virtual bool init() override;
	void update(float _dt) override;
	bool initEnemy();
	void enemySpawn(float _dt);
	void setEnemyType();
	void enemyProcess();
	void removeEnemy(int _idx);

	Vector<EnemySprite*> getEnemyList();
};

#endif