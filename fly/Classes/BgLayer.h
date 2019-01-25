#ifndef _BGLAYER_H_
#define _BGLAYER_H_

#include "cocos2d.h"
USING_NS_CC;

class BgLayer : public Layer {
public:
	virtual bool init();
	CREATE_FUNC(BgLayer);
	void createBackgrounds();
	void update(float dt);
	void startScroll();
	void addHearts();
	void addAirShips();
	void addBirds();
private:
	std::vector<Sprite*> farBackground;
	std::vector<Sprite*> nearBackground;
	TMXTiledMap *map;
};

#endif // !_BGLAYER_H_