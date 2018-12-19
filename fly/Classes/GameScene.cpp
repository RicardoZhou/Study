#include "GameScene.h"
#include "Bglayer.h"

Scene* GameScene::createScene() {
	//auto scene = Scene::create();
	auto scene = Scene::createWithPhysics();

	//������������ĵ��Է�Χ���ú�ɫ������ʾ�������ڵ��ԣ�������Ϸʱ��ɾ��
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//���������Ĵ�С�Լ�����
	scene->getPhysicsWorld()->setGravity(Vec2(0, -98));



	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
};

bool GameScene::init() {
	if (!Layer::init()) {
		return false;
	}

	//��ӱ�����
	bgLayer = BgLayer::create();
	addChild(bgLayer);

	return true;
};