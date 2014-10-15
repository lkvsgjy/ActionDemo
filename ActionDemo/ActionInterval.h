//
//  ActionInterval.h
//  ActionDemo
//
//  Created by yangxin on 13-8-26.
//
//

#ifndef __ActionDemo__ActionInterval__
#define __ActionDemo__ActionInterval__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class ActionInterval:CCLayer
{
public:
    bool init();
    static CCScene * scene();
    CREATE_FUNC(ActionInterval);
    void base();
    void orbitCamera();
    void cardinalSpline();
    void actionEase();
    void sequence();
    void delayTime();
    void targetedAction();
    void progressTo();
    void gridBase();
    void back();
};
#endif /* defined(__ActionDemo__ActionInterval__) */
