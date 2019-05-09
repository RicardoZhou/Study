#ifndef _BIRD_H_
#define _BIRD_H_

#include "cocos2d.h"
USING_NS_CC;

class Bird : public Node {
public:
	CREATE_FUNC(Bird);
	virtual bool init();
private:
	Sprite* _bird;
};

#endif // !_BIRD_H_
