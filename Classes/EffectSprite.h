#ifndef _EFFECT_SPRITE_H_
#define _EFFECT_SPRITE_H_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class EffectSprite : public Sprite
{
private:
	Sprite* hitEffect;
	Vec2 hitEffectPos;
	Size visibleSize;
	string fileName;
	bool isHit;
	int destroySpeed;

public:
	EffectSprite();
	CREATE_FUNC(EffectSprite);
	virtual bool init() override;
	void initHitEffect();
	void update(float _dt) override;
	void effectOn();
	void effectProcess(float _dt);
	void setIsHit(bool _isHit);
};

#endif