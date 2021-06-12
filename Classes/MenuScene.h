#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;

class MenuScene : public Scene
{
public:
	enum ETag{kStart = 0, kExit = 1};
private:

public:
	MenuScene();
	virtual ~MenuScene();

	CREATE_FUNC(MenuScene);
	virtual bool init() override;

public:
	void startGameCallback(Ref* _sender);

};

#endif
