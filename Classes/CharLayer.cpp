#include "CharLayer.h"
#include "CharSprite.h"
#include "Weapon.h"
#include "BulletSprite.h"
#include "GameScene.h"

CharLayer::CharLayer() : m_visibleSize(Size::ZERO), m_pPlayer(nullptr), setPos(Vec2::ZERO),
						 bulletX(nullptr), bulletC(nullptr), bulletS(nullptr){}

CharLayer::~CharLayer() {}

CharLayer* CharLayer::create()
{
	CharLayer* pCharLayer = new CharLayer;
	if (pCharLayer != nullptr && pCharLayer->init())
	{
		pCharLayer->autorelease();
		return pCharLayer;
	}
	else
	{
		if (pCharLayer != nullptr)
		{
			delete pCharLayer;
			pCharLayer = nullptr;
		}
	}
	return nullptr;
}

bool CharLayer::init()
{
	if (!Layer::init()) return false;

	InitPlayer();


	EventListenerKeyboard* listenerKey = EventListenerKeyboard::create();
	listenerKey->onKeyPressed = CC_CALLBACK_2(CharLayer::onKeyPressed, this);
	listenerKey->onKeyReleased = CC_CALLBACK_2(CharLayer::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKey, this);

	this->scheduleUpdate();

	return true;
}

void CharLayer::update(float _dt)
{
	BulletProcess();
}

bool CharLayer::InitPlayer()
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	m_pPlayer = CharSprite::create();
	if (m_pPlayer == nullptr || !m_pPlayer->init("Character/player.png", 100.0f)) return false;
	m_pPlayer->setScale(0.25f);
	m_pPlayer->setPosition(m_visibleSize.width * 0.375f, m_visibleSize.height * 0.125f);
	m_pPlayer->Setbullet(Weapon::create());
	this->addChild(m_pPlayer);
}

void CharLayer::onKeyPressed(EventKeyboard::KeyCode _keyCode, Event* _event)
{
	switch(_keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		MoveLeft();
		break;

	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		MoveRight();
		break;

	case EventKeyboard::KeyCode::KEY_A:
	{
		bulletX = m_pPlayer->Shoot(BulletSprite::EType::kX);
		this->addChild((Node*)bulletX);
		m_playerBulletList.pushBack(bulletX);
		break;
	}
	case EventKeyboard::KeyCode::KEY_W:
	{
		bulletC = m_pPlayer->Shoot(BulletSprite::EType::kC);
		this->addChild((Node*)bulletC);
		m_playerBulletList.pushBack(bulletC);
		break;
	}
	case EventKeyboard::KeyCode::KEY_D:
	{
		bulletS = m_pPlayer->Shoot(BulletSprite::EType::kS);
		this->addChild((Node*)bulletS);
		m_playerBulletList.pushBack(bulletS);
		break;
	}
	
	}
}

void CharLayer::MoveLeft()
{
	if (m_pPlayer->getPosition().x > 90)
	{
		setPos = m_pPlayer->getPosition() + Point(-90.0f, 0.0f);
		m_pPlayer->setPosition(setPos);
	}
}

void CharLayer::MoveRight()
{
	if (m_pPlayer->getPosition().x < 270)
	{
		setPos = m_pPlayer->getPosition() + Point(90.0f, 0.0f);
		m_pPlayer->setPosition(setPos);
	}
}

void CharLayer::BulletProcess()
{
	for (int i = 0; i < m_playerBulletList.size(); ++i)
	{
		if (m_playerBulletList.at(i)->IsDead())
		{
			this->removeChild(m_playerBulletList.at(i));
			m_playerBulletList.erase(i);
			break;
		}
	}
}

Vector<BulletSprite*> CharLayer::GetPlayerBulletList()
{
	return m_playerBulletList;
}

void CharLayer::RemoveBulletlist(int _idx)
{
	m_playerBulletList.erase(_idx);
}