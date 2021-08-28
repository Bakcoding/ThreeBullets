#include "CreateButton.h"

CreateButton::CreateButton() : fileName{""}, type(Widget::TextureResType::LOCAL) {}

bool CreateButton::init()
{
	if (!Button::init())
	{
		return false;
	}

	return true;
}

bool CreateButton::init(const string _file[], Widget::TextureResType _type)
{
	if (!Button::init(_file[0],	_file[1], _file[2], _type))
	{
		return false;
	}

	fileName[0] = _file[0];
	fileName[1] = _file[1];
	fileName[2] = _file[2];
	type = _type;

	//Button* button = Button::create(
	//	_file[0], _file[1], _file[2]
	//);

	//button->setPosition(_pos);
	//button->addTouchEventListener(_callback);

	//this->addChild(button);

	return true;
}

void CreateButton::alignmentHorizontal(Button* _target, float _padding)
{
	Vec2 targetPos = _target->getPosition();
	Vec2 newPos = Vec2(targetPos.x + _padding, targetPos.y);
	this->setPosition(newPos);
}

void CreateButton::alignmentVertical(Button* _target, float _padding)
{
	Vec2 targetPos = _target->getPosition();
	Vec2 newPos = Vec2(targetPos.x, targetPos.y - _padding);
	this->setPosition(newPos);
}