#include "Hero.h"

bool Hero::init() {
	if (!Node::init())
		return false;

	this->hero = Sprite::create("flying1.png");
	this->hero->setPosition(Vec2::ZERO);
	addChild(this->hero);

	//���һ������
	auto heroBody = PhysicsBody::createBox(
		//��������״
		this->getContentSize(),
		//�������������(�ܶȣ�����ϵ����Ħ����)
		PhysicsMaterial(10, 0.1, 0.1)
	);
	//����������ĸ���������Ϸ�����е������������
	//���ǰ���������������Node���������������Node�е��ӽڵ�Hero����
	this->setPhysicsBody(heroBody);
	return true;
}