#include "EffectSprite.h"

EffectSprite::EffectSprite() :
	fileName{ "Effect/HitEffect.png" }, hitEffect(NULL), hitEffectPos(Vec2::ZERO), isHit(false), destroySpeed(800),
	visibleSize(Director::getInstance()->getVisibleSize()) {}

// ȿ�� ����
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

// ȿ�� �̹��� ����, ���� ����Ʈ ȿ��
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

// ȿ�� �̹����� �ϳ� �����ϰ� ���� �����ؼ� ����Ѵ�.
// �÷��̾ ��� ���� �� �ߵ��Ѵ�.
void EffectSprite::effectOn()
{
	if (isHit)
	{
		isHit = false;
		hitEffect->setOpacity(255);

		return;
	}
}

// �ߵ��ϰ� �� �� ������ ���������鼭 �Ⱥ��̰Ե�
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

// �÷��̾� ��� �Ҿ����� Ȯ��
void EffectSprite::setIsHit(bool _isHit)
{
	isHit = _isHit;
}