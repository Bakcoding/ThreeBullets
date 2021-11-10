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

// 총알 초기화, 생성
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

// 총알 위치 갱신, 생성되면 위로 이동
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

// 총알 생명주기 체크, 화면 밖으로나가거나 적과 충돌시
bool BulletSprite::isDead()
{
	return isBulletDead;
}

// 총알의 종류 반환
BulletSprite::EType BulletSprite::getBulletType()
{
	return this->bulletType;
}