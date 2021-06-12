#ifndef _WEAPON_NODE_H_
#define _WEAPON_NODE_H_
#include "cocos2d.h"
#include "BulletSprite.h"

USING_NS_CC;

//class BulletSprite;

class WeaponNode : public Node
{
private:

public:
	// 순수 가상 함수
	virtual BulletSprite* Shoot(BulletSprite::EType _type) = 0;
};

#endif