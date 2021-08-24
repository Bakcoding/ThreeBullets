#include "BulletSprite.h"

bool BulletSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}