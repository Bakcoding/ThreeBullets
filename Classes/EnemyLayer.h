#ifndef _ENEMY_LAYER_H_
#define _ENEMY_LAYER_H_
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class EnemySprite;

class EnemyLayer : public Layer
{
public:


private:
	Size m_visibleSize;
	Vector<EnemySprite*>m_EnemyList;

	EnemySprite* Enemy;


public:
	EnemyLayer();
	CREATE_FUNC(EnemyLayer);
	virtual bool init() override;

	void update(float _dt);
	void Spawn(float _dt);
public:
	void EnemyProcess();

	Vector<EnemySprite*> GetEnemyList();
	void RemoveEnemylist(int _idx);

};

#endif

