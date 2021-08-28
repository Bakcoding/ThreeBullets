#ifndef _PLAYER_SPRITE_H_
#define _PLAYER_SPRITE_H_
#include "cocos2d.h"
#include "BulletLayer.h"
USING_NS_CC;
using namespace std;

class PlayerSprite : public Sprite
{
private:
	Size visibleSize;
	Vec2 playerPos;
	
public:
	PlayerSprite();
	CREATE_FUNC(PlayerSprite);
	virtual bool init() override;
	bool init(const char* _fileName, Vec2 _pos);
	void moveLeft();
	void moveRight();
};
#endif