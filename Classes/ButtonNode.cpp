#include "ButtonNode.h"

ButtonNode::ButtonNode() /*: button(NULL)*/ {}

bool ButtonNode::init()
{
	if (!Button::init())
	{
		return false;
	}

	return true;
}

bool ButtonNode::init(string _file[], Widget::ccWidgetTouchCallback _callback, Vec2 _pos)
{
	if (!Button::init())
	{
		return false;
	}

	Button* button = Button::create(
		_file[0], _file[1], _file[2]
	);

	button->setPosition(_pos);
	button->addTouchEventListener(_callback);

	this->addChild(button);

	return true;
}

void ButtonNode::alignmentHorizontal(Button* _target, float _padding)
{
	Vec2 targetPos = _target->getPosition();
	Vec2 newPos = Vec2(targetPos.x + _padding, targetPos.y);
	this->setPosition(newPos);
}

void ButtonNode::alignmentVertical(Button* _target, float _padding)
{
	Vec2 targetPos = _target->getPosition();
	Vec2 newPos = Vec2(targetPos.x, targetPos.y - _padding);
	this->setPosition(newPos);
}