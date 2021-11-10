#include "GameScene.h"

GameScene::GameScene() : 
	pPlayer(NULL), pEnemy(NULL), pBullet(NULL), pBGLayer(NULL), pEffect(NULL), bulletList(NULL), enemyList(NULL), bulletBox(Rect::ZERO), enemyBox(Rect::ZERO),
	life(3), point(10), score(0), enemyPoint(10), isGameover(false) {}

// 게임 씬 생성
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

// 충돌, 점수, 적 정보 갱신 업데이트
void GameScene::update(float _dt)
{
	if (!isGameover)
	{
		collisionProcess();
		setLabelValue();
		enemyProcess();
	}
}
// 충돌 처리
// 총알 vs 적
void GameScene::collisionProcess()
{
	// 총알 리스트
	bulletList = pBullet->getBulletList();
	// 적 리스트
	enemyList = pEnemy->getEnemyList();

	// 리스트 비어있다면 함수 종료
	if (bulletList.empty() || enemyList.empty())
	{
		return;
	}
	
	// 바운딩 박스를 씌우고 충돌 체크
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

// 적 vs 총알 충돌 결과 처리
void GameScene::matchResult(int _val, int _eCount, int _bCount)
{
	// enum으로 승 무 패 정수 값 할당, 정수로 비교
	// 무
	if (_val == EType::kDraw)
	{
		pBullet->removeBullet(_bCount);
	}
	// 패
	else if (_val == EType::kLose)
	{
		loseLife();
		pBullet->removeBullet(_bCount);
	}
	// 승
	else if (_val == EType::kWin)
	{
		addScore(point);
		pEnemy->removeEnemy(_eCount);
		pBullet->removeBullet(_bCount);
	}
}

// 적과 총알 상성비교, 정수 반환 무:0 패:1 승:2
/*
	상성 구조
		C
	  ↗	  ↘
	S	←	X
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

// 표시되는 점수, 목숨 갱신
void GameScene::setLabelValue()
{
	pBGLayer->setLabelString(life, score);
}

// 점수 획득
void GameScene::addScore(int _score)
{
	ScoreManager::addTotalScore(_score);
	score = ScoreManager::getTotalScore();
}

// 목숨 소실
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

// 적 라이프 사이클
// 총알에 제거되지 않고 아래까지 내려왔을 때
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

// 게임오버 플래그 확인 후 
// 게임 오버 씬으로 전환
void GameScene::gameOver()
{
	if (isGameover)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameoverScene::create()));
	}
}