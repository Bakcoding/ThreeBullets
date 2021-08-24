#ifndef _TITLE_SCENE_
#define _TITLE_SCENE_
#include "cocos2d.h"
#include "GameScene.h"
USING_NS_CC;

class TitleScene : public Scene
{
public:
	// 차일드에 태그를 붙이는 용도
	enum ETag {kStart = 0, kExit = 1};

	static TitleScene* createScene();
	CREATE_FUNC(TitleScene);
	virtual bool init() override;

	void initTitle();
	void initButton();

	void titlesceneCallBack(Ref* _sender);
};

#endif