#ifndef _ENEMY_SPRITE_H_
#define _ENEMY_SPRITE_H_
#include "cocos2d.h"
USING_NS_CC;

class EnemySprite : public Sprite
{
public:
	enum EType {kXEnemy = 0, kCEnemy, kSEnemy, kLen};
private:
	bool isEnemyDead;
	float moveSpeed;
	Vec2 moveDir;
	char* fileName[EType::kLen];
	Size visibleSize;
	EType enemyType;
public:
	EnemySprite();
	CREATE_FUNC(EnemySprite);
	virtual bool init() override;
	bool init(EType _type, float _speed, Vec2 _dir);
	void update(float _dt) override;
	void enemyMove(float _dt);
	bool isDead();
	EType getEnemyType();
	void enemyAction();
	void setEnemyDead(bool _bool);
};
#endif