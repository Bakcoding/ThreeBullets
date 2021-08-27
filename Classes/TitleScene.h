#ifndef _TITLE_SCENE_H
#define _TITLE_SCENE_H
#include "cocos2d.h"
#include "ButtonNode.h"
#include "GameScene.h"
USING_NS_CC;

class TitleScene : public Scene
{
private:
	Size visibleSize;
	string strStartButton[4];
	string strExitButton[4];

	ButtonNode* pStartButton;
	ButtonNode* pExitButton;

public:
	TitleScene();
	CREATE_FUNC(TitleScene);
	virtual bool init() override;

	void titleImageInit();
	void buttonInit();

	void nextScene(Ref* _sender, Widget::TouchEventType _type);
	void exitGame(Ref* _sender, Widget::TouchEventType _type);
};



#endif