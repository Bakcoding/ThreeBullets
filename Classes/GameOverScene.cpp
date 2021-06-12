#include "GameOverScene.h"
#include "GameScene.h"
#include "ScoreManager.h"

GameOverScene::GameOverScene() : score(0) {}
GameOverScene::~GameOverScene() {}

bool GameOverScene::init()
{
	if (!Scene::init()) return false;

	InitGameOver();
	InitButton();
	InitLabel();


	this->scheduleUpdate();
	return true;
}

void GameOverScene::update(float _dt)
{

}

void GameOverScene::GameOverCallback(Ref* _sender)
{
	switch (((MenuItemImage*)_sender)->getTag())
	{
	case ETag::kRetry:
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
		break;
	case ETag::kExit:
		Director::getInstance()->end();
		break;
	}
}

void GameOverScene::InitGameOver()
{
	Size winSize = Director::getInstance()->getWinSize();
	Sprite* Gameover = Sprite::create("Button/GameOver.png");
	Gameover->setPosition(winSize.width * 0.5f, winSize.height * 0.7f);
	this->addChild(Gameover);
}

void GameOverScene::InitButton()
{
	Size winSize = Director::getInstance()->getWinSize();

	MenuItemImage* Retry = MenuItemImage::create(
		"Button/Retry.png",
		"Button/RetryOn.png",
		CC_CALLBACK_1(GameOverScene::GameOverCallback, this));
	Retry->setScale(0.7f);

	MenuItemImage* Exit = MenuItemImage::create(
		"Button/EXIT.png",
		"Button/EXITOn.png",
		CC_CALLBACK_1(GameOverScene::GameOverCallback, this));

	Menu* menu = Menu::create(Retry, Exit, NULL);
	menu->alignItemsVertically();
	menu->setPosition(winSize.width * 0.5f, winSize.height * 0.3f);

	Retry->setTag(ETag::kRetry);
	Exit->setTag(ETag::kExit);

	this->addChild(menu);
}

void GameOverScene::InitLabel()
{
	Size winSize = Director::getInstance()->getWinSize();
	Label* label = Label::createWithTTF("00000000", "fonts/Marker Felt.ttf", 30);
	label->setTextColor(Color4B(255, 255, 255, 255));
	label->setPosition(winSize.width * 0.5, winSize.height * 0.6);
	this->addChild(label, 0, "lastscore");

	score = ScoreManager::getScore();
	Label* lastscore = (Label*)this->getChildByName("lastscore");
	string str = StringUtils::format("%d", score);
	lastscore->setString(str);
}



