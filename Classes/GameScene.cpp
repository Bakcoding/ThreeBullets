#include "GameScene.h"

GameScene::GameScene() : 
	pPlayer(NULL), pEnemy(NULL), pBullet(NULL), pBGLayer(NULL), bulletList(NULL), enemyList(NULL), bulletBox(Rect::ZERO), enemyBox(Rect::ZERO),
	life(3), point(10), score(0), enemyPoint(10), isGameover(false) {}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	pBGLayer = BackgroundLayer::create();
	this->addChild(pBGLayer, 1);

	pPlayer = PlayerLayer::create();
	this->addChild(pPlayer, 3);

	pEnemy = EnemyLayer::create();
	this->addChild(pEnemy, 2);

	pBullet = pPlayer->getBulletLayer();
	ScoreManager::setTotalScore(0);

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float _dt)
{
	if (!isGameover)
	{
		collisionProcess();
		setLabelValue();
		enemyProcess();
	}
}

void GameScene::collisionProcess()
{
	bulletList = pBullet->getBulletList();
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
		pBullet->removeBullet(_bCount);
	}
	else if (_val == EType::kLose)
	{
		loseLife();
		pBullet->removeBullet(_bCount);
	}
	else if (_val == EType::kWin)
	{
		addScore(point);
		pEnemy->removeEnemy(_eCount);
		pBullet->removeBullet(_bCount);
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

void GameScene::setLabelValue()
{
	pBGLayer->setLabelString(life, score);
}

void GameScene::addScore(int _score)
{
	ScoreManager::addTotalScore(_score);
	score = ScoreManager::getTotalScore();
}

void GameScene::loseLife()
{
	life--;
	if (life <= 0)
	{
		isGameover = true;
		gameOver();
		return;
	}

}

void GameScene::enemyProcess()
{
	for (int enemyCount = 0; enemyCount < enemyList.size(); enemyCount++)
	{
		if (enemyList.at(enemyCount)->isDead())
		{
			loseLife();
			pEnemy->removeEnemy(enemyCount);
		}
	}
}

void GameScene::gameOver()
{
	if (isGameover)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameoverScene::create()));
	}
}