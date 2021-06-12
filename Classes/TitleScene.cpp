#include "TitleScene.h"


TitleScene::TitleScene(){}
TitleScene::~TitleScene(){}

bool TitleScene::init()
{
	if (!Scene::init()) return false;	
		// Title 
		InitTitle();
		// Menu
		InitMenu();


		return true;	
}

void TitleScene::InitTitle()
{
	Size winSize = Director::getInstance()->getWinSize();
	Sprite* Title = Sprite::create("Button/Title.png");
	Title->setPosition(winSize.width * 0.5f, winSize.height * 0.7f);
	this->addChild(Title);
}

void TitleScene::InitMenu()
{
	Size winSize = Director::getInstance()->getWinSize();
	// Start 
	MenuItemImage* Play = MenuItemImage::create(
		"Button/PLAY.png",
		"Button/PLAYOn.png",
		CC_CALLBACK_1(TitleScene::playGameCallback, this));

	// Exit
	MenuItemImage* Exit = MenuItemImage::create(
		"Button/EXIT.png",
		"Button/EXITOn.png",
		CC_CALLBACK_1(TitleScene::playGameCallback, this));

	// Menu
	Menu* menu = Menu::create(Play, Exit, NULL);
	menu->alignItemsVertically();
	menu->setPosition(winSize.width * 0.5f, winSize.height * 0.3f);

	Play->setTag(ETag::kStart);
	Exit->setTag(ETag::kExit);

	this->addChild(menu);
}


void TitleScene::playGameCallback(Ref* _sender)
{
	switch (((MenuItemImage*)_sender)->getTag())
	{
	case ETag::kStart:
		CCLOG("Start Callback");
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, ManualScene::create()));
		break;
	case ETag::kExit:
		Director::getInstance()->end();
		CCLOG("Exit Callback");
		break;
	}
}