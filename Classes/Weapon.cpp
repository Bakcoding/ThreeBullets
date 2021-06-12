#include "Weapon.h"
#include "BulletSprite.h"

bool Weapon::init()
{
	if (!Node::init()) return false;

	return true;
}

BulletSprite* Weapon::Shoot(BulletSprite::EType _type)
{
	bullet = BulletSprite::create();
	if (bullet == nullptr || !bullet->initBullet(_type, 700.0f, Vec2(0.0f, 1.0f)))
	{
		return nullptr;
	}
	bullet->setPosition(this->convertToWorldSpace(this->getPosition()));
	bullet->setScale(0.25f);

	return bullet;
}