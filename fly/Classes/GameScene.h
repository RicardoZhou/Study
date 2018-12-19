#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

#include "BgLayer.h"

class GameScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
private:
	BgLayer* bgLayer;
};

#endif // !_GAME_SCENE_H_