//
//  ActionDelayTime.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionDelayTime__
#define __ActionDemo__ActionDelayTime__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionDelayTime:public CCLayer
{
public:
    static CCScene * scene();
    bool init();
    CREATE_FUNC(ActionDelayTime);
    void back();
    void show();
private:
    CCSprite *mySprite;
};
#endif /* defined(__ActionDemo__ActionDelayTime__) */
