#include "PlayerLayer.h"

PlayerLayer::PlayerLayer() : pPlayer(NULL), strPlayerFile{ "Player/PlayerSprite.png" }, 
strLeftButtonFile{"Button/LeftButtonNormal.png", "Button/LeftButtonSelect.png","Button/LeftButtonSelect.png" },
strRightButtonFile{"Button/RightButtonNormal.png", "Button/RightButtonSelect.png", "Button/RightButtonSelect.png"},
visibleSize(Director::getInstance()->getVisibleSize()), interval(visibleSize.width * 0.2f) {}

bool PlayerLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initPlayer();
	initButton();

	return true;
}

void PlayerLayer::initPlayer()
{
	if (!pPlayer == NULL)
	{
		return;
	}
	Vec2 newPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	pPlayer = Sprite::create(strPlayerFile);
	pPlayer->setPosition(newPos);
	this->addChild(pPlayer);
}

void PlayerLayer::initButton()
{
	Vec2 newPos = Vec2(visibleSize.width * 0.1225f, visibleSize.height * 0.0575f);
	CreateButton* leftButton = CreateButton::create();
	leftButton->init(strLeftButtonFile, CC_CALLBACK_2(PlayerLayer::moveLeft, this), newPos);

	newPos = Vec2(visibleSize.width * 0.335f, visibleSize.height * 0.0575f);
	CreateButton* rightButton = CreateButton::create();
	rightButton->init(strRightButtonFile, CC_CALLBACK_2(PlayerLayer::moveRight, this), newPos);
	
	leftButton->setTag(EButton::kLeft);
	rightButton->setTag(EButton::kRight);

	this->addChild(leftButton);
	this->addChild(rightButton);
}


void PlayerLayer::moveLeft(Ref* _sender, Widget::TouchEventType _type)
{
	Vec2 currentPos = pPlayer->getPosition();
	Vec2 firstLine = Vec2(visibleSize.width * 0.2f, visibleSize.height);

	switch (_type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		if (currentPos.x != firstLine.x)
		{
			CCLOG("test Left");
			pPlayer->setPosition(currentPos.x - interval, currentPos.y);
		}
		break;
	case ui::Widget::TouchEventType::ENDED:
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
	case ui::Widget::TouchEventType::BEGAN:
		if (currentPos.x != lastLine.x)
		{
			CCLOG("test Right");
			pPlayer->setPosition(currentPos.x + interval, currentPos.y);
		}
		break;
	case ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}