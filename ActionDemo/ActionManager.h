//
//  ActionManager.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionManager__
#define __ActionDemo__ActionManager__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionManager:CCLayer
{
public:
    static CCScene *scene();
    bool init();
    CREATE_FUNC(ActionManager);
    void onEnter();
    void back();
    void resumeGrossini(float time);
private:
    CCSprite *mySprite;
};
#endif /* defined(__ActionDemo__ActionManager__) */
