#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer() :
	backgroundImage{ NULL }, imgScrollSpeed(1000.0f), imgHeight(0), life(0), score(0), lifeLabel(NULL), scoreLabel(NULL),
	visibleSize(Director::getInstance()->getVisibleSize()) {}

bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	drawEndLine();
	initCountTable();
	initBackground();
	initLabel();
	this->scheduleUpdate();

	return true;
}

void BackgroundLayer::update(float _dt)
{
	scrollBackground(_dt);
	repositionImage();
	setLabelString(life, score);
}

void BackgroundLayer::initBackground()
{
	for (int imgCount = 0; imgCount < ECount::kImage; ++imgCount)
	{
		backgroundImage[imgCount] = Sprite::create("Background/BackgroundSprite.png");
		imgHeight = backgroundImage[imgCount]->getContentSize().height * backgroundImage[imgCount]->getScale();
		backgroundImage[imgCount]->setAnchorPoint(Vec2::ZERO);
		backgroundImage[imgCount]->setPosition(Vec2(0.0f, imgCount * imgHeight));
		this->addChild(backgroundImage[imgCount], 3);
	}
}

void BackgroundLayer::scrollBackground(float _dt)
{
	for (int imgCount = 0; imgCount < ECount::kImage; ++imgCount)
	{
		Vec2 currentPos = backgroundImage[imgCount]->getPosition();
		currentPos.y -= imgScrollSpeed * _dt;
		backgroundImage[imgCount]->setPosition(currentPos);
	}
}

int BackgroundLayer::getImageLastIndex()
{
	int lastIdx = 0;
	for (int imgCount = 0; imgCount < ECount::kImage; imgCount++)
	{
		if (backgroundImage[lastIdx]->getPosition().y < backgroundImage[imgCount]->getPosition().y)
		{
			lastIdx = imgCount;
		}
	}
	
	return lastIdx;
}

void BackgroundLayer::repositionImage()
{
	for (int imgCount = 0; imgCount < ECount::kImage; imgCount++)
	{
		Vec2 currentPos = backgroundImage[imgCount]->getPosition();
		
		if (currentPos.y < -imgHeight)
		{
			int lastIdx = getImageLastIndex();
			currentPos.y = backgroundImage[lastIdx]->getPosition().y + imgHeight;
		}

		backgroundImage[imgCount]->setPosition(currentPos);
	}
}

void BackgroundLayer::initCountTable()
{
	Sprite* countTable = Sprite::create("Background/CountImage.png");
	countTable->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.65f);
	countTable->setOpacity(50);
	countTable->setScale(1.5f);
	this->addChild(countTable);
}

void BackgroundLayer::drawEndLine()
{
	Vec2 originPoint = Vec2(0, visibleSize.height * 0.21f);
	Vec2 destPoint = Vec2(visibleSize.width, visibleSize.height * 0.21f);
	DrawNode* endLine = DrawNode::create();
	endLine->drawLine(originPoint, destPoint, Color4F::RED);
	endLine->setLineWidth(0.5f);
	this->addChild(endLine);
}

void BackgroundLayer::initLabel()
{
	Size winSize = Director::getInstance()->getWinSize();
	float factorX = winSize.width / 360.0f;
	float factorY = winSize.height / 740.0f;

	lifeLabel = Label::createWithTTF("0", "fonts/arial.ttf", 20);
	lifeLabel->setAnchorPoint(Vec2::ZERO);
	lifeLabel->setPosition(visibleSize.width * 0.01f, visibleSize.height * 0.18f);
	lifeLabel->setTextColor(Color4B::WHITE);
	lifeLabel->setScaleX(factorX);
	lifeLabel->setScaleY(factorY);

	scoreLabel = Label::createWithTTF("000000", "fonts/Marker Felt.ttf", 40);
	scoreLabel->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.65f);
	scoreLabel->setTextColor(Color4B(255, 255, 255, 80));
	scoreLabel->setScaleX(factorX);
	scoreLabel->setScaleY(factorY);

	this->addChild(lifeLabel, 2);
	this->addChild(scoreLabel, 1);
}

void BackgroundLayer::setLabelString(int _life, int _score)
{
	string strLife = StringUtils::format("LIFE : %d", _life);
	lifeLabel->setString(strLife);

	string strScore = StringUtils::format("%d", _score);
	scoreLabel->setString(strScore);
}
