#ifndef _CREATE_BUTTON_H_
#define _CREATE_BUTTON_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace std;
using namespace ui;

class CreateButton : public Button
{
private:
	//Button* button;
public:
	CreateButton();
	CREATE_FUNC(CreateButton);
	bool init();
	bool init(string _file[], Widget::ccWidgetTouchCallback _callback, Vec2 _pos);

	void alignmentHorizontal(Button* _target, float _padding);
	void alignmentVertical(Button* _target, float _padding);
};

#endif