#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "BgLayer.h"
#include "Hero.h"

class GameScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	void heroComeIn();
	void heroStartDrop();

	//Åö×²»Øµ÷º¯Êý
	bool onContactBegin(PhysicsContact& contact);
	bool onContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve);
	void onContactSeparate(PhysicsContact& contact);
private:
	BgLayer* bgLayer;
	Hero* hero;
};

#endif // !_GAME_SCENE_H_