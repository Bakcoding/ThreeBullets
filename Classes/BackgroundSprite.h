#ifndef _BACKGROUND_SPRITE_H_
#define _BACKGROUND_SPRITE_H_
#include "cocos2d.h"
USING_NS_CC;

class BackgroundSprite : public Sprite
{
private:
	Size visibleSize;
	enum ECount {kImage = 2};
	Sprite* backgroundImage[ECount::kImage];
	float imgScrollSpeed;
	float imgHeight;
public:
	BackgroundSprite();
	CREATE_FUNC(BackgroundSprite);
	virtual bool init() override;
	void update(float _dt);
	void initBackground();
	void scrollBackground(float _dt);
	void drawEndLine();
	int getImageLastIndex();
	void repositionImage();
};
#endif