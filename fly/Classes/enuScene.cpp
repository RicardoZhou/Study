#include "MenuScene.h"
#include "GameScene.h"
#include "ScheduleTest.h"

Scene* MenuScene::createScene() {
	//Scene* scene = new Scene();
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init() {
	if (!Layer::init())
		return false;

	auto size = Director::getInstance()->getVisibleSize();

	//����һ�����飬������ʾ��������
	auto bg = Sprite::create("main.jpg");

	this->addChild(bg);

	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));

	//��ӱ���ͼƬ
	auto title = Sprite::create("title.png");
	title->setPosition(Vec2(size.width*0.75, size.height*0.5));
	this->addChild(title);

	auto moveUp = MoveBy::create(1, Vec2(0, 20));
	auto moveDown = MoveBy::create(1, Vec2(0, -20));
	auto sequence = Sequence::create(moveUp, moveDown, NULL);
	auto repeat = RepeatForever::create(sequence);
	title->runAction(repeat);

	//���������Ϸ�İ�ť
	auto btn = Button::create("start11.png", "start2.png");
	this->addChild(btn);
	btn->setPosition(Vec2(size.width / 4, size.height / 2));
	//��ť������
	btn->addTouchEventListener(CC_CALLBACK_2(MenuScene::touchEvent, this));


	return true;
}

//��ť������
void MenuScene::touchEvent(Ref* sender, Widget::TouchEventType type) {
	switch (type) {
	case Widget::TouchEventType::ENDED:
		{
			auto destScene = ScheduleTest::createScene();
			Director::getInstance()->pushScene(destScene);
		}
		break;
	default:
		break;
	}
};