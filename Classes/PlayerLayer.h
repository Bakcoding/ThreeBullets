#ifndef _PLAYER_LAYER_
#define _PLAYER_LAYER_
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class PlayerLayer : public Layer
{
private:
	Sprite* pPlayer;
	Size winSize;
	Vec2 currentPos;
	float buttonPadding;


public:	
	PlayerLayer();
	~PlayerLayer();
	// 플레이어 움직임 관련
	enum EButton { kLeft = 0, kRight = 1, kX = 2, kCircle = 3, kRect = 4 };

public:
	CREATE_FUNC(PlayerLayer);
	bool virtual init() override;

	void initPlayer();
	void initButton();

	void moveLeft();
	void moveRight();
	void playerAction(Ref* _sender);
};

#endif