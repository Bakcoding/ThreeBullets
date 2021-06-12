#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "GameOverScene.h"
#include "CharLayer.h"
#include "EnemyLayer.h"
#include "BGLayer.h"

USING_NS_CC;

class Effect;

class GameScene : public Scene
{
private:
	int Life;
	int i;
	int j;
	int Score;


	BGLayer* pBGLayer;
	CharLayer* pCharLayer;
	EnemyLayer* pEnemyLayer;
	Effect* pEffect;

	Rect bulletbox;
	Rect enemybox;

	Vector<BulletSprite*> playerbulletlist;
	Vector<EnemySprite*> enemylist;

public:
	GameScene();
	virtual ~GameScene();

	static GameScene* createScene();
	static GameScene* create();
	virtual bool init() override;
	void update(float _dt);

public:
	void CheckCollision();
	void EnemyReach();
	void lifecount();
	void AddScore(int _n);
	void loseLife(int _n);

public:
	void ScoreInit();
	void ScorePrint();
	void Lifeinit();
	void LifePrint();	
}; 

#endif