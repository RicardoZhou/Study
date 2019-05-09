#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"
USING_NS_CC;

class Hero : public Node {
public:
	CREATE_FUNC(Hero);
	virtual bool init();

	void initAnimationCach();

	void fly();
	void drop();
	void die();
private:
	Sprite *hero;
};

#endif // !_HERO_H_