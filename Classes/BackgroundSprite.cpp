#include "BackgroundSprite.h"

BackgroundSprite::BackgroundSprite() :
	backgroundImage{ NULL }, imgScrollSpeed(1000.0f), imgHeight(0),
	visibleSize(Director::getInstance()->getVisibleSize()) {}

bool BackgroundSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	drawEndLine();
	initBackground();
	
	this->scheduleUpdate();

	return true;
}

void BackgroundSprite::update(float _dt)
{
	scrollBackground(_dt);
	repositionImage();
}

void BackgroundSprite::initBackground()
{
	for (int imgCount = 0; imgCount < ECount::kImage; ++imgCount)
	{
		backgroundImage[imgCount] = Sprite::create("Background/BackgroundSprite.png");
		imgHeight = backgroundImage[imgCount]->getContentSize().height * backgroundImage[imgCount]->getScale();
		backgroundImage[imgCount]->setAnchorPoint(Vec2::ZERO);
		backgroundImage[imgCount]->setPosition(Vec2(0.0f, imgCount * imgHeight));
		this->addChild(backgroundImage[imgCount]);
	}
}

void BackgroundSprite::scrollBackground(float _dt)
{
	for (int imgCount = 0; imgCount < ECount::kImage; ++imgCount)
	{
		Vec2 currentPos = backgroundImage[imgCount]->getPosition();
		currentPos.y -= imgScrollSpeed * _dt;
		backgroundImage[imgCount]->setPosition(currentPos);
	}
}

int BackgroundSprite::getImageLastIndex()
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

void BackgroundSprite::repositionImage()
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

void BackgroundSprite::drawEndLine()
{
	Vec2 originPoint = Vec2(0, visibleSize.height * 0.21f);
	Vec2 destPoint = Vec2(visibleSize.width, visibleSize.height * 0.21f);
	DrawNode* endLine = DrawNode::create();
	endLine->drawLine(originPoint, destPoint, Color4F::RED);
	endLine->setLineWidth(0.5f);
	this->addChild(endLine);
}