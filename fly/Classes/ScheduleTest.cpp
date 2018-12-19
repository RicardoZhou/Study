#include "ScheduleTest.h"

Scene* ScheduleTest::createScene() {
	auto scene = Scene::create();
	auto layer = ScheduleTest::create();
	scene->addChild(layer);
	return scene;
};

bool ScheduleTest::init() {
	if (!Layer::init()) {
		return false;
	}

	auto size = Director::getInstance()->getVisibleSize();
	auto layer = CCLayerColor::create(Color4B::RED, 200, 200);
	this->addChild(layer);
	layer->setAnchorPoint(Vec2(0, 0.5));
	layer->ignoreAnchorPointForPosition(false);
	layer->setPosition(Vec2(0, size.height / 2));

	//����ʱ�����
	this->scheduleUpdate();

	return true;
}

void ScheduleTest::update(float dt) {
	//dt��ʾ������һ�ε���update��ʱ��������λ����
	auto size = Director::getInstance()->getVisibleSize();
	int speed = 200;//ÿ���ƶ�200����
	float offset = speed * dt;
	auto newPositionX = this->getPositionX() + offset;
	if (newPositionX > size.width) {
		newPositionX = -200;
	}
	this->setPositionX(newPositionX);
}