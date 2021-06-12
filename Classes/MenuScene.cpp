#include "MenuScene.h"

MenuScene::MenuScene()
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::init()
{
	if (!Scene::init()) return false;
	
		Size winSize = Director::getInstance()->getWinSize();

		// Title 
		Sprite* Title = Sprite::create("Button/Title.png");
		Title->setPosition(winSize.width * 0.5f, winSize.height * 0.7f);
		this->addChild(Title);

		// Start 
		MenuItemImage* Start = MenuItemImage::create(
			"Button/START.png",
			"Button/STARTOn.png", 
			CC_CALLBACK_1(MenuScene::startGameCallback, this));
		//Start->setPosition(winSize.width * 0.5f, winSize.height * 0.3f);
		//this->addChild(Start);

		// Exit
		MenuItemImage* Exit = MenuItemImage::create(
			"Button/EXIT.png",
			"Button/EXITOn.png",
		CC_CALLBACK_1(MenuScene::startGameCallback, this));
		//Exit->setPosition(winSize.width * 0.5f, winSize.height * 0.2f);
		//this->addChild(Exit);

		// Menu
		Menu* menu = Menu::create(Start, Exit, NULL);
		menu->alignItemsVertically();
		menu->setPosition(winSize.width * 0.5f, winSize.height * 0.3f);

		Start->setTag(ETag::kStart);
		Exit->setTag(ETag::kExit);

		this->addChild(menu);

		return true;
	
}

void MenuScene::startGameCallback(Ref* _sender)
{
	switch (((MenuItemImage*)_sender)->getTag())
	{
	case ETag::kStart:
		CCLOG("Start Callback");
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
		break;
	case ETag::kExit:
		Director::getInstance()->end();
		CCLOG("Exit Callback");
		break;
	}
}