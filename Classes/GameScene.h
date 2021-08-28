#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "PlayerLayer.h"
#include "BulletLayer.h"
USING_NS_CC;

class GameScene : public Scene
{
public:
	static GameScene* createScene();
	static GameScene* create();
	//CREATE_FUNC(GameScene);
	virtual bool init() override;
};

#endif