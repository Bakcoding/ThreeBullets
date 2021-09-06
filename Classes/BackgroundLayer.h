#ifndef _BACKGROUND_LAYER_H_
#define _BACKGROUND_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class BackgroundLayer : public Layer
{
private:
	Size visibleSize;
	enum ECount {kImage = 2};
	Sprite* backgroundImage[ECount::kImage];
	Label* lifeLabel;
	Label* scoreLabel;
	float imgScrollSpeed;
	float imgHeight;
	int life;
	int score;
public:
	BackgroundLayer();
	CREATE_FUNC(BackgroundLayer);
	virtual bool init() override;
	void update(float _dt) override;
	void initBackground();
	void scrollBackground(float _dt);
	void drawEndLine();
	void initCountTable();
	int getImageLastIndex();
	void repositionImage();
	void initLabel();
	void setLabelString(int _life, int _score);
};
#endif