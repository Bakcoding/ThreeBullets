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
	enemyMove(_dt);
}

void EnemySprite::enemyMove(float _dt)
{
	if (isEnemyDead)
	{
		return;
	}

	Vec2 newPos = this->getPosition();
	
	newPos += moveSpeed * moveDir * _dt;
	this->setPosition(newPos);

	if (this->getPosition().y < visibleSize.height * 0.23f)
	{
		isEnemyDead = true;
	}
}

bool EnemySprite::isDead()
{
	return this->isEnemyDead;
}

void EnemySprite::setEnemyDead(bool _bool)
{
	this->isEnemyDead = _bool;
}

EnemySprite::EType EnemySprite::getEnemyType()
{
	return this->enemyType;
}

void EnemySprite::enemyAction()
{
	Action* rotate = RotateBy::create(3.0f, 500.0f);
	this->runAction(rotate);
}