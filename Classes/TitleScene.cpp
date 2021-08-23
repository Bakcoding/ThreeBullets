#include "TitleScene.h"


TitleScene* TitleScene::createScene() {
	return create();	
}

bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	initTitle();
	initButton();


	return true;
}

// 게임 타이틀 로고
void TitleScene::initTitle()
{
	// 화면의 크기를 가져옴
	Size winSize = Director::getInstance()->getWinSize();
	float positonX = winSize.width * 0.5f;
	float positionY = winSize.height * 0.7f;

	Sprite* title = Sprite::create("Title/Logo.png");
	// 위치 조정
	title->setPosition(positonX, positionY);
	// 이미지 크기 조정
	title->setScale(1.5f);
	this->addChild(title);
}

// 시작 버튼
void TitleScene::initButton()
{
	Size winSize = Director::getInstance()->getWinSize();
	float positionX = winSize.width * 0.5f;
	float positionY = winSize.height * 0.3f;
	
	// 시작 버튼 상호작용
	MenuItemImage* start = MenuItemImage::create(
		"Title/StartButtonNormal.png",
		"Title/StartButtonSelect.png",
		CC_CALLBACK_1(TitleScene::titlesceneCallBack, this));

	// 종료 버튼 상호작용
	MenuItemImage* exit = MenuItemImage::create(
		"Title/ExitButtonNormal.png",
		"Title/ExitButtonSelect.png",
		CC_CALLBACK_1(TitleScene::titlesceneCallBack, this));

	// 이미지 크기 조정
	start->setScale(2.0f);
	exit->setScale(2.0f);

	// 버튼 위치, Menu로 만들어서 묶어서 관리, 마지막 전달인자 NULL로 끝 표시
	Menu* menu = Menu::create(start, exit, NULL);
	// 메뉴로 만든 객체 수직 정렬
	menu->alignItemsVertically();
	// 위치 조정
	menu->setPosition(positionX, positionY);
	// 객체 태그 설정
	start->setTag(ETag::kStart);
	exit->setTag(ETag::kExit);

	this->addChild(menu);
}

// 버튼 구분
void TitleScene::titlesceneCallBack(Ref* _sender)
{
	// MenuItem 만든 객체 태그로 구분
	switch (((MenuItemImage*)_sender)->getTag())
	{
	// 씬전환
	case ETag::kStart:
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
		break;
	// 종료		
	case ETag::kExit:
		Director::getInstance()->end();
		break;
	}
}