#ifndef _HEART_H_
#define _HEART_H_

#include "cocos2d.h"
USING_NS_CC;

class Heart : public Node {
public:
	CREATE_FUNC(Heart);
	virtual bool init();

private:
	Sprite* _heart;
};

#endif // _HEART_H_