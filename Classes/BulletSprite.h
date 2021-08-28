#ifndef _BULLET_SPRITE_H_
#define _BULLET_SPRITE_H_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class BulletSprite : public Sprite
{
private:
	Vec2 moveDir;
	float moveSpeed;
	bool isBulletDead;

public:
	enum EType {kX = 0, kC, kS, kLen
	};
private:
	char* bulletFileName[EType::kLen];
	EType eType;
public:
	BulletSprite();
	CREATE_FUNC(BulletSprite);
	bool init();
	bool init(EType _type, Vec2 _dir, float _speed);
	void update(float _dt);
};

#endif