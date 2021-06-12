#include "Effect.h"

Effect::Effect() : IsBlink(false) {}

bool Effect::init()
{
	if (!Sprite::init()) return false;



	return true;
}

void Effect::HitEffect()
{
	Size winSize = Director::getInstance()->getWinSize();
	Sprite* hit = Sprite::create("Effect/EFDmg.png");
	hit->setPosition(winSize.width * 0.5f, winSize.height * 0.5f);
	this->addChild(hit);

	if (IsBlink == false)
	{
		IsBlink = true;
		//Blink* pBlink = Blink::create(0.5f, 1);
		RemoveSelf* pRemove = RemoveSelf::create(true);
		CallFunc* pCall = CallFunc::create(CC_CALLBACK_0(Effect::HitEnd, this));
		Sequence* pSeq = Sequence::create(pRemove, pCall, 0);
		hit->runAction(pSeq);
	}
}

void Effect::HitEnd()
{
	IsBlink = false;
}