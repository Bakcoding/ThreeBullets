#include "GameScene.h"

GameScene* GameScene::createScene()
{
	return create();
}

GameScene* GameScene::create()
{
	GameScene* pGameScene = new GameScene;
	if (pGameScene != nullptr && pGameScene->init())
	{
		pGameScene->autorelease();
		return pGameScene;
	}
	else
	{
		if (pGameScene != nullptr)
		{
			delete pGameScene;
			pGameScene = nullptr;
		}
	}
	return nullptr;
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	PlayerLayer* player = PlayerLayer::create();
	this->addChild(player);


	return true;
}