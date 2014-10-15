//
//  ActionBase.h
//  ActionDemo
//
//  Created by yangxin on 13-8-26.
//
//

#ifndef __ActionDemo__ActionBase__
#define __ActionDemo__ActionBase__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionBase:CCLayer
{
public:
    bool init();
    static CCScene * scene();
    CREATE_FUNC(ActionBase);
public:
    void actionMove();
    void actionRotate();
    void actionScale();
    void actionJump();
    void actionBlink();
    void actionSkew();
    void actionTint();
    void actionBezier();
    void recover();
    void back();
private:
    CCSprite *mySprite;
};
#endif /* defined(__ActionDemo__ActionBase__) */
