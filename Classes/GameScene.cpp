#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	PlayerLayer* pPlayer = PlayerLayer::create();
	this->addChild(pPlayer);

	return true;
}