#ifndef _PLAYER_LAYER_H_
#define _PLAYER_LAYER_H_
#include "cocos2d.h"
#include "PlayerSprite.h"
#include "CreateButton.h"
#include "BulletLayer.h"

class PlayerLayer : public Layer
{
private:
	Vec2 playerPos;
	PlayerSprite* pPlayer;
	BulletLayer* pBullet;
	char* strPlayerFile;
	string strLeftButtonFile[3];
	string strRightButtonFile[3];
	Size visibleSize;
	float interval;
	Vector<BulletSprite*> bulletList;
public:
	enum EButton { kLeft = 0, kRight };
public:
	PlayerLayer();
	CREATE_FUNC(PlayerLayer);
	bool init();
	bool initPlayer();
	bool initButton();
	bool initBullet();
	void moveLeft(Ref* _sender, Widget::TouchEventType _type);
	void moveRight(Ref* _sender, Widget::TouchEventType _type);
	void update(float _dt);
	Vec2 getPlayerPosition();
	Vector<BulletSprite*> getBulletList();
	BulletLayer* getBulletLayer();
};
#endif