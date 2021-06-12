#ifndef _CHAR_SPRITE_H_
#define _CHAR_SPRITE_H_
#include "cocos2d.h"
#include "BulletSprite.h"

USING_NS_CC;

class WeaponNode;

class CharSprite : public Sprite
{
private:
	float m_fSpeed;
	WeaponNode* m_pBullet;

public:
	CharSprite();

	CREATE_FUNC(CharSprite);
	virtual bool init() override;
	bool init(const char* _filName, float _speed);


public:
	BulletSprite* Shoot(BulletSprite::EType _type);

public:
	void Setbullet(WeaponNode* _bullet);
};


#endif 