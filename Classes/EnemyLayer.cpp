#include "EnemyLayer.h"

EnemyLayer::EnemyLayer() :
	visibleSize(Director::getInstance()->getVisibleSize()), enemyList(NULL), enemyType(EnemySprite::EType::kCEnemy), 
	moveSpeed(300.0f), moveDir(Vec2(0, -1)), pEnemySprite(NULL), laneInterval(visibleSize.width * 0.2f, 0),
	refLane(visibleSize.width * 0.1f, visibleSize.height) {}

// 적 생성
bool EnemyLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->schedule(CC_SCHEDULE_SELECTOR(EnemyLayer::enemySpawn), 0.8f, CC_REPEAT_FOREVER, 3.0f);

	this->scheduleUpdate();

	return true;
}

// 적 초기화, 생성
bool EnemyLayer::initEnemy()
{
	pEnemySprite = EnemySprite::create();

	if (pEnemySprite == NULL || !pEnemySprite->init(enemyType, moveSpeed, moveDir))
	{
		return false;
	}

	return true;
}

// 적 생성 위치
void EnemyLayer::enemySpawn(float _dt)
{
	srand(int(time(NULL)));
	// 무작위 타입의 적 세팅
	setEnemyType();
	// 적 생성
	initEnemy();
	// 무작위 위치, 5개의 레인 중 하나
	int randLane = rand() % 5;
	
	// 랜덤한 하나의 레인에서
	switch(randLane)
	{
		// 5개의 레인 각 위치, 적 위치 정하고 회전 동작 실행, 생성된 적 리스트에 저장
		case 0:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			pEnemySprite->enemyAction();
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 1:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			pEnemySprite->enemyAction();
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 2:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			pEnemySprite->enemyAction();
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 3:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			pEnemySprite->enemyAction();
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
		case 4:
			pEnemySprite->setPosition(refLane + (laneInterval * randLane));
			pEnemySprite->enemyAction();
			enemyList.pushBack(pEnemySprite);
			this->addChild(pEnemySprite);
			break;
	}
}

// 적의 무작위 타입 지정
void EnemyLayer::setEnemyType()
{
	// X S C 3가지 중 하나
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

// 적 사망처리
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

// 적 사망시 리스트와 등록에서 제거
void EnemyLayer::removeEnemy(int _idx)
{
	this->removeChild(enemyList.at(_idx));
	enemyList.erase(_idx);
}

// 적 리스트 반환
Vector<EnemySprite*> EnemyLayer::getEnemyList()
{
	return this->enemyList;
}