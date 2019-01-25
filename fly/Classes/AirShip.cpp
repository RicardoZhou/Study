#include "AirShip.h"

bool AirShip::init() {
	if (!Node::init())
		return false;

	_airship = Sprite::create("airship.png");
	_airship->setPosition(Vec2::ZERO);
	addChild(_airship);

	auto airshipBody = PhysicsBody::createCircle(
		_airship->getContentSize().width / 2,
		PhysicsMaterial(0, 0, 0));
	airshipBody->setGravityEnable(false);
	this->setPhysicsBody(airshipBody);

	auto moveUp = MoveBy::create(3, Vec2(0, _airship->getContentSize().height / 2));
	auto moveDown = MoveBy::create(3, Vec2(0, -_airship->getContentSize().height / 2));
	auto seq = Sequence::create(moveUp, moveDown, NULL);
	auto act = RepeatForever::create(seq);
	this->runAction(act);

	return true;
}