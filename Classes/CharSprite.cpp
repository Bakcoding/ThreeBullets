#include "CharSprite.h"
#include "WeaponNode.h"

CharSprite::CharSprite() : m_fSpeed(0.0f), m_pBullet(nullptr) {}
bool CharSprite::init()
{
	if (!Sprite::init()) return false;


	return true;
}

bool CharSprite::init(const char* _flieName, float _moveSpeed)
{
	if (!Sprite::initWithFile(_flieName)) return false;

	m_fSpeed = _moveSpeed;
	
	return true;
}

BulletSprite* CharSprite::Shoot(BulletSprite::EType _type)
{
	if (m_pBullet)
	{
		return m_pBullet->Shoot(_type);
	}
	return nullptr;
}

void CharSprite::Setbullet(WeaponNode* _bullet)
{
	if (_bullet == nullptr) return;
	if (m_pBullet != nullptr)
	{
		this->removeChild(dynamic_cast<Node*>(m_pBullet), true);
	}
	m_pBullet = _bullet;
	Size contentSize = this->getContentSize();
	m_pBullet->setAnchorPoint(Vec2(0.5f, 0.5f));
	m_pBullet->setPosition(Vec2(contentSize.width * 0.25f, contentSize.height * 0.5f));
	this->addChild(m_pBullet);
}

