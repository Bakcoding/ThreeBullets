#ifndef _BULLET_SPRITE_H_
#define _BULLET_SPRITE_H_
#include "cocos2d.h"

USING_NS_CC;

class BulletSprite : public Sprite
{
public:
	enum EType { kX, kC, kS, kLen };
	char* m_cFilenames[EType::kLen];

private:
	bool m_bIsDead;
	Vec2 m_vDir;
	float m_fMoveSpeed;
	EType m_type;

public:
	BulletSprite();

	CREATE_FUNC(BulletSprite);
	virtual bool init() override;

	bool initBullet(EType _type, float m_moveSpeed, Vec2 _dir);
	void update(float _dt);

public:
	bool IsDead() const;
	EType GetType();

};

#endif