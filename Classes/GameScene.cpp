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

	return true;
}