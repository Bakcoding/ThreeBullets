#include "ManualScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

ManualScene::ManualScene() {}
bool ManualScene::init()
{
	if (!Scene::init()) return false;

	InitManual();
	InitStart();

	return true;
}

void ManualScene::InitManual()
{
	Size winSize = Director::getInstance()->getWinSize();
	Sprite* manual = Sprite::create("Background/Manual.png");
	manual->setPosition(winSize.width * 0.5f, winSize.height * 0.5f);
	this->addChild(manual);
}

void ManualScene::InitStart()
{
	Size winSize = Director::getInstance()->getWinSize();
	MenuItemImage* Start = MenuItemImage::create(
		"Button/START.png",
		"Button/STARTOn.png",
		CC_CALLBACK_1(ManualScene::startGameCallback, this));

	Menu* button = Menu::create(Start, NULL);
	button->alignItemsVertically();
	button->setPosition(winSize.width * 0.5f, winSize.height * 0.1f);

	Start->setTag(ETag::kStart);

	this->addChild(button);
}

void ManualScene::startGameCallback(Ref* _sender)
{
	switch (((MenuItemImage*)_sender)->getTag())
	{
	case ETag::kStart:
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
		break;
	}
}