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

	return true;
}