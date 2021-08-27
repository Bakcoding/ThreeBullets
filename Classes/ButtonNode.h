#ifndef _BUTTON_NODE_H
#define _BUTTON_NODE_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace std;
using namespace ui;

class ButtonNode : public Button
{
private:
	//Button* button;
public:
	ButtonNode();
	CREATE_FUNC(ButtonNode);
	bool init();
	bool init(string _file[], Widget::ccWidgetTouchCallback _callback, Vec2 _pos);

	void alignmentHorizontal(Button* _target, float _padding);
	void alignmentVertical(Button* _target, float _padding);
};

#endif