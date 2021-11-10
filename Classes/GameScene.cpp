#include "GameScene.h"

GameScene::GameScene() : 
	pPlayer(NULL), pEnemy(NULL), pBullet(NULL), pBGLayer(NULL), pEffect(NULL), bulletList(NULL), enemyList(NULL), bulletBox(Rect::ZERO), enemyBox(Rect::ZERO),
	life(3), point(10), score(0), enemyPoint(10), isGameover(false) {}

// ���� �� ����
bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	pPlayer = PlayerLayer::create();
	this->addChild(pPlayer, 3);

	pBGLayer = BackgroundLayer::create();
	this->addChild(pBGLayer, 1);

	pEffect = EffectSprite::create();
	this->addChild(pEffect, 0);


	pEnemy = EnemyLayer::create();
	this->addChild(pEnemy, 2);

	pBullet = pPlayer->getBulletLayer();
	ScoreManager::setTotalScore(0);

	this->scheduleUpdate();

	return true;
}

// �浹, ����, �� ���� ���� ������Ʈ
void GameScene::update(float _dt)
{
	if (!isGameover)
	{
		collisionProcess();
		setLabelValue();
		enemyProcess();
	}
}
// �浹 ó��
// �Ѿ� vs ��
void GameScene::collisionProcess()
{
	// �Ѿ� ����Ʈ
	bulletList = pBullet->getBulletList();
	// �� ����Ʈ
	enemyList = pEnemy->getEnemyList();

	// ����Ʈ ����ִٸ� �Լ� ����
	if (bulletList.empty() || enemyList.empty())
	{
		return;
	}
	
	// �ٿ�� �ڽ��� ����� �浹 üũ
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

// �� vs �Ѿ� �浹 ��� ó��
void GameScene::matchResult(int _val, int _eCount, int _bCount)
{
	// enum���� �� �� �� ���� �� �Ҵ�, ������ ��
	// ��
	if (_val == EType::kDraw)
	{
		pBullet->removeBullet(_bCount);
	}
	// ��
	else if (_val == EType::kLose)
	{
		loseLife();
		pBullet->removeBullet(_bCount);
	}
	// ��
	else if (_val == EType::kWin)
	{
		addScore(point);
		pEnemy->removeEnemy(_eCount);
		pBullet->removeBullet(_bCount);
	}
}

// ���� �Ѿ� �󼺺�, ���� ��ȯ ��:0 ��:1 ��:2
/*
	�� ����
		C
	  ��	  ��
	S	��	X
*/
#pragma region counterCompare
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
	}
	
	return 3;
}
#pragma endregion 

// ǥ�õǴ� ����, ��� ����
void GameScene::setLabelValue()
{
	pBGLayer->setLabelString(life, score);
}

// ���� ȹ��
void GameScene::addScore(int _score)
{
	ScoreManager::addTotalScore(_score);
	score = ScoreManager::getTotalScore();
}

// ��� �ҽ�
void GameScene::loseLife()
{
	life--;
	pEffect->setIsHit(true);

	if (life <= 0)
	{
		isGameover = true;
		gameOver();
	}

}

// �� ������ ����Ŭ
// �Ѿ˿� ���ŵ��� �ʰ� �Ʒ����� �������� ��
void GameScene::enemyProcess()
{
	for (int enemyCount = 0; enemyCount < enemyList.size(); enemyCount++)
	{
		if (enemyList.at(enemyCount)->isDead())
		{
			loseLife();
			enemyList.at(enemyCount)->setEnemyDead(false);
			pEnemy->removeEnemy(enemyCount);
		}
	}
}

// ���ӿ��� �÷��� Ȯ�� �� 
// ���� ���� ������ ��ȯ
void GameScene::gameOver()
{
	if (isGameover)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameoverScene::create()));
	}
}