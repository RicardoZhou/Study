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

	auto size = Director::getInstance()->getVisibleSize();

	//添加背景层
	bgLayer = BgLayer::create();
	addChild(bgLayer);

	//添加Hero
	hero = Hero::create();
	addChild(hero);
	hero->setPosition(Vec2(-30, size.height * 2 / 3));

	heroComeIn();

	//碰撞事件以及回调函数
	//1.创建一个物理引擎的碰撞事件监听器
	auto contactListener = EventListenerPhysicsContact::create();
	//2.配置相关的回调函数(事件处理函数)
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(GameScene::onContactPreSolve, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(GameScene::onContactSeparate, this);
	//3.添加物理引擎的碰撞事件监听器
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
};

void GameScene::heroComeIn() {
	//启动飞行模式
	hero->fly();

	auto size = Director::getInstance()->getVisibleSize();
	auto moveAct = MoveTo::create(4, Vec2(size.width / 2, size.height * 2 / 3));

	//创建一个函数动作
	auto callFunc = CallFunc::create(CC_CALLBACK_0(GameScene::heroStartDrop, this));

	//创建一个顺序执行的动作
	auto sequence = Sequence::create(moveAct, callFunc, NULL);

	hero->runAction(sequence);
}

void GameScene::heroStartDrop() {
	//让屏幕滚动
	bgLayer->startScroll();

	//让Hero的重力有效
	hero->getPhysicsBody()->setGravityEnable(true);

	//启动drop动画
	hero->drop();
}

bool GameScene::onContactBegin(PhysicsContact& contact) {
	log("onContactBegin");
	return true;
}

bool GameScene::onContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve) {
	log("onContactPreSolve");
	return true;
}

void GameScene::onContactSeparate(PhysicsContact& contact) {
	log("onContactSeparate");
}