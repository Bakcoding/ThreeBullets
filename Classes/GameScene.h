#ifndef _GAME_SCENE_
#define _GAME_SCENE_
#include "cocos2d.h"
#include "PlayerLayer.h"
USING_NS_CC;

class GameScene : public Scene
{
public:
	static GameScene* createScene();
	CREATE_FUNC(GameScene);
	virtual bool init() override;
};
#endif