#ifndef _CHAR_LAYER_H_
#define _CHAR_LAYER_H_
#include "cocos2d.h"
#include "EnemyLayer.h"


USING_NS_CC;

class CharSprite;
class WeaponNode;
class BulletSprite;

class CharLayer : public Layer
{
public:

private:
	Size m_visibleSize;
	CharSprite* m_pPlayer;
	Vec2 setPos;
	Vector<BulletSprite*>m_playerBulletList;

	BulletSprite* bulletX;
	BulletSprite* bulletC;
	BulletSprite* bulletS;

public:
	CharLayer();
	virtual ~CharLayer();
	static CharLayer* create();
	virtual bool init() override;
	virtual void update(float _dt) override;

	bool InitPlayer();
	virtual void onKeyPressed(EventKeyboard::KeyCode _keyCode, Event* _event);

	void MoveLeft();
	void MoveRight();

private:
	void BulletProcess();

public:
	Vector<BulletSprite*> GetPlayerBulletList();
	void RemoveBulletlist(int _idx);


};
#endif