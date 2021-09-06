#include "TitleScene.h"

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
	Vec2 startPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	pStartButton = CreateButton::create();
	pStartButton->init(strStartButton, Widget::TextureResType::LOCAL);
	pStartButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::nextScene, this));
	pStartButton->setPosition(startPos);

	Vec2 exitPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.225f);
	pExitButton = CreateButton::create();
	pExitButton->init(strExitButton, Widget::TextureResType::LOCAL);
	pExitButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::exitGame, this));
	pExitButton->setPosition(exitPos);

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