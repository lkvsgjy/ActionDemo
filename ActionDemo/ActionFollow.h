//
//  ActionFollow.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionFollow__
#define __ActionDemo__ActionFollow__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionFollow:CCLayer
{
public:
    static CCScene * scene();
    bool init();
    CREATE_FUNC(ActionFollow);
    void show();
    void back();
private:
    CCSprite *mySprite1;
    CCSprite *mySprite2;
};
#endif /* defined(__ActionDemo__ActionFollow__) */
