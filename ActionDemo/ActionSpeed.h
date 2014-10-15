//
//  ActionSpeed.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionSpeed__
#define __ActionDemo__ActionSpeed__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionSpeed:CCLayer
{
public:
    static CCScene * scene();
    bool init();
    CREATE_FUNC(ActionSpeed);
    void onEnter();
    void back();
    void changedSpeed();
private:
    CCSprite *mySprite;
};
#endif /* defined(__ActionDemo__ActionSpeed__) */
