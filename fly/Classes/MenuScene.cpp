#include "MenuScene.h"
#include "GameScene.h"

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

	//创建一个精灵，用来表示“背景”
	auto bg = Sprite::create("main.jpg");

	this->addChild(bg);

	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(Vec2(0, 0));

	//添加标题图片
	auto title = Sprite::create("title.png");
	title->setPosition(Vec2(size.width*0.75, size.height*0.5));
	this->addChild(title);

	auto moveUp = MoveBy::create(1, Vec2(0, 20));
	auto moveDown = MoveBy::create(1, Vec2(0, -20));
	auto sequence = Sequence::create(moveUp, moveDown, NULL);
	auto repeat = RepeatForever::create(sequence);
	title->runAction(repeat);

	//添加启动游戏的按钮
	auto btn = Button::create("start11.png", "start2.png");
	this->addChild(btn);
	btn->setPosition(Vec2(size.width / 4, size.height / 2));
	//按钮处理函数
	btn->addTouchEventListener(CC_CALLBACK_2(MenuScene::touchEvent, this));


	return true;
}

//按钮处理函数
void MenuScene::touchEvent(Ref* sender, Widget::TouchEventType type) {
	switch (type) {
	case Widget::TouchEventType::ENDED:
		{
			auto gameScene = GameScene::createScene();
			//新场景从上向下匀速移动，直到覆盖原场景
			auto destScene = TransitionMoveInT::create(2, gameScene);
			Director::getInstance()->pushScene(destScene);
		}
		break;
	default:
		break;
	}
};