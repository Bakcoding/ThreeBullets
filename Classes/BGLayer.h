#ifndef _BGLAYER_H_
#define _BGLAYER_H_
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class GameScene;

class BGLayer : public Layer
{
private:
	enum ELen { kSpace = 2 };

private:
	Sprite* m_pSpace[ELen::kSpace];
	Sprite* endline;

	float m_fSpaceScrollSpeed;
	float m_fSpaceContentHeight;
	
public:
	BGLayer();
	virtual ~BGLayer();

	static BGLayer* create();
	virtual bool init() override;
	virtual void update(float _dt) override;

private:
	void InitBGScpace();
	void BGScrollSpace(float _dt);
	int GetLastIndexWithSpace();
	void ScreenOutSpace();
	void InitLine();
	void InitEndline();

public:
	Sprite* GetEndline();

};

#endif