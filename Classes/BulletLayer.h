#ifndef _BULLET_LAYER_H_
#define _BULLET_LAYER_H_
#include "cocos2d.h"
#include "CreateButton.h"
#include "BulletSprite.h"

class BulletLayer : public Layer
{
private:
	CreateButton* xButton;
	CreateButton* cButton;
	CreateButton* sButton;

	BulletSprite* bullet;
	
	Vector<BulletSprite*> bulletList;

	Size visibleSize;

	Vec2 moveDir;
	float moveSpeed;
	bool bulletIsDead;
	Vec2 playerPos;

	string strXBullet;
	string strCBullet;
	string strSBullet;

	string strXButton[3];
	string strCButton[3];
	string strSButton[3];
public:
	BulletLayer();
	CREATE_FUNC(BulletLayer);
	bool init();
	void update(float _dt);
	bool initButton();
	void setBulletPos(Vec2 _pos);
	void touchXButton(Ref* _sender, Widget::TouchEventType _type);
	void touchCButton(Ref* _sender, Widget::TouchEventType _type);
	void touchSButton(Ref* _sender, Widget::TouchEventType _type);
	void bulletProcess();
	void removeBullet(int _idx);

	BulletSprite* shootBullet(BulletSprite::EType _type);
	Vector<BulletSprite*> getBulletList();
};
#endif