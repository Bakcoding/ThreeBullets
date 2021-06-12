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

// ������ �Լ�
void EnemyLayer::Spawn(float _dt)
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	// ���� ������ ������ ��ġ ����
	int RandLine = rand() % 4 + 1;
	// ���� ����
	int BaseLine = m_visibleSize.width * 0.125f;
	// ���� ���� ����
	int LineInterver = 25;
	// ���� ��ġ
	int RandPosition = (BaseLine * ((2 * RandLine) - 1));
	
	// ������ ���ʹ� Ÿ�� ����
	int RanType = rand() % 3 + 1;

	switch (RanType)
	{
		case 1:
		{
			Enemy = new EnemySprite;
			// ���ʹ� ��������Ʈ ���� �Լ� initEnemy(Ÿ��, �ӵ�, ����)
			Enemy->initEnemy(EnemySprite::EType::kEX, 200.0f, Vec2(0.0f, -1.0f));
			Enemy->setScale(0.25f);
			Enemy->setPosition(RandPosition, m_visibleSize.height);
			// OnAction() : ��������Ʈ ȸ����Ű�� �Լ�, ���ʹ̰� ȸ���ϸ鼭 ������
			Enemy->OnAction();
			m_EnemyList.pushBack(Enemy);
			this->addChild(Enemy);
			break;
		}

		// ���� Ÿ�Ը� �ٲ�� �������� ������
		case 2:
		{
			Enemy = new EnemySprite;
			Enemy->initEnemy(EnemySprite::EType::kEC, 200.0f, Vec2(0.0f, -1.0f));
			// ����
#pragma region ����
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
			// ����
#pragma region ����
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
