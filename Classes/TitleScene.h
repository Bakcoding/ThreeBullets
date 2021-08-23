#ifndef _TITLE_SCENE_
#define _TITLE_SCENE_
#include "cocos2d.h"
#include "GameScene.h"
USING_NS_CC;

class TitleScene : public Scene
{
public:
	enum ETag {kStart = 0, kExit = 1};

	static TitleScene* createScene();
	CREATE_FUNC(TitleScene);
	virtual bool init() override;


	void initTitle();
	void initButton();

	void titlesceneCallBack(Ref* _sender);
};

#endif