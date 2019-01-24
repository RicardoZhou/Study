#include "Hero.h"

bool Hero::init() {
	if (!Node::init())
		return false;

	this->hero = Sprite::create("flying1.png");
	this->hero->setPosition(Vec2::ZERO);
	addChild(this->hero);

	//添加一个刚体
	auto heroBody = PhysicsBody::createBox(
		//刚体的形状
		hero->getContentSize(),
		//刚体的物理特性(密度，弹性系数，摩擦力)
		PhysicsMaterial(10, 0.1, 0.1)
	);
	//把物理世界的刚体对象和游戏世界中的组件关联起来
	//我们把这个刚体对象和这个Node对象关联，而不是Node中的子节点Hero对象
	this->setPhysicsBody(heroBody);

	//初始化动画缓存
	initAnimationCach();

	//最开始时，让Hero重力无效
	this->getPhysicsBody()->setGravityEnable(false);

	return true;
}

void Hero::initAnimationCach() {
	//auto sprite = Sprite::create();
	//auto frame = sprite->getSpriteFrame();
	//Vector<SpriteFrame*> frames;
	//auto animation = Animation::createWithSpriteFrames(多个精灵帧序列 frames，每帧的延时);
	//AnimationCache::getInstance()->addAnimation(动画 animation，动画名称);

	//飞行，下降，死亡
	const int size = 3;
	int frameSize[size] = { 4, 3, 4 };
	char* prefix[size] = { "flying", "drop", "die" };
	for (int k = 0; k < size; k++) {
		Vector<SpriteFrame*> spriteFrame;
		for (int i = 1; i <= frameSize[k]; i++) {
			char fileName[32];
			sprintf(fileName, "%s%d.png", prefix[k], i);
			auto sprite = Sprite::create(fileName);
			auto frame = sprite->getSpriteFrame();
			spriteFrame.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(spriteFrame, 0.1);
		AnimationCache::getInstance()->addAnimation(animation, prefix[k]);
	}
	Vector<SpriteFrame*> frames;
}

void Hero::fly() {
	//停止当前的所有动作
	hero->stopAllActions();
	//准备从动画缓存中获取动画
	auto cache = AnimationCache::getInstance();
	//从动画缓存中获取指定动画
	auto animation = cache->getAnimation("flying");
	//根据"动画"来创建一个"动画动作"(Animation)
	auto animate = Animate::create(animation);
	//创建一个永久循环动作
	auto repeatAct = RepeatForever::create(animate);
	//让指定结点来执行这个动作
	hero->runAction(repeatAct);
}

void Hero::drop() {
	hero->stopAllActions();
	auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("drop"));
	auto repeatAct = RepeatForever::create(animate);
	hero->runAction(repeatAct);
}

void Hero::die() {
	hero->stopAllActions();
	auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("die"));
	hero->runAction(animate);
}