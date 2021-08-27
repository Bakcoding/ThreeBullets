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

	//Button* button = Button::create(strStartButton[0], strStartButton[1], strStartButton[2]);
	//button->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.5f));
	//button->addTouchEventListener(CC_CALLBACK_2(TitleScene::nextScene, this));
	//this->addChild(button);

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
	pStartButton = ButtonNode::create();
	pStartButton->init(strStartButton, CC_CALLBACK_2(TitleScene::nextScene, this), newPos);

	pExitButton = ButtonNode::create();
	pExitButton->init(strExitButton, CC_CALLBACK_2(TitleScene::exitGame, this), newPos);
	pExitButton->alignmentVertical(pStartButton, 50.0f);

	this->addChild(pStartButton);
	this->addChild(pExitButton);
}

void TitleScene::nextScene(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
}
void TitleScene::exitGame(Ref* _sender, Widget::TouchEventType _type)
{
	switch (_type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}