#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"

//�����ռ�
USING_NS_CC;

//Button�������ռ�
using namespace ui;

class MenuScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MenuScene);

	//��ť������
	void touchEvent(Ref* sender, Widget::TouchEventType type);
};

#endif // !_MENU_SCENE_H_