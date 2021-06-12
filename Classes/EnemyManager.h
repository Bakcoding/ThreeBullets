#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_
#include "cocos2d.h"

USING_NS_CC;

class EnemyLayer;
class CharLayer;
//class EnemySprite;
//class CharSprite;


class EnemyManager : public Node
{
private:



public:
	EnemyManager();
	virtual ~EnemyManager();
	CREATE_FUNC(EnemyManager);
	virtual bool init() override;


	void update();
};

#endif
