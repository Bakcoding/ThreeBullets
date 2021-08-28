#include "PlayerLayer.h"
PlayerLayer::PlayerLayer() : pPlayer(NULL), playerPos(Vec2::ZERO), pBullet(NULL),
strPlayerFile{ "Player/PlayerSprite.png" },
strLeftButtonFile{ "Button/LeftButtonNormal.png", "Button/LeftButtonSelect.png","Button/LeftButtonSelect.png" },
strRightButtonFile{ "Button/RightButtonNormal.png", "Button/RightButtonSelect.png", "Button/RightButtonSelect.png" },
visibleSize(Director::getInstance()->getVisibleSize()), interval(visibleSize.width * 0.2f) {}

bool PlayerLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initPlayer();
	initButton();
	initBullet();

	this->scheduleUpdate();

	return true;
}

void PlayerLayer::update(float _dt)
{
	pBullet->setBulletPos(playerPos);
}

bool PlayerLayer::initPlayer()
{
	Vec2 newPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	pPlayer = PlayerSprite::create();
	if (pPlayer == nullptr || !pPlayer->init(strPlayerFile, Vec2::ZERO))
	{
		return false;
	}

	pPlayer->setPosition(newPos);
	playerPos = newPos;

	this->addChild(pPlayer);

}

bool PlayerLayer::initButton()
{
	Vec2 leftPos = Vec2(visibleSize.width * 0.1225f, visibleSize.height * 0.0575f);
	Vec2 rightPos = Vec2(visibleSize.width * 0.335f, visibleSize.height * 0.0575f);
	CreateButton* leftButton = CreateButton::create();
	CreateButton* rightButton = CreateButton::create();
	
	if (leftButton == nullptr || !leftButton->init(strLeftButtonFile, Widget::TextureResType::LOCAL))
	{
		return false;
	}

	if (rightButton == nullptr || !rightButton->init(strRightButtonFile, Widget::TextureResType::LOCAL))
	{
		return false;
	}
	
	leftButton->addTouchEventListener(CC_CALLBACK_2(PlayerLayer::moveLeft, this));
	rightButton->addTouchEventListener(CC_CALLBACK_2(PlayerLayer::moveRight, this));

	leftButton->setPosition(leftPos);
	rightButton->setPosition(rightPos);

	this->addChild(leftButton);
	this->addChild(rightButton);
}

bool PlayerLayer::initBullet()
{
	pBullet = BulletLayer::create();

	if (pBullet == nullptr || !Layer::init())
	{
		return false;
	}

	this->addChild(pBullet);
}


void PlayerLayer::moveLeft(Ref* _sender, Widget::TouchEventType _type)
{
	Vec2 currentPos = pPlayer->getPosition();
	Vec2 firstLine = Vec2(visibleSize.width * 0.2f, visibleSize.height);

	switch (_type)
	{
	case Widget::TouchEventType::BEGAN:
		if (currentPos.x != firstLine.x)
		{
			pPlayer->moveLeft();
			playerPos = pPlayer->getPosition();
		}
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void PlayerLayer::moveRight(Ref* _sender, Widget::TouchEventType _type)
{
	Vec2 currentPos = pPlayer->getPosition();
	Vec2 lastLine = Vec2(visibleSize.width, visibleSize.height);

	switch (_type)
	{
	case Widget::TouchEventType::BEGAN:
		if (currentPos.x != lastLine.x)
		{
			pPlayer->moveRight();
			playerPos = pPlayer->getPosition();
		}
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

Vec2 PlayerLayer::getPlayerPosition()
{
	return playerPos;
}
