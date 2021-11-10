#include "EffectSprite.h"

EffectSprite::EffectSprite() :
	fileName{ "Effect/HitEffect.png" }, hitEffect(NULL), hitEffectPos(Vec2::ZERO), isHit(false), destroySpeed(800),
	visibleSize(Director::getInstance()->getVisibleSize()) {}

// 효과 생성
bool EffectSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	initHitEffect();

	this->scheduleUpdate();

	return true;
}

// 효과 이미지 생성, 레드 라이트 효과
void EffectSprite::initHitEffect()
{
	hitEffect = Sprite::create(fileName);
	hitEffect->setAnchorPoint(Vec2::ZERO);
	hitEffect->setPosition(0, visibleSize.height * 0.21f);
	hitEffect->setOpacity(0);
	this->addChild(hitEffect);
}

void EffectSprite::update(float _dt)
{
	effectProcess(_dt);
}

// 효과 이미지를 하나 생성하고 투명값 조절해서 사용한다.
// 플레이어가 목숨 잃을 때 발동한다.
void EffectSprite::effectOn()
{
	if (isHit)
	{
		isHit = false;
		hitEffect->setOpacity(255);

		return;
	}
}

// 발동하고 난 뒤 서서히 투명해지면서 안보이게됨
void EffectSprite::effectProcess(float _dt)
{
	effectOn();
	int opacity = 0;
	opacity = hitEffect->getOpacity();
	opacity -= destroySpeed * _dt;

	if (opacity <= 0)
	{
		opacity = 0;
		return;
	}
	
	hitEffect->setOpacity(opacity);
}

// 플레이어 목숨 잃었는지 확인
void EffectSprite::setIsHit(bool _isHit)
{
	isHit = _isHit;
}