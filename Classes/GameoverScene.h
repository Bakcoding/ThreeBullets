#ifndef _GAMEOVER_SCENE_H_
#define _GAMEOVER_SCENE_H_
#include "cocos2d.h"
#include "CreateButton.h"
#include "GameScene.h"
#include "ScoreManager.h"

USING_NS_CC;
using namespace std;

class GameoverScene : public Scene
{
private:
	Size visibleSize;
	string retryFileName[3];
	string exitFileName[3];
	int totalScore;

public:
	GameoverScene();
	CREATE_FUNC(GameoverScene);
	virtual bool init() override;
	void gameoverSprite();
	void scoreLabel();
	bool initButton();
	void turnGameScene(Ref* _sender, Widget::TouchEventType _type);
	void exitApplication(Ref* _sender, Widget::TouchEventType _type);
};

#endif
