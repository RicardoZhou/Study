#include "Bird.h"

bool Bird::init() {
	if (!Node::init())
		return false;

	_bird = Sprite::create("bird1.png");
	_bird->setPosition(Vec2::ZERO);
	addChild(_bird);

	auto birdBody = PhysicsBody::createCircle(
		_bird->getContentSize().width / 2,
		PhysicsMaterial(0, 0, 0));
	birdBody->setGravityEnable(false);
	this->setPhysicsBody(birdBody);

	Vector<SpriteFrame*> frames;
	int frameSize = 9;
	float totalTime = 0.6;
	char frameName[16];
	for (int i = 1; i <= frameSize; i++) {
		sprintf(frameName, "bird%d.png", i);
		auto sprite = Sprite::create(frameName);
		auto frame = sprite->getSpriteFrame();
		frames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(frames, totalTime / frameSize);
	auto animate = Animate::create(animation);
	auto act = RepeatForever::create(animate);
	_bird->runAction(act);

	return true;
}