#include "GameoverScene.h"



GameoverScene::GameoverScene() : 
	retryFileName{"Button/RetryButtonNormal.png", "Button/RetryButtonSelect.png", "Button/RetryButtonSelect.png"},
	exitFileName{ "Button/ExitButtonNormal.png", "Button/ExitButtonSelect.png", "Button/ExitButtonSelect.png" },
	visibleSize(Director::getInstance()->getVisibleSize()), totalScore(0) {}

bool GameoverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	gameoverSprite();
	scoreLabel();
	initButton();

	return true;
}

void GameoverScene::gameoverSprite()
{
	Sprite* gameover = Sprite::create("Gameover/Gameover.png");
	gameover->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.7f);
	this->addChild(gameover);
}

void GameoverScene::scoreLabel()
{
	totalScore = ScoreManager::getTotalScore();
	float scoreFontSize = (visibleSize.width * visibleSize.height) / 8000;
	Label* scoreLabel = Label::createWithTTF("000000", "fonts/Marker Felt.ttf", scoreFontSize);
	scoreLabel->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.6f);
	scoreLabel->setTextColor(Color4B::WHITE);
	string strScore = StringUtils::format("%d", totalScore);
	scoreLabel->setString(strScore);

	this->addChild(scoreLabel);
}

bool GameoverScene::initButton()
{
	CreateButton* retryButton = CreateButton::create();
	CreateButton* exitButton = CreateButton::create();

	Vec2 retryPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	Vec2 exitPos = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.22f);

	if (retryButton == nullptr || !retryButton->init(retryFileName, Widget::TextureResType::LOCAL))
	{
		return false;
	}

	if (exitButton == nullptr || !exitButton->init(exitFileName, Widget::TextureResType::LOCAL))
	{
		return false;
	}

	retryButton->setPosition(retryPos);
	exitButton->setPosition(exitPos);

	retryButton->addTouchEventListener(CC_CALLBACK_2(GameoverScene::turnGameScene, this));
	exitButton->addTouchEventListener(CC_CALLBACK_2(GameoverScene::exitApplication, this));

	this->addChild(retryButton);
	this->addChild(exitButton);

	return true;
}

void GameoverScene::turnGameScene(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
}

void GameoverScene::exitApplication(Ref* _sender, Widget::TouchEventType _type)
{
	Director::getInstance()->end();
}
