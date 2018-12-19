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
	return true;
}