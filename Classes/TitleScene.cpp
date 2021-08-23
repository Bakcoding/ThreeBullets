#include "TitleScene.h"


TitleScene* TitleScene::createScene() {
	return create();	
}

bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	initTitle();
	initButton();


	return true;
}

// ���� Ÿ��Ʋ �ΰ�
void TitleScene::initTitle()
{
	// ȭ���� ũ�⸦ ������
	Size winSize = Director::getInstance()->getWinSize();
	float positonX = winSize.width * 0.5f;
	float positionY = winSize.height * 0.7f;

	Sprite* title = Sprite::create("Title/Logo.png");
	// ��ġ ����
	title->setPosition(positonX, positionY);
	// �̹��� ũ�� ����
	title->setScale(1.5f);
	this->addChild(title);
}

// ���� ��ư
void TitleScene::initButton()
{
	Size winSize = Director::getInstance()->getWinSize();
	float positionX = winSize.width * 0.5f;
	float positionY = winSize.height * 0.3f;
	
	// ���� ��ư ��ȣ�ۿ�
	MenuItemImage* start = MenuItemImage::create(
		"Title/StartButtonNormal.png",
		"Title/StartButtonSelect.png",
		CC_CALLBACK_1(TitleScene::titlesceneCallBack, this));

	// ���� ��ư ��ȣ�ۿ�
	MenuItemImage* exit = MenuItemImage::create(
		"Title/ExitButtonNormal.png",
		"Title/ExitButtonSelect.png",
		CC_CALLBACK_1(TitleScene::titlesceneCallBack, this));

	// �̹��� ũ�� ����
	start->setScale(2.0f);
	exit->setScale(2.0f);

	// ��ư ��ġ, Menu�� ���� ��� ����, ������ �������� NULL�� �� ǥ��
	Menu* menu = Menu::create(start, exit, NULL);
	// �޴��� ���� ��ü ���� ����
	menu->alignItemsVertically();
	// ��ġ ����
	menu->setPosition(positionX, positionY);
	// ��ü �±� ����
	start->setTag(ETag::kStart);
	exit->setTag(ETag::kExit);

	this->addChild(menu);
}

// ��ư ����
void TitleScene::titlesceneCallBack(Ref* _sender)
{
	// MenuItem ���� ��ü �±׷� ����
	switch (((MenuItemImage*)_sender)->getTag())
	{
	// ����ȯ
	case ETag::kStart:
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::create()));
		break;
	// ����		
	case ETag::kExit:
		Director::getInstance()->end();
		break;
	}
}