#ifndef _BULLET_SPRITE_
#define _BULLET_SPRITE_
#include "cocos2d.h"
USING_NS_CC;

class BulletSprite : public Sprite
{
public:
	CREATE_FUNC(BulletSprite);
	bool virtual init() override;
};
#endif