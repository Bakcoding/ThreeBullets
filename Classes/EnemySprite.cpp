#include "EnemySprite.h"

EnemySprite::EnemySprite() : 
	m_eIsDead(false), m_vDir(Vec2::ZERO), m_fMoveSpeed(0.0f), newPos(Vec2::ZERO),
m_fileNames{"Character/EnemyX.png", "Character/EnemyC.png", "Character/EnemyS.png"} {}

bool EnemySprite::init()
{
	if (!Sprite::init()) return false;

	return true;
}

bool EnemySprite::initEnemy(EType _type, float _moveSpeed, Vec2 _dir)
{
	if (!Sprite::initWithFile(m_fileNames[_type])) return false;

	m_fMoveSpeed = _moveSpeed;
	m_vDir = _dir;
	m_Etype = _type;

	this->scheduleUpdate();

	return true;
}

void EnemySprite::update(float _dt)
{	
	if (m_eIsDead) return;

	newPos = this->getPosition();
	newPos = newPos + (m_vDir * m_fMoveSpeed * _dt);
	this->setPosition(newPos);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	if (newPos.y < visibleSize.height - 580)
	{
		m_eIsDead = true;
	}
}

bool EnemySprite::IsDead() const
{
	return m_eIsDead;
}

EnemySprite::EType EnemySprite::GetType()
{
	return m_Etype;
}

void EnemySprite::OnAction()
{
	Action* rotate = RotateBy::create(3.0f, 500.0f);
	this->runAction(rotate);
}