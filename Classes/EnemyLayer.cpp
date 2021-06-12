 #include "EnemyLayer.h"
#include "EnemySprite.h"
#include <ctime>


EnemyLayer::EnemyLayer() : m_visibleSize(Size::ZERO) {}

bool EnemyLayer::init()
{
	if (!Layer::init()) return false;


	srand((int)time(NULL));
	this->schedule(CC_SCHEDULE_SELECTOR(EnemyLayer::Spawn), 0.8f, CC_REPEAT_FOREVER, 2.0f);
	this->scheduleUpdate();

	return true;
}

void EnemyLayer::update(float _dt)
{
	EnemyProcess();
}

// 적생성 함수
void EnemyLayer::Spawn(float _dt)
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	// 적이 생성될 무작위 위치 생성
	int RandLine = rand() % 4 + 1;
	// 기준 라인
	int BaseLine = m_visibleSize.width * 0.125f;
	// 라인 사이 간격
	int LineInterver = 25;
	// 랜덤 위치
	int RandPosition = (BaseLine * ((2 * RandLine) - 1));
	
	// 무작위 에너미 타입 지정
	int RanType = rand() % 3 + 1;

	switch (RanType)
	{
		case 1:
		{
			Enemy = new EnemySprite;
			// 에너미 스프라이트 생성 함수 initEnemy(타입, 속도, 방향)
			Enemy->initEnemy(EnemySprite::EType::kEX, 200.0f, Vec2(0.0f, -1.0f));
			Enemy->setScale(0.25f);
			Enemy->setPosition(RandPosition, m_visibleSize.height);
			// OnAction() : 스프라이트 회전시키는 함수, 에너미가 회전하면서 내려옴
			Enemy->OnAction();
			m_EnemyList.pushBack(Enemy);
			this->addChild(Enemy);
			break;
		}

		// 적의 타입만 바뀌고 나머지는 동일함
		case 2:
		{
			Enemy = new EnemySprite;
			Enemy->initEnemy(EnemySprite::EType::kEC, 200.0f, Vec2(0.0f, -1.0f));
			// 생략
#pragma region 생략
			Enemy->setScale(0.25f);
			Enemy->setPosition(RandPosition, m_visibleSize.height);
			Enemy->OnAction();
			m_EnemyList.pushBack(Enemy);
			this->addChild(Enemy);
			break;
#pragma endregion
		}
		case 3:
		{
			Enemy = new EnemySprite;
			Enemy->initEnemy(EnemySprite::EType::kES, 200.0f, Vec2(0.0f, -1.0f));
			// 생략
#pragma region 생략
			Enemy->setScale(0.25f);
			Enemy->setPosition(RandPosition, m_visibleSize.height);
			Enemy->OnAction();
			m_EnemyList.pushBack(Enemy);
			this->addChild(Enemy);
			break;
#pragma endregion
		}
	}
}

void EnemyLayer::EnemyProcess()
{
	for (int i = 0; i < m_EnemyList.size(); ++i)
	{
		if (m_EnemyList.at(i)->IsDead())
		{
			this->removeChild(m_EnemyList.at(i));
			m_EnemyList.erase(i);
			break;
		}
	}
}

Vector<EnemySprite*> EnemyLayer::GetEnemyList()
{
	return m_EnemyList;
}

void EnemyLayer::RemoveEnemylist(int _idx)
{
	m_EnemyList.erase(_idx);
}
