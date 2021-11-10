#include "PlayerLayer.h"
PlayerLayer::PlayerLayer() : pPlayer(NULL), playerPos(Vec2::ZERO), pBullet(NULL),
strPlayerFile{ "Player/PlayerSprite.png" },
strLeftButtonFile{ "Button/LeftButtonNormal.png", "Button/LeftButtonSelect.png","Button/LeftButtonSelect.png" },
strRightButtonFile{ "Button/RightButtonNormal.png", "Button/RightButtonSelect.png", "Button/RightButtonSelect.png" },
visibleSize(Director::getInstance()->getVisibleSize()), interval(visibleSize.width * 0.2f) {}

// 플레이어 생성
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

// 총알 정보 업데이트
// 플레이어 위치에서 총알이 생성된다.  
void PlayerLayer::update(float _dt)
{
	pBullet->setBulletPos(playerPos);
}

// PlayerSprite 초기화 함수 호출, 플레이어 초기화, 생성
bool PlayerLayer::initPlayer()
{
	Vec2 newPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.241f);
	pPlayer = PlayerSprite::create();
	if (pPlayer == NULL || !pPlayer->init(strPlayerFile, Vec2::ZERO))
	{
		return false;
	}

	pPlayer->setPosition(newPos);
	pPlayer->setScale(0.8f);
	playerPos = newPos;

	this->addChild(pPlayer);

	return true;
}

// CreateButton 클래스 사용한 버튼 생성
// 플레이어 좌우 이동 버튼
bool PlayerLayer::initButton()
{
	Vec2 leftPos = Vec2(visibleSize.width * 0.1225f, visibleSize.height * 0.0575f);
	Vec2 rightPos = Vec2(visibleSize.width * 0.335f, visibleSize.height * 0.0575f);
	CreateButton* leftButton = CreateButton::create();
	CreateButton* rightButton = CreateButton::create();

	if (leftButton == NULL || !leftButton->init(strLeftButtonFile, Widget::TextureResType::LOCAL))
	{
		return false;
	}

	if (rightButton == NULL || !rightButton->init(strRightButtonFile, Widget::TextureResType::LOCAL))
	{
		return false;
	}

	// 좌로 이동하는 버튼
	leftButton->addTouchEventListener(CC_CALLBACK_2(PlayerLayer::moveLeft, this));
	// 우로 이동하는 버튼
	rightButton->addTouchEventListener(CC_CALLBACK_2(PlayerLayer::moveRight, this));

	leftButton->setPosition(leftPos);
	rightButton->setPosition(rightPos);

	this->addChild(leftButton);
	this->addChild(rightButton);

	return true;
}

// 총알 생성
bool PlayerLayer::initBullet()
{
	pBullet = BulletLayer::create();

	if (pBullet == NULL || !Layer::init())
	{
		return false;
	}

	this->addChild(pBullet);

	return true;
}

// 버튼 입력 처리 콜백 함수
// 왼쪽
void PlayerLayer::moveLeft(Ref* _sender, Widget::TouchEventType _type)
{
	Vec2 currentPos = pPlayer->getPosition();
	Vec2 firstLine = Vec2(visibleSize.width * 0.2f, visibleSize.height);

	switch (_type)
	{
	case Widget::TouchEventType::BEGAN:

		pPlayer->moveLeft();
		playerPos = pPlayer->getPosition();
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}
// 오른쪽 
void PlayerLayer::moveRight(Ref* _sender, Widget::TouchEventType _type)
{
	Vec2 currentPos = pPlayer->getPosition();
	Vec2 lastLine = Vec2(visibleSize.width, visibleSize.height);

	switch (_type)
	{
	case Widget::TouchEventType::BEGAN:

		pPlayer->moveRight();
		playerPos = pPlayer->getPosition();
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

// 플레이어 위치 반환
Vec2 PlayerLayer::getPlayerPosition()
{
	return playerPos;
}

// 총알이 저장된 리스트 반환
Vector<BulletSprite*> PlayerLayer::getBulletList()
{
	bulletList = pBullet->getBulletList();
	return bulletList;
}

// 총알 객체를 반환
BulletLayer* PlayerLayer::getBulletLayer()
{
	return pBullet;
}
