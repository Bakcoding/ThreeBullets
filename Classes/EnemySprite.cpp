#include "EnemySprite.h"

EnemySprite::EnemySprite() : isEnemyDead(false), moveSpeed(0), moveDir(Vec2::ZERO),
	fileName{"Enemy/XEnemy.png", "Enemy/CEnemy.png", "Enemy/SEnemy.png"},
	visibleSize(Director::getInstance()->getVisibleSize()){}

bool EnemySprite::init() 
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

bool EnemySprite::init(EType _type, float _speed, Vec2 _dir)
{
	if (!Sprite::initWithFile(fileName[_type]))
	{
		return false;
	}

	moveSpeed = _speed;
	moveDir = _dir;
	enemyType = _type;
	this->setScale(0.3f);

	this->scheduleUpdate();

	return true;
}

void EnemySprite::update(float _dt)
{
	enemyDeadline(_dt);
}

void EnemySprite::enemyDeadline(float _dt)
{
	if (isEnemyDead)
	{
		return;
	}

	Vec2 enemyPos = this->getPosition();
	Vec2 newPos = enemyPos;
	
	newPos += moveSpeed * moveDir * _dt;
	this->setPosition(newPos);

	if (this->getPosition().y < visibleSize.height * 0.23f)
	{
		isEnemyDead = true;
	}
}

bool EnemySprite::isDead()
{
	return isEnemyDead;
}

EnemySprite::EType EnemySprite::getEnemyType()
{
	return this->enemyType;
}