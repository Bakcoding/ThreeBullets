#ifndef _GAME_OVER_SCENE_H_
#define _GAME_OVER_SCENE_H_
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;

class GameOverScene : public Scene
{
private:
	int score;

public:
	enum ETag{kRetry = 0, kExit};

public:
	GameOverScene();
	virtual ~GameOverScene();

	CREATE_FUNC(GameOverScene);
	virtual bool init() override;
	void update(float _dt);

	

public:
	void GameOverCallback(Ref* _sender);
	void InitGameOver();
	void InitButton();

	void InitLabel();
};

#endif