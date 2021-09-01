#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	BackgroundSprite* bgSprite = BackgroundSprite::create();
	this->addChild(bgSprite);

	pPlayer = PlayerLayer::create();
	this->addChild(pPlayer);

	pEnemy = EnemyLayer::create();
	this->addChild(pEnemy);

	pBulletLayer = pPlayer->getBulletLayer();
	this->scheduleUpdate();



	return true;
}

void GameScene::update(float _dt)
{
	collisionProcess();
}

void GameScene::collisionProcess()
{
	bulletList = pBulletLayer->getBulletList();
	enemyList = pEnemy->getEnemyList();

	if (bulletList.empty() || enemyList.empty())
	{
		return;
	}

	for (int enemyCount = 0; enemyCount < enemyList.size(); enemyCount++)
	{
		enemyBox = enemyList.at(enemyCount)->getBoundingBox();

		for (int bulletCount = 0; bulletCount < bulletList.size(); bulletCount++)
		{
			bulletBox = bulletList.at(bulletCount)->getBoundingBox();

			if (enemyBox.intersectsRect(bulletBox))
			{
				int result = compareType(enemyList.at(enemyCount), bulletList.at(bulletCount));
				matchResult(result, enemyCount, bulletCount);
			}
		}
	}
}

void GameScene::matchResult(int _val, int _eCount, int _bCount)
{
	if (_val == EType::kDraw)
	{
		pBulletLayer->removeBullet(_bCount);
	}
	else if (_val == EType::kLose)
	{
		pBulletLayer->removeBullet(_bCount);
	}
	else if (_val == EType::kWin)
	{
		pEnemy->removeEnemy(_eCount);
		pBulletLayer->removeBullet(_bCount);
	}
	else
	{
		CCLOG("Error");
		return;
	}
}

int GameScene::compareType(EnemySprite* _enemy, BulletSprite* _bullet)
{
	if (_enemy->getEnemyType() == EnemySprite::EType::kXEnemy)
	{
		if (_bullet->getBulletType() == BulletSprite::EType::kX)
		{
			// draw
			return 0;
		}

		else if (_bullet->getBulletType() == BulletSprite::EType::kC)
		{
			// win
			return 1;
		}

		else if (_bullet->getBulletType() == BulletSprite::EType::kS)
		{
			// lose
			return 2;
		}
		
		else
		{
			// error
			return 3;
		}
	}

	if (_enemy->getEnemyType() == EnemySprite::EType::kCEnemy)
	{
		if (_bullet->getBulletType() == BulletSprite::EType::kC)
		{
			// draw
			return 0;
		}

		else if (_bullet->getBulletType() == BulletSprite::EType::kS)
		{
			// win
			return 1;
		}

		else if (_bullet->getBulletType() == BulletSprite::EType::kX)
		{
			// lose
			return 2;
		}

		else
		{
			// error
			return 3;
		}
	}

	if (_enemy->getEnemyType() == EnemySprite::EType::kSEnemy)
	{
		if (_bullet->getBulletType() == BulletSprite::EType::kS)
		{
			// draw
			return 0;
		}

		else if (_bullet->getBulletType() == BulletSprite::EType::kX)
		{
			// win
			return 1;
		}

		else if (_bullet->getBulletType() == BulletSprite::EType::kC)
		{
			// lose
			return 2;
		}

		else
		{
			// error
			return 3;
		}
	}
}