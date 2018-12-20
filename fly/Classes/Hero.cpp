#include "Hero.h"

bool Hero::init() {
	if (!Node::init())
		return false;

	this->hero = Sprite::create("flying1.png");
	this->hero->setPosition(Vec2::ZERO);
	addChild(this->hero);

	//添加一个刚体
	auto heroBody = PhysicsBody::createBox(
		//刚体想形状
		this->getContentSize(),
		//刚体的物理特性(密度，弹性系数，摩擦力)
		PhysicsMaterial(10, 0.1, 0.1)
	);
	//把物理世界的刚体对象和游戏世界中的组件关联起来
	//我们把这个刚体对象和这个Node对象关联，而不是Node中的子节点Hero对象
	this->setPhysicsBody(heroBody);

	//初始化动画缓存
	initAnimationCach();

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
	std::string prefix[size] = { "flying", "draw", "die" };
	for (int k = 0; k < size; k++) {
		Vector<SpriteFrame*> spriteFrame;
		for (int i = 1; i <= frameSize[k]; i++) {
			std::stringstream ss;
			ss << prefix[k] << i << ".png";
			auto sprite = Sprite::create(ss.str());
			auto frame = sprite->getSpriteFrame();
			spriteFrame.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(spriteFrame, 0.1);
		AnimationCache::getInstance()->addAnimation(animation, prefix[k]);
	}
	Vector<SpriteFrame*> frames;
}