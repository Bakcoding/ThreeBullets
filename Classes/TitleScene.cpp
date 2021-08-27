#include "TitleScene.h"
#include <iostream>

TitleScene::TitleScene() : visibleSize(Director::getInstance()->getVisibleSize()), 
strStartButton{ "Button/StartButtonNormal.png" ,  "Button/StartButtonSelect.png" , "Button/StartButtonSelect.png"},
strExitButton{ "Button/ExitButtonNormal.png", "Button/ExitButtonSelect.png", "Button/ExitButtonSelect.png" }, 
pStartButton(NULL), pExitButton(NULL) {}

bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	titleImageInit();
	buttonInit();


	return true;
}

void TitleScene::titleImageInit()
{
	Sprite* titleImage = Sprite::create("Title/Logo.png");
	titleImage->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.7f);
	this->addChild(titleImage);
}

void TitleScene::buttonInit()
{
	Vec2 newPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	pStartButton = CreateButton::create();
	pStartButton->init(strStartButton, CC_CALLBACK_2(TitleScene::nextScene, this), newPos);


	newPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.225f);
	pExitButton = CreateButton::create();
	pExitButton->init(strExitButton, CC_CALLBACK_2(TitleScene::exitGame, this), newPos);

	this->addChild(pStartButton);
	this->addChild(pExitButton);
}

void TitleScene::nextScene(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
}
void TitleScene::exitGame(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->end();
}