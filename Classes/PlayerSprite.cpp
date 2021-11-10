#include "PlayerSprite.h"

PlayerSprite::PlayerSprite() : visibleSize(Director::getInstance()->getVisibleSize()), playerPos(Vec2::ZERO) {}

bool PlayerSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

// 플레이어 초기화
bool PlayerSprite::init(const char* _fileName, Vec2 _pos)
{
	if (!Sprite::initWithFile(_fileName))
	{
		return false;
	}

	playerPos = _pos;

	return true;
}

// 플레이어 움직임 함수
// 왼쪽으로 이동
void PlayerSprite::moveLeft()
{
	if (this->getPosition().x > visibleSize.width * 0.2f)
	{
		Vec2 newPos = this->getPosition();
		newPos -= Vec2(visibleSize.width * 0.2f, 0);
		this->setPosition(newPos);
	}
}
// 오른쪽으로 이동
void PlayerSprite::moveRight()
{
	if (this->getPosition().x < visibleSize.width * 0.8f)
	{
		Vec2 newPos = this->getPosition();
		newPos += Vec2(visibleSize.width * 0.2f, 0);
		this->setPosition(newPos);
	}
}

