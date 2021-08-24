#include "GameScene.h"

GameScene* GameScene::createScene()
{
	return create();
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	PlayerLayer* pPlayerLayer = PlayerLayer::create();
	pPlayerLayer->PlayerLayer::init();
	this->addChild(pPlayerLayer);

	return true;
}