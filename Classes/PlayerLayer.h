#ifndef _PLAYER_LAYER_H_
#define _PLAYER_LAYER_H_
#include "cocos2d.h"
#include "CreateButton.h"
USING_NS_CC;

class PlayerLayer : public Layer
{
private:
	Sprite* pPlayer;
	string strPlayerFile;
	string strLeftButtonFile[3];
	string strRightButtonFile[3];
	Size visibleSize;
	float interval;

public:
	enum EButton { kLeft = 0, kRight };
public:
	PlayerLayer();
	CREATE_FUNC(PlayerLayer);
	bool init();
	void initPlayer();
	void initButton();
	void moveLeft(Ref* _sender, Widget::TouchEventType _type);
	void moveRight(Ref* _sender, Widget::TouchEventType _type);
};
#endif