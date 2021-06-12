#ifndef _TITLE_SCENE_H_
#define _TITLE_SCENE_H_
#include "cocos2d.h"
#include "ManualScene.h"

USING_NS_CC;

class TitleScene : public Scene
{
public:
	enum ETag{kStart = 0, kExit = 1};

private:

public:
	TitleScene();
	virtual ~TitleScene();

	CREATE_FUNC(TitleScene);
	virtual bool init() override;

public:
	void InitTitle();
	void InitMenu();
	void playGameCallback(Ref* _sender);

};

#endif
