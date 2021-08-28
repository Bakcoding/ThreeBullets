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
	string fileName[3];
	Widget::TextureResType type;
public:
	CreateButton();
	CREATE_FUNC(CreateButton);
	virtual bool init() override;
	bool init(const string _file[], Widget::TextureResType _type);

	void alignmentHorizontal(Button* _target, float _padding);
	void alignmentVertical(Button* _target, float _padding);
};

#endif