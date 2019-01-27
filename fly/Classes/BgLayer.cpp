#include "BgLayer.h"
#include "Heart.h"
#include "AirShip.h"
#include "Bird.h"

bool BgLayer::init() {
	if (!Layer::init())
		return false;

	//创建3层背景
	createBackgrounds();

	//创建奖品
	//addHearts();
	addObject("heart", (CreateObjectFunc)Heart::create);
	//创建飞船
	//addAirShips();
	addObject("airship", (CreateObjectFunc)AirShip::create);
	//创建飞鸟
	//addBirds();
	addObject("bird", (CreateObjectFunc)Bird::create);

	return true;
}

void BgLayer::createBackgrounds() {
	auto size = Director::getInstance()->getVisibleSize();
	//创建一个极远的背景
	auto bg1Sprite = Sprite::create("bj1.jpg");
	bg1Sprite->setPosition(size.width * 0.5, size.height * 0.5);
	addChild(bg1Sprite);
	bg1Sprite->setZOrder(-4);

	//创建一个极远的背景
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

	//添加一个较近的背景
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

	//添加地图
	this->map = TMXTiledMap::create("map.tmx");
	map->setAnchorPoint(Vec2::ZERO);
	map->setPosition(Vec2::ZERO);
	addChild(map, -1);// => addChild, setZOrder(-1)

	//背景最开始不滚动
	//this->scheduleUpdate();

	//添加天空的边界（天花板），地面
	auto groundHeight = map->getContentSize().height * 0.19;
	auto skyHeight = map->getContentSize().height * 0.9;
	auto width = size.width;//map->getContentSize().width;	天空地面不需要移动，所以仅需屏幕宽度

	auto groundBody = PhysicsBody::createEdgeSegment(Vec2(0, groundHeight), Vec2(width, groundHeight));
	auto groundNode = Node::create();
	addChild(groundNode);
	groundNode->setPhysicsBody(groundBody);

	auto skyBody = PhysicsBody::createEdgeSegment(Vec2(0, skyHeight), Vec2(width, skyHeight));
	auto skyNode = Node::create();
	addChild(skyNode);
	skyNode->setPhysicsBody(skyBody);
}

void BgLayer::update(float dt) {
	//比较远的背景
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

	//比较近的背景
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

	//添加地图
	auto size = Director::getInstance()->getVisibleSize();
	speed = 130;
	float newPosX = map->getPositionX() - speed * dt;
	if (newPosX <= size.width - map->getContentSize().width)
	{
		log("game end!!!");
		this->unscheduleUpdate();//取消时间调度
	}

	map->setPositionX(newPosX);
}

void BgLayer::startScroll() {
	this->scheduleUpdate();
}

/*
void BgLayer::addHearts() {
	auto hearts = map->getObjectGroup("heart")->getObjects();

	for (auto object : hearts) {
		auto heartObject = object.asValueMap();
		auto x = heartObject["x"].asFloat();
		auto y = heartObject["y"].asFloat();

		auto heart = Heart::create();
		heart->setPosition(x, y);
		map->addChild(heart);
	}
}

void BgLayer::addAirShips() {
	auto objs = map->getObjectGroup("airship")->getObjects();

	for (auto object : objs) {
		auto obj = object.asValueMap();
		auto x = obj["x"].asFloat();
		auto y = obj["y"].asFloat();

		auto ship = AirShip::create();
		ship->setPosition(x, y);
		map->addChild(ship);
	}
}

void BgLayer::addBirds() {
	auto objs = map->getObjectGroup("bird")->getObjects();

	for (auto object : objs) {
		auto obj = object.asValueMap();
		auto x = obj["x"].asFloat();
		auto y = obj["y"].asFloat();

		auto bird = Bird::create();
		bird->setPosition(x, y);
		map->addChild(bird);
	}
}
*/

void BgLayer::addObject(std::string name, CreateObjectFunc func) {
	auto objs = map->getObjectGroup(name)->getObjects();

	for (auto object : objs) {
		auto obj = object.asValueMap();
		auto x = obj["x"].asFloat();
		auto y = obj["y"].asFloat();

		auto bird = func();
		bird->setPosition(x, y);
		map->addChild(bird);
	}
}