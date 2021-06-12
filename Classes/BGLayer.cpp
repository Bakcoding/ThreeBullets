#include "BGLayer.h"
#include "GameScene.h"

BGLayer::BGLayer() : m_pSpace{ nullptr }, m_fSpaceScrollSpeed(500.0f), m_fSpaceContentHeight(0.0f) {}
BGLayer::~BGLayer(){}

BGLayer* BGLayer::create()
{
	BGLayer* pBGLayer = new BGLayer;
	if (pBGLayer != nullptr && pBGLayer->init())
	{
		pBGLayer->autorelease();
		return pBGLayer;
	}
	else
	{
		if (pBGLayer != nullptr)
		{
			delete pBGLayer;
			pBGLayer = nullptr;
		}
	}
	return nullptr;
}

bool BGLayer::init()
{
	if (!Layer::init()) return false;

	InitBGScpace();
	InitLine();
	InitEndline();

	this->scheduleUpdate();

	return true;
}

void BGLayer::update(float _dt)
{
	BGScrollSpace(_dt);
	ScreenOutSpace();
}

void BGLayer::InitBGScpace()
{
	for (int i = 0; i < ELen::kSpace; ++i)
	{
		m_pSpace[i] = Sprite::create("Background/BGstar.png");
		{
			m_fSpaceContentHeight = m_pSpace[i]->getContentSize().height * m_pSpace[i]->getScale();
			m_pSpace[i]->setAnchorPoint(Vec2::ZERO);
		}
		m_pSpace[i]->setPosition(Vec2(0.0f, i * m_fSpaceContentHeight));
		this->addChild(m_pSpace[i], 4);
	}
}

void BGLayer::BGScrollSpace(float _dt)
{
	Vec2 curPos = Vec2::ZERO;
	for (int i = 0; i < ELen::kSpace; ++i)
	{
		Vec2 curPos = m_pSpace[i]->getPosition();
		curPos.y -= m_fSpaceScrollSpeed * _dt;
		m_pSpace[i]->setPosition(curPos);
	}
}

int BGLayer::GetLastIndexWithSpace()
{
	int lastIdx = 0;
	for (int i = 0; i < ELen::kSpace; ++i)
	{
		if (m_pSpace[lastIdx]->getPosition().y < m_pSpace[i]->getPosition().y)
		{
			lastIdx = i;
		}
	}
	return lastIdx;
}

void BGLayer::ScreenOutSpace()
{
	for (int i = 0; i < ELen::kSpace; ++i)
	{
		Vec2 curPos = m_pSpace[i]->getPosition();
		if (curPos.y < -m_fSpaceContentHeight)
		{
			int maXidx = GetLastIndexWithSpace();
			curPos.y = m_pSpace[maXidx]->getPosition().y + m_fSpaceContentHeight;
		}
		m_pSpace[i]->setPosition(curPos);
	}
}

void BGLayer::InitLine()
{
	Size winSize = Director::getInstance()->getWinSize();
	Sprite* BGLine = Sprite::create("Background/BGLine.png");
	BGLine->setAnchorPoint(Vec2::ZERO);
	this->addChild(BGLine);
}

void BGLayer::InitEndline()
{
	endline = Sprite::create("Background/EndLine.png");
	endline->setPosition(Vec2(180, 65));
	this->addChild(endline);
}

Sprite* BGLayer::GetEndline()
{
	return endline;
}