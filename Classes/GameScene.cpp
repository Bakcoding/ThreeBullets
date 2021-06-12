#include "GameScene.h"
#include "CharLayer.h"
#include "BGLayer.h"
#include "EnemyLayer.h"
#include "BulletSprite.h"
#include "EnemySprite.h"
#include "GameOverScene.h"
#include "Effect.h"
#include "ScoreManager.h"

GameScene::GameScene() : Life(3), bulletbox(Rect::ZERO), enemybox(Rect::ZERO), i(0), j(0), Score(0) {}
GameScene::~GameScene() {}

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
	if (!Scene::init()) return false;

	pBGLayer = BGLayer::create();
	this->addChild(pBGLayer);

	pCharLayer = CharLayer::create();
	this->addChild(pCharLayer);

	pEnemyLayer = EnemyLayer::create();
	this->addChild(pEnemyLayer);

	pEffect = Effect::create();
	this->addChild(pEffect);

	ScoreInit();
	Lifeinit();

	this->scheduleUpdate();
	return true;
}
void GameScene::update(float _dt)
{
	lifecount();
	CheckCollision();
	ScorePrint();
	LifePrint();
	EnemyReach();

}

// 충돌 검사
void GameScene::CheckCollision()
{
	// 총알과 적 정보가 담긴 리스트 가져온다.
	playerbulletlist = pCharLayer->GetPlayerBulletList();
	enemylist = pEnemyLayer->GetEnemyList();
	// 총알을 기준으로 적의 타입을 구분하여 판정한다.
	for (i = 0; i < playerbulletlist.size(); ++i)
	{
		// 총알이 발사되지 않았을 경우 함수 종료
		if (playerbulletlist.empty())
		{
			return;
		}
		// 총알이 발사된 경우 함수 실행
		else
		{
			for (j = 0; j < enemylist.size(); ++j)
			{
				bulletbox = playerbulletlist.at(i)->getBoundingBox();
				enemybox = enemylist.at(j)->getBoundingBox();

				if (bulletbox.intersectsRect(enemybox))
				{
					// 이겼을 때, 상성에 맞춰서 조건문 비교
					if ((playerbulletlist.at(i)->GetType() == BulletSprite::EType::kX) && (enemylist.at(j)->GetType() == EnemySprite::EType::kES) ||
						(playerbulletlist.at(i)->GetType() == BulletSprite::EType::kC) && (enemylist.at(j)->GetType() == EnemySprite::EType::kEX) ||
						(playerbulletlist.at(i)->GetType() == BulletSprite::EType::kS && enemylist.at(j)->GetType() == EnemySprite::EType::kEC))
					{
						// 점수 획득, 리스트 정리
						AddScore(10);
						pCharLayer->removeChild(playerbulletlist.at(i));
						pCharLayer->RemoveBulletlist(i);

						pEnemyLayer->removeChild(enemylist.at(j));
						pEnemyLayer->RemoveEnemylist(j);
					}
#pragma region 패배, 동승 경우
					// 졌을 때
					else if ((playerbulletlist.at(i)->GetType() == BulletSprite::EType::kX && enemylist.at(j)->GetType() == EnemySprite::EType::kEC) ||
						(playerbulletlist.at(i)->GetType() == BulletSprite::EType::kC && enemylist.at(j)->GetType() == EnemySprite::EType::kES) ||
						(playerbulletlist.at(i)->GetType() == BulletSprite::EType::kS && enemylist.at(j)->GetType() == EnemySprite::EType::kEX))
					{
						// life--
						loseLife(1);
						pCharLayer->removeChild(playerbulletlist.at(i));
						pCharLayer->RemoveBulletlist(i);

						return;
					}
					// 비겼을 때
					else if ((playerbulletlist.at(i)->GetType() == BulletSprite::EType::kX && enemylist.at(j)->GetType() == EnemySprite::EType::kEX) ||
						(playerbulletlist.at(i)->GetType() == BulletSprite::EType::kC && enemylist.at(j)->GetType() == EnemySprite::EType::kEC) ||
						(playerbulletlist.at(i)->GetType() == BulletSprite::EType::kS && enemylist.at(j)->GetType() == EnemySprite::EType::kES))
					{
						pCharLayer->removeChild(playerbulletlist.at(i));
						pCharLayer->RemoveBulletlist(i);

						return;
					}
#pragma endregion
					else return;
				}
			}
		}
	}
}

void GameScene::EnemyReach()
{
	BGLayer* pEndline = BGLayer::create();
	auto edline = pEndline->GetEndline();
	enemylist = pEnemyLayer->GetEnemyList();
	Rect rtedline = edline->getBoundingBox();

	for (int k = 0; k < enemylist.size(); ++k)
	{
		Rect rtenemy = enemylist.at(k)->getBoundingBox();

		if (rtedline.intersectsRect(rtenemy))
		{
			loseLife(1);
			pEnemyLayer->removeChild(enemylist.at(k));
			pEnemyLayer->RemoveEnemylist(k);
			return;
		}
	}
}


void GameScene::lifecount()
{
	if (Life <= 0)
	{	
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameOverScene::create()));
	}
}

void GameScene::loseLife(int _n)
{
	pEffect->HitEffect();
	Life -= _n;
}

void GameScene::AddScore(int _n)
{	
	ScoreManager::setScore(Score);
	ScoreManager::addScore(_n);
	Score = ScoreManager::getScore();
}

void GameScene::ScoreInit()
{
	Label* score = Label::createWithTTF("0000000000000", "fonts/arial.ttf", 15);
	this->addChild(score, 35, "scorelabel");
	score->setPosition(Vec2(50, 50));
	score->setTextColor(Color4B(255, 255, 255, 255));
}

void GameScene::ScorePrint()
{
	Label* scorelabel = (Label*)this->getChildByName("scorelabel");
	string str = StringUtils::format("SCORE : %d", Score);
	scorelabel->setString(str);
}

void GameScene::Lifeinit()
{
	Label* life = Label::createWithTTF("0000000000000", "fonts/arial.ttf", 15);
	this->addChild(life, 35, "lifelabel");
	life->setPosition(Vec2(310, 50));
	life->setTextColor(Color4B(255, 255, 255, 255));
}

void GameScene::LifePrint()
{
	Label* lifelabel = (Label*)this->getChildByName("lifelabel");
	string str = StringUtils::format("LIFE : %d", Life);
	lifelabel->setString(str);
}
