#include "GameScene.h"
#include "Bglayer.h"

Scene* GameScene::createScene() {
	//auto scene = Scene::create();
	auto scene = Scene::createWithPhysics();

	//设置物理世界的调试范围，用红色线条表示，仅用于调试，发布游戏时因删除
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//设置重力的大小以及方向
	scene->getPhysicsWorld()->setGravity(Vec2(0, -98));



	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
};

bool GameScene::init() {
	if (!Layer::init()) {
		return false;
	}

	//添加背景层
	bgLayer = BgLayer::create();
	addChild(bgLayer);

	return true;
};