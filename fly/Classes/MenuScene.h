#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"

//命名空间
USING_NS_CC;

//Button的命名空间
using namespace ui;

class MenuScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MenuScene);

	//按钮处理函数
	void touchEvent(Ref* sender, Widget::TouchEventType type);
};

#endif // !_MENU_SCENE_H_