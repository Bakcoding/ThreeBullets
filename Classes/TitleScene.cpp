#include "TitleScene.h"

TitleScene::TitleScene() : visibleSize(Director::getInstance()->getVisibleSize()), 
strStartButton{ "Button/StartButtonNormal.png" ,  "Button/StartButtonSelect.png" , "Button/StartButtonSelect.png"},
strExitButton{ "Button/ExitButtonNormal.png", "Button/ExitButtonSelect.png", "Button/ExitButtonSelect.png" }, 
pStartButton(NULL), pExitButton(NULL) {}

// 타이틀 씬 초기화
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

// 게임 타이틀 로고 생성
void TitleScene::titleImageInit()
{
	Sprite* titleImage = Sprite::create("Title/Logo.png");
	titleImage->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.7f);
	this->addChild(titleImage);
}

// CreateButton 클래스 사용한 버튼 생성
void TitleScene::buttonInit()
{
	// 시작하기 버튼
	Vec2 startPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	pStartButton = CreateButton::create();
	pStartButton->init(strStartButton, Widget::TextureResType::LOCAL);
	pStartButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::nextScene, this));
	pStartButton->setPosition(startPos);

	// 게임종료 버튼
	Vec2 exitPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.225f);
	pExitButton = CreateButton::create();
	pExitButton->init(strExitButton, Widget::TextureResType::LOCAL);
	pExitButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::exitGame, this));
	pExitButton->setPosition(exitPos);

	this->addChild(pStartButton);
	this->addChild(pExitButton);
}

// 씬 전환
// 시작하기 -> 게임 씬으로 전환
void TitleScene::nextScene(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
}
// 게임종료 -> 애플리케이션 종료
void TitleScene::exitGame(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->end();
}