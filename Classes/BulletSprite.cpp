#include "BulletSprite.h"

BulletSprite::BulletSprite() : moveDir(Vec2::ZERO), moveSpeed(0), isBulletDead(false),
bulletFileName{ "Bullet/XBullet.png", "Bullet/CBullet.png", "Bullet/SBullet.png" } {}

bool BulletSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

bool BulletSprite::init(EType _type, Vec2 _dir, float _speed)
{
	if (!Sprite::initWithFile(bulletFileName[_type]))
	{
		return false;
	}

	moveDir = _dir;
	moveSpeed = _speed;
	bulletType = _type;

	this->scheduleUpdate();
	
	return true;
}

void BulletSprite::update(float _dt)
{
	if (isBulletDead)
	{
		return;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 newPos = this->getPosition();
	newPos += moveSpeed * moveDir * _dt;
	this->setPosition(newPos);
	newPos = this->getPosition();

	if (newPos.y > visibleSize.height)
	{
		isBulletDead = true;
	}
}

bool BulletSprite::isDead()
{
	return isBulletDead;
}

BulletSprite::EType BulletSprite::getBulletType()
{
	return this->bulletType;
}