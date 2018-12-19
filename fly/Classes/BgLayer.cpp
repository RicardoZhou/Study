#include "BgLayer.h"

bool BgLayer::init() {
	if (!Layer::init())
		return false;

	//����3�㱳��
	createBackgrounds();

	return true;
}

void BgLayer::createBackgrounds() {
	auto size = Director::getInstance()->getVisibleSize();
	//����һ����Զ�ı���
	auto bg1Sprite = Sprite::create("bj1.jpg");
	bg1Sprite->setPosition(size.width * 0.5, size.height * 0.5);
	addChild(bg1Sprite);
	bg1Sprite->setZOrder(-4);

	//����һ����Զ�ı���
	auto farBg1 = Sprite::create("bj2.png");
	auto farBg2 = Sprite::create("bj2.png");
	this->farBackground.push_back(farBg1);
	this->farBackground.push_back(farBg2);
	farBg1->setAnchorPoint(Vec2(0, 0));
	farBg2->setAnchorPoint(Vec2(0, 0));
	farBg1->setPosition(Vec2(0, 10));
	farBg2->setPosition(Vec2(farBg1->getContentSize().width, 10));
	farBg1->setZOrder(-3);
	farBg2->setZOrder(-3);
	addChild(farBg1);
	addChild(farBg2);

	//���һ���Ͻ��ı���
	auto nearBg1 = Sprite::create("bj3.png");
	auto nearBg2 = Sprite::create("bj3.png");
	this->nearBackground.push_back(nearBg1);
	this->nearBackground.push_back(nearBg2);
	nearBg1->setAnchorPoint(Vec2(0, 0));
	nearBg2->setAnchorPoint(Vec2(0, 0));
	nearBg1->setPosition(Vec2(0, 0));
	nearBg2->setPosition(Vec2(nearBg1->getContentSize().width, 0));
	nearBg1->setZOrder(-2);
	nearBg2->setZOrder(-2);
	addChild(nearBg1);
	addChild(nearBg2);

	//��ӵ�ͼ
	this->map = TMXTiledMap::create("map.tmx");
	map->setAnchorPoint(Vec2::ZERO);
	map->setPosition(Vec2::ZERO);
	addChild(map, -1);// => addChild, setZOrder(-1)

	this->scheduleUpdate();
}

void BgLayer::update(float dt) {
	//�Ƚ�Զ�ı���
	Sprite* sprite1 = this->farBackground[0];
	Sprite* sprite2 = this->farBackground[1];

	float speed = 50;
	auto offset = speed * dt;
	auto newPosX1 = sprite1->getPositionX() - offset;
	auto newPosX2 = newPosX1 + sprite1->getContentSize().width;

	if (newPosX2 <= 0) {
		newPosX1 = 0;
		newPosX2 = sprite1->getContentSize().width;
	}
	sprite1->setPositionX(newPosX1);
	sprite2->setPositionX(newPosX2);

	//�ȽϽ��ı���
	sprite1 = this->nearBackground[0];
	sprite2 = this->nearBackground[1];

	speed = 100;
	offset = speed * dt;
	newPosX1 = sprite1->getPositionX() - offset;
	newPosX2 = newPosX1 + sprite1->getContentSize().width;

	if (newPosX2 <= 0) {
		newPosX1 = 0;
		newPosX2 = sprite1->getContentSize().width;
	}
	sprite1->setPositionX(newPosX1);
	sprite2->setPositionX(newPosX2);

	//��ӵ�ͼ
	auto size = Director::getInstance()->getVisibleSize();
	speed = 130;
	float newPosX = map->getPositionX() - speed * dt;
	if (newPosX <= size.width - map->getContentSize().width)
	{
		log("game end!!!");
		this->unscheduleUpdate();//ȡ��ʱ�����
	}

	map->setPositionX(newPosX);
}