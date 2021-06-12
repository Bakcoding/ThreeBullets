#ifndef _MANUAL_SCENE_H_
#define _MANUAL_SCENE_H_
#include "cocos2d.h"

USING_NS_CC;

class ManualScene : public Scene
{
public:
	enum ETag{kStart};
private:

public:
	ManualScene();
	CREATE_FUNC(ManualScene);
	virtual bool init() override;

	void InitManual();
	void InitStart();
	void startGameCallback(Ref* _sender);

};

#endif