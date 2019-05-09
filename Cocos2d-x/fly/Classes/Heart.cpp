#include "Heart.h"

bool Heart::init() {
	if (!Node::init())
		return false;

	_heart = Sprite::create("heart.png");
	_heart->setPosition(Vec2::ZERO);
	addChild(_heart);

	auto heartBody = PhysicsBody::createCircle(_heart->getContentSize().width / 2,
		PhysicsMaterial(0, 0, 0));
	this->setPhysicsBody(heartBody);
	this->getPhysicsBody()->setGravityEnable(false);

	//碰撞检测相关的掩码
	heartBody->setCategoryBitmask(0x10);
	heartBody->setCollisionBitmask(0x36);
	heartBody->setContactTestBitmask(0x20);

	return true;
}