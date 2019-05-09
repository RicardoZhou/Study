#ifndef _AIRSHIP_H_
#define _AIRSHIP_H_

#include "cocos2d.h"
USING_NS_CC;

class AirShip : public Node {
public:
	CREATE_FUNC(AirShip);
	virtual bool init();
private:
	Sprite* _airship;
};

#endif // !_AIRSHIP_H_
