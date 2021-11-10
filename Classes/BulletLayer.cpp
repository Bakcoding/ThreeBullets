#include "BulletLayer.h"

BulletLayer::BulletLayer() :
	bullet(NULL), xButton(NULL), cButton(NULL), sButton(NULL), bulletList(NULL),
	visibleSize(Director::getInstance()->getVisibleSize()), moveDir(Vec2(0, 1)), moveSpeed(700.0f), bulletIsDead(false), playerPos(Vec2::ZERO),
	strXBullet{"Bullet/XBullet.png"},
	strCBullet{"Bullet/CBullet.png"},
	strSBullet{"Bullet/SBullet.png"},

	strXButton{ "Button/XButtonNormal.png", "Button/XButtonSelect.png", "Button/XButtonSelect.png" },
	strCButton{ "Button/CButtonNormal.png", "Button/CButtonSelect.png", "Button/CButtonSelect.png" },
	strSButton{ "Button/SButtonNormal.png", "Button/SButtonSelect.png", "Button/SButtonSelect.png" } {}

// �Ѿ� ���� Ʈ���� Ŭ����
bool BulletLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initButton();
	
	this->scheduleUpdate();

	return true;
}

void BulletLayer::update(float _dt)
{
	bulletProcess();
}

// CreateButton Ŭ���� ��� ��ư����
// 3���� �Ѿ�, 3���� ��ư, X S C
bool BulletLayer::initButton()
{
	Vec2 xPos = Vec2(visibleSize.width * 0.6225f, visibleSize.height * 0.0575f);
	Vec2 cPos = Vec2(visibleSize.width * 0.74f, visibleSize.height * 0.155f);
	Vec2 sPos = Vec2(visibleSize.width * 0.85f, visibleSize.height * 0.0575f);

	xButton = CreateButton::create();
	cButton = CreateButton::create();
	sButton = CreateButton::create();

	if (xButton == nullptr || !xButton->init(strXButton, Widget::TextureResType::LOCAL))
	{
		return false;
	}
	if (cButton == nullptr || !cButton->init(strCButton, Widget::TextureResType::LOCAL))
	{
		return false;
	}
	if (sButton == nullptr || !sButton->init(strSButton, Widget::TextureResType::LOCAL))
	{
		return false;
	}

	xButton->addTouchEventListener(CC_CALLBACK_2(BulletLayer::touchXButton, this));
	cButton->addTouchEventListener(CC_CALLBACK_2(BulletLayer::touchCButton, this));
	sButton->addTouchEventListener(CC_CALLBACK_2(BulletLayer::touchSButton, this));
	
	xButton->setPosition(xPos);
	cButton->setPosition(cPos);
	sButton->setPosition(sPos);

	this->addChild(xButton);
	this->addChild(cButton);
	this->addChild(sButton);

	return true;
}

// X��ư ������ �� X�Ѿ� �߻�
void BulletLayer::touchXButton(Ref* _sender, Widget::TouchEventType _type)
{
	switch(_type)
	{
	case Widget::TouchEventType::BEGAN:
		bullet = shootBullet(BulletSprite::EType::kX);
		bulletList.pushBack(bullet);
		this->addChild(bullet);
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

// C
void BulletLayer::touchCButton(Ref* _sender, Widget::TouchEventType _type)
{
	switch (_type)
	{
	case Widget::TouchEventType::BEGAN:
		bullet = shootBullet(BulletSprite::EType::kC);
		bulletList.pushBack(bullet);
		this->addChild(bullet);
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

// S
void BulletLayer::touchSButton(Ref* _sender, Widget::TouchEventType _type)
{
	switch (_type)
	{
	case Widget::TouchEventType::BEGAN:
		bullet = shootBullet(BulletSprite::EType::kS);
		bulletList.pushBack(bullet);
		this->addChild(bullet);
		break;
	case Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

// �Ѿ� �߻�
// �Ѿ� �ʱ�ȭ, ���� 
BulletSprite* BulletLayer::shootBullet(BulletSprite::EType _type)
{
	bullet = BulletSprite::create();
	bullet->init(_type, moveDir, moveSpeed);
	bullet->setPosition(playerPos + Vec2(0, 25.0f));
	bullet->setScale(0.6f);

	return bullet;
}

// �Ѿ� ��ġ = �÷��̾� ��ġ
void BulletLayer::setBulletPos(Vec2 _pos)
{
	playerPos = _pos;
}

// ���� �Ѿ� ã�Ƽ� ����Ʈ���� ����
void BulletLayer::bulletProcess()
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		if (bulletList.at(i)->isDead())
		{
			removeBullet(i);
		}
	}
}

// �Ѿ��� ����Ʈ���� ����
void BulletLayer::removeBullet(int _idx)
{
	this->removeChild(bulletList.at(_idx));
	bulletList.erase(_idx);
}

Vector<BulletSprite*> BulletLayer::getBulletList()
{
	return this->bulletList;
}
