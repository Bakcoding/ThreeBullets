#include "EnemySprite.h"

EnemySprite::EnemySprite() : isEnemyDead(false), moveSpeed(0), moveDir(Vec2::ZERO),
	fileName{"Enemy/XEnemy.png", "Enemy/CEnemy.png", "Enemy/SEnemy.png"},
	visibleSize(Director::getInstance()->getVisibleSize()){}

// 적 스프라이트 초기화
bool EnemySprite::init() 
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

// 적 초기화, 생성
bool EnemySprite::init(EType _type, float _speed, Vec2 _dir)
{
	if (!Sprite::initWithFile(fileName[_type]))
	{
		return false;
	}

	moveSpeed = _speed;
	moveDir = _dir;
	enemyType = _type;
	this->setScale(0.3f);

	this->scheduleUpdate();

	return true;
}

// 적 움직임 갱신, 생성과 동시에 아래를 향해 내려온다.
void EnemySprite::update(float _dt)
{
	enemyMove(_dt);
}

// 적 움직임
void EnemySprite::enemyMove(float _dt)
{
	if (isEnemyDead)
	{
		return;
	}

	Vec2 newPos = this->getPosition();
	
	newPos += moveSpeed * moveDir * _dt;
	this->setPosition(newPos);

	if (this->getPosition().y < visibleSize.height * 0.23f)
	{
		isEnemyDead = true;
	}
}

// 적 죽음 확인
bool EnemySprite::isDead()
{
	return this->isEnemyDead;
}

// 적 죽음 플래그 세팅
void EnemySprite::setEnemyDead(bool _bool)
{
	this->isEnemyDead = _bool;
}

// 적의 타입 정보 반환
EnemySprite::EType EnemySprite::getEnemyType()
{
	return this->enemyType;
}

// 적 이미지 회전 동작
void EnemySprite::enemyAction()
{
	Action* rotate = RotateBy::create(3.0f, 500.0f);
	this->runAction(rotate);
}