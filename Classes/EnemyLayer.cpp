#include "EnemyLayer.h"

EnemyLayer::EnemyLayer() :
	visibleSize(Director::getInstance()->getVisibleSize()), enemyList(NULL),
	moveSpeed(300.0f), moveDir(Vec2(0, -1)), pEnemySprite(NULL), laneInterval(visibleSize.width * 0.2f, 0),
	refLane(visibleSize.width * 0.1f, visibleSize.height) {}
bool EnemyLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	srand(unsigned int(time(NULL)));

	this->schedule(CC_SCHEDULE_SELECTOR(EnemyLayer::enemySpawn), 0.8f, CC_REPEAT_FOREVER, 3.0f);
	this->scheduleUpdate();

	return true;
}

void EnemyLayer::update(float _dt)
{
	// enemyProcess();
}

bool EnemyLayer::initEnemy()
{
	pEnemySprite = EnemySprite::create();

	if (pEnemySprite == NULL || !pEnemySprite->init(enemyType, moveSpeed, moveDir))
	{
		return false;
	}

	return true;
}

void EnemyLayer::enemySpawn(float _dt)
{
	setEnemyType();
	initEnemy();

	int randLane = rand() % 5;
	
	switch(randLane)
	{
		case 0:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 1:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 2:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 3:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 4:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
	}
}

void EnemyLayer::setEnemyType()
{
	int randType = rand() % 3 + 1;

	if (randType == 1)
	{
		enemyType = EnemySprite::EType::kXEnemy;
	}
	else if (randType == 2)
	{
		enemyType = EnemySprite::EType::kCEnemy;
	}
	else
	{
		enemyType = EnemySprite::EType::kSEnemy;
	}
}

void EnemyLayer::enemyProcess()
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		if (enemyList.at(i)->isDead())
		{
			removeEnemy(i);
		}
	}
}

void EnemyLayer::removeEnemy(int _idx)
{
	this->removeChild(enemyList.at(_idx));
	enemyList.erase(_idx);
}

Vector<EnemySprite*> EnemyLayer::getEnemyList()
{
	return this->enemyList;
}