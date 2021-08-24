#include "PlayerLayer.h"

PlayerLayer::PlayerLayer()
{
	pPlayer = NULL;
	winSize = Director::getInstance()->getWinSize();
	currentPos = Vec2::ZERO;
	buttonPadding = 1.0f;
}

PlayerLayer::~PlayerLayer() {}

bool PlayerLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	

	initPlayer();
	initButton();
	this->scheduleUpdate();
	return true;
}

void PlayerLayer::initPlayer()
{
	pPlayer = Sprite::create("Player/PlayerSprite.png");
	pPlayer->setPosition(winSize.width * 0.5f, winSize.height * 0.3f);
	currentPos = pPlayer->getPosition();
	pPlayer->setScale(0.5f);

	this->addChild(pPlayer);
}

void PlayerLayer::initButton()
{
	MenuItemImage* leftButton = MenuItemImage::create(
		"Button/LeftButtonNormal.png",
		"Button/LeftButtonSelect.png",
		CC_CALLBACK_1(PlayerLayer::playerAction, this)
	);

	MenuItemImage* rightButton = MenuItemImage::create(
		"Button/RightButtonNormal.png",
		"BUtton/RightButtonSelect.png",
		CC_CALLBACK_1(PlayerLayer::playerAction,this)
	);
	
	leftButton->setScale(2.0f);
	rightButton->setScale(2.0f);

	leftButton->setTag(EButton::kLeft);
	rightButton->setTag(EButton::kRight);

	Menu* buttonMenu = Menu::create(leftButton, rightButton, NULL);
	buttonMenu->alignItemsHorizontally();
	//buttonMenu->alignItemsHorizontallyWithPadding(buttonPadding);
	buttonMenu->setPosition(winSize.width * 0.5f, winSize.height * 0.5f);

	this->addChild(buttonMenu);
}

void PlayerLayer::moveLeft()
{
	Vec2 newPos = currentPos;
	newPos = currentPos - Point(winSize.width * 0.25, 0);
	pPlayer->setPosition(newPos);
}

void PlayerLayer::moveRight()
{
	Vec2 newPos = currentPos;
	newPos = currentPos + Point(winSize.width * 0.25f, 0);
}

void PlayerLayer::playerAction(Ref* _sender)
{
	switch (((MenuItemImage*)_sender)->getTag())
	{
	case EButton::kLeft:
		CCLOG("before Pos : %f\n", pPlayer->getPosition().x);
		moveLeft();
		CCLOG("After Pos : %f\n", pPlayer->getPosition().x);
		break;
		
	case EButton::kRight:
		moveRight();
		break;
	}
}