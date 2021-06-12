#ifndef _ENEMY_SPRITE_H_
#define _ENEMY_SPRITE_H_
#include "cocos2d.h"

USING_NS_CC;

class EnemySprite : public Sprite
{
public:
	enum EType {kEX, kEC, kES, kLen};
	char* m_fileNames[EType::kLen];

private:
	bool m_eIsDead;
	Vec2 m_vDir;
	float m_fMoveSpeed;
	EType m_Etype;
	Vec2 newPos;

public:
	EnemySprite();

	CREATE_FUNC(EnemySprite);
	virtual bool init() override;
	bool initEnemy(EType _type, float m_moveSpeed, Vec2 _dir);
	void update(float _dt);

public:
	bool IsDead() const;
	EType GetType();
	void OnAction();
};

#endif