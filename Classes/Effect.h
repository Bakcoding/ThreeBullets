#ifndef _EFFECT_H_
#define _EFFECT_H_
#include "cocos2d.h"

USING_NS_CC;

class Effect : public Sprite
{
private:
	bool IsBlink;
public:
	Effect();
	CREATE_FUNC(Effect);
	virtual bool init() override;

public:
	void HitEffect();
	void HitEnd();
};

#endif