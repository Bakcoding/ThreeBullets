#ifndef _WEAPON_H_
#define _WEAPON_H_
#include "cocos2d.h"
#include "WeaponNode.h"

USING_NS_CC;

class Weapon : public WeaponNode
{
public:


private:
	BulletSprite* bullet;

public:
	//SetBullet();
	CREATE_FUNC(Weapon);
	virtual bool init() override;

public:
	BulletSprite* Shoot(BulletSprite::EType _type) override;
};


#endif