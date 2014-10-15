//
//  ActionGridBase.h
//  ActionDemo
//
//  Created by yangxin on 13-8-27.
//
//

#ifndef __ActionDemo__ActionGridBase__
#define __ActionDemo__ActionGridBase__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionGridBase:public CCLayer
{
public:
    static CCScene * scene();
    bool init();
    CREATE_FUNC(ActionGridBase);
    void back();
    void show1();
    void show2();
private:
    CCSprite *mySprite;
};

#endif /* defined(__ActionDemo__ActionGridBase__) */
