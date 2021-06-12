#include "BulletSprite.h"

BulletSprite::BulletSprite() : m_bIsDead(false), m_vDir(Vec2::ZERO), m_fMoveSpeed(0.0f), 
							   m_cFilenames{"Bullet/BulletX.png", "Bullet/BulletCircle.png", "Bullet/BulletSquare.png"} {}

bool BulletSprite::init()
{
	if (!Sprite::init()) return false;

	return true;
}

bool BulletSprite::initBullet(EType _type, float _moveSpeed, Vec2 _dir)
{
	if (!Sprite::initWithFile(m_cFilenames[_type])) return false;

	m_fMoveSpeed = _moveSpeed;
	m_vDir = _dir;
	m_type = _type;

	this->scheduleUpdate();

	return true;
}

void BulletSprite::update(float _dt)
{
	if (m_bIsDead) return;

	Vec2 newPos = this->getPosition();
	newPos = newPos + (m_vDir * m_fMoveSpeed * _dt);
	this->setPosition(newPos);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	if (newPos.y > visibleSize.height)
	{
		m_bIsDead = true;
	}
}

bool BulletSprite::IsDead() const
{
	return m_bIsDead;
}

BulletSprite::EType BulletSprite::GetType()
{
	return m_type;
}
