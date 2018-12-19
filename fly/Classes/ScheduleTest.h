#ifndef _SCHEDULE_TEST_H_
#define _SCHEDULE_TEST_H_

#include "cocos2d.h"
USING_NS_CC;

class ScheduleTest : public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ScheduleTest);

	void update(float dt);
};

#endif // !_SCHEDULE_TEST_H_