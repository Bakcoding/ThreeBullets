#include "EnemyLayer.h"

EnemyLayer::EnemyLayer() :
	visibleSize(Director::getInstance()->getVisibleSize()), enemyList(NULL), enemyType(EnemySprite::EType::kCEnemy), 
	moveSpeed(300.0f), moveDir(Vec2(0, -1)), pEnemySprite(NULL), laneInterval(visibleSize.width * 0.2f, 0),
	refLane(visibleSize.width * 0.1f, visibleSize.height) {}

// �� ����
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

// �� �ʱ�ȭ, ����
bool EnemyLayer::initEnemy()
{
	pEnemySprite = EnemySprite::create();

	if (pEnemySprite == NULL || !pEnemySprite->init(enemyType, moveSpeed, moveDir))
	{
		return false;
	}

	return true;
}

// �� ���� ��ġ
void EnemyLayer::enemySpawn(float _dt)
{
	srand(int(time(NULL)));
	// ������ Ÿ���� �� ����
	setEnemyType();
	// �� ����
	initEnemy();
	// ������ ��ġ, 5���� ���� �� �ϳ�
	int randLane = rand() % 5;
	
	// ������ �ϳ��� ���ο���
	switch(randLane)
	{
		// 5���� ���� �� ��ġ, �� ��ġ ���ϰ� ȸ�� ���� ����, ������ �� ����Ʈ�� ����
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

// ���� ������ Ÿ�� ����
void EnemyLayer::setEnemyType()
{
	// X S C 3���� �� �ϳ�
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

// �� ���ó��
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

// �� ����� ����Ʈ�� ��Ͽ��� ����
void EnemyLayer::removeEnemy(int _idx)
{
	this->removeChild(enemyList.at(_idx));
	enemyList.erase(_idx);
}

// �� ����Ʈ ��ȯ
Vector<EnemySprite*> EnemyLayer::getEnemyList()
{
	return this->enemyList;
}